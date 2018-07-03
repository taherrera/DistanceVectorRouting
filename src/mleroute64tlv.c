#include "route-set.h"
#include "../platform/platform.h"
#include "../src/constants.h"
#include "../src/mleroute64tlv.h"
#include "../gui/printtables.h"

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })


void minimizeroute(RouterSet* aRouterSet, LinkSet* aLinkSet, unsigned int incomingrouter,unsigned int destrouter,unsigned char routecost)
{
	unsigned char actualroutecost = aRouterSet->mRouterSet[destrouter].mRouteCost;   // min cost reported by neighbors
	unsigned char actualnexthoprouter = aRouterSet->mRouterSet[destrouter].mNextHop; // next hop router (present)
	unsigned char actualnexthoprouterage = aLinkSet->mNeighborList[actualnexthoprouter].mage;

	unsigned char actuallinkcostincoming = aLinkSet->mNeighborList[actualnexthoprouter].mIncomingLink.mLinkCost;
	unsigned char actuallinkcostoutgoing = aLinkSet->mNeighborList[actualnexthoprouter].mOutgoingLink.mLinkCost;
	
	// the link cost to the present next hop
	unsigned char actuallinkcost = max(actuallinkcostincoming, actuallinkcostoutgoing);


	// the link cost to "incomingrouter"
	unsigned int potentiallinkcostincoming = aLinkSet->mNeighborList[incomingrouter].mIncomingLink.mLinkCost;
	unsigned int potentiallinkcostoutgoing = aLinkSet->mNeighborList[incomingrouter].mOutgoingLink.mLinkCost;
	unsigned int potentiallinkcost = max(potentiallinkcostincoming,potentiallinkcostoutgoing);

	if ( (destrouter != MYROUTERID)&&(incomingrouter!=MYROUTERID) ){
		if ((potentiallinkcostincoming == LINKCOST_DB2M) || (potentiallinkcostoutgoing == LINKCOST_DB2M)) 
		{// then "incomingrouter" is not a valid neighbor and cant send to it
			aLinkSet->mNeighborList[incomingrouter].mage = 0;
		
		}else if((actuallinkcostincoming == LINKCOST_DB2M) || (actuallinkcostoutgoing == LINKCOST_DB2M))
		{// I cant get to "destouter" through "actualnexthop", but I can get trough "incomingrouter" 
			
			aRouterSet->mRouterSet[destrouter].mNextHop = incomingrouter;
			if (destrouter == incomingrouter){
			// the routing cost is the cost reported by incoming router + the link cost
				aRouterSet->mRouterSet[destrouter].mRouteCost = potentiallinkcost;
			}else{
				aRouterSet->mRouterSet[destrouter].mRouteCost = routecost + potentiallinkcost;
			}
			aLinkSet->mNeighborList[incomingrouter].mage = 1;
		}else if( (actualroutecost==0)&&(incomingrouter==destrouter) )
		{ // best path is trough incoming router
			
			aRouterSet->mRouterSet[destrouter].mRouteCost = potentiallinkcost;
			aRouterSet->mRouterSet[destrouter].mNextHop = incomingrouter;
			aLinkSet->mNeighborList[incomingrouter].mage = 1;
		}else if (actualroutecost==0)  
		// If path does not exist, use this one
		{	
			aRouterSet->mRouterSet[destrouter].mRouteCost = routecost + potentiallinkcost;
			aRouterSet->mRouterSet[destrouter].mNextHop = incomingrouter;
			aLinkSet->mNeighborList[incomingrouter].mage = 1;
		}else if ((actualroutecost - actuallinkcost > routecost-potentiallinkcost)&& (incomingrouter!=destrouter)){
			
			aRouterSet->mRouterSet[destrouter].mRouteCost = potentiallinkcost;
			aRouterSet->mRouterSet[destrouter].mRouteCost = routecost + potentiallinkcost;
			aRouterSet->mRouterSet[destrouter].mNextHop = incomingrouter;
			aLinkSet->mNeighborList[incomingrouter].mage = 1;
		}else if ((actualroutecost > potentiallinkcost) && (incomingrouter==destrouter)){
			
			aRouterSet->mRouterSet[destrouter].mRouteCost = potentiallinkcost;
			aRouterSet->mRouterSet[destrouter].mNextHop = incomingrouter;
			aLinkSet->mNeighborList[incomingrouter].mage = 1;
		}
		
	}
}


void createroutertlv(RouterSet* aRouterSet, LinkSet* aLinkSet, unsigned char* tlv)
{

	static unsigned char type = 9;
	static unsigned char length = MAXROUTERS+1+4;
	static unsigned char IDseq = 0;
	static unsigned char IDmask[4] = {0xfc,0x00,0x00,0x00};
	unsigned char linkqualroutedata[MAXROUTERS];
	int i;

	for (i=0;i<MAXROUTERS;i++)
	{
		if (aRouterSet->mRouterSet[i].mRouterID == MYROUTERID) // if router == me
		{
			linkqualroutedata[i] = 0x01;
			//printf("its me: %u \n",linkqualroutedata[i]);
		}else{
			unsigned char out = aLinkSet->mNeighborList[i].mOutgoingLink.mQuality;
			unsigned char in = aLinkSet->mNeighborList[i].mIncomingLink.mQuality;
			unsigned char linkquality = min(in,out);
			unsigned char linkcost;
			if (linkquality == QUALITY_DB2M) // router unreachable directly
			{
				linkcost = LINKCOST_DB2M;
			}else{				 // router reachable directly
				linkcost = QualityToCost(linkquality);
			}		

			// the reported route cost is the route cost of others plus my link cost
			unsigned char routecost = aRouterSet->mRouterSet[i].mRouteCost;

			
			linkqualroutedata[i] = (out << 6) + (in << 4) + routecost;
		}
	} 

	memcpy(&tlv[4+1+1+1]	,&linkqualroutedata,	MAXROUTERS);
	memcpy(&tlv[1+1+1]	,&IDmask,		4);
	memcpy(&tlv[1+1]	,&IDseq,		1);
	memcpy(&tlv[1]		,&length,		1);
	memcpy(&tlv[0]		,&type,			1);


};


void readroutertlvandchangerouting(RouterSet *aRouterSet, LinkSet *aLinkSet, char * message, unsigned char RSSI)
{
	
	
	unsigned char type, length;
	type = message[0];
	length = message[1];
	
	if (type == 9)  // route 64 tlv
	{ 

		unsigned int numrouters = length - 1 - 4;
		int i;
		unsigned char routerinfo[MAXROUTERS] = {0x00};

		// Save all Routing info in routerinfo[]
		for (i=0;i<numrouters;i++)
		{
			routerinfo[i] = message[7+i]; 
		}
		unsigned int incomingrouter;
		
		// Process the sender first
		for (i=0;i<numrouters;i++)
		{
			
			if (routerinfo[i] == 0x01) // this is the sender (neighbor i)
			{
				incomingrouter = i;
				// set all incoming variables in link set
				//aLinkSet->mNeighborList[i].mage = 1;
				#ifdef POSIX
				unsigned char RSSITABLE[6][6] = {	{40,25,0 , 0, 0, 0},   // 6 rows , 6 columns
									{25,40,30, 0, 0, 0},
									{0 ,30,40,60, 0, 0},
									{0 ,0 ,60,40,80, 0},
									{0 ,0 ,0 ,80,40,90},
									{0 ,0 ,0, 0, 90,40}};
				aLinkSet->mNeighborList[i].mLastLinkMargin = RSSITABLE[i][MYROUTERID];
				FirstOrderFilter(&(aLinkSet->mNeighborList[i]),RSSITABLE[i][MYROUTERID]);
				#endif
				SetQuality(&(aLinkSet->mNeighborList[i]));
				setCost(&(aLinkSet->mNeighborList[i]));
				minimizeroute(aRouterSet, aLinkSet,incomingrouter,i,0);
				
			}
		}
		// process routing information reported by "incomingrouter"
		unsigned char outgoingquality; // outgoing quality of router "incomingrouter"
		unsigned char incomingquality;
		for (i=0;i<numrouters;i++)
		{
			if ((i == MYROUTERID) && (routerinfo[i] != 0x01)) // its info on me and not looping back
			{	
				outgoingquality = (0b00110000 & routerinfo[i]) >> 4; // in for him is out for me
				aLinkSet->mNeighborList[incomingrouter].mOutgoingLink.mQuality = outgoingquality; 
				SetQuality(&(aLinkSet->mNeighborList[incomingrouter]));
				
				
			}else if (routerinfo[i] != 0x01) // info on other routers
			{
				
				outgoingquality = (0b00110000 & routerinfo[i]) >> 4;
				incomingquality = (0b11000000 & routerinfo[i]) >> 6;
				unsigned char quality = min(outgoingquality,incomingquality);
				unsigned char costdirect = QualityToCost(quality);
				
				unsigned char routecost; // the cost of "incomingrouter" to router "i" is
							 // the min cost reported by the other routers to him
							 // plus the link cost he has to the next hop

				// this is the routing cost of "incomingrouter" to router "i"
				routecost = (routerinfo[i]&0b00001111);

				
				if ((routecost != 0x00)||(incomingrouter == i)){// then "i" is reachable by "incomingrouter" or "incomingrouter" is "i"
					
					// find out if min to router "i" is trough "incomingrouter"
					minimizeroute(aRouterSet, aLinkSet,incomingrouter,i,routecost);
				}
			}
		}
	
		
	}
	
	printrouterset(aRouterSet);
	printlinkset(aLinkSet);
}

