#include "route-set.h"
#include "../platform/platform.h"
#include "../src/constants.h"
#include "../src/mleroute64tlv.h"


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
			unsigned char route = aRouterSet->mRouterSet[i].mRouteCost;
			linkqualroutedata[i] = (out << 6) + (in << 4) + route;
			//printf("not me out: %u, ",out);
			//printf("not me in: %u, ",in);
			//printf("not me route: %u, ",route);	
		}
	} 
	//for (i=0;i<MAXROUTERS;i++)
	//printf("\n%u \n",linkqualroutedata[i]);

	// [MAXROUTERS+1+1+1+4]
	memcpy(&tlv[4+1+1+1]	,&linkqualroutedata,	MAXROUTERS);
	memcpy(&tlv[1+1+1]	,&IDmask,		4);
	memcpy(&tlv[1+1]	,&IDseq,		1);
	memcpy(&tlv[1]		,&length,		1);
	memcpy(&tlv[0]		,&type,			1);
	/*
	memcpy(tlv, (	(type   << ((MAXROUTERS+1+1+4)*8))+ 
			(length << ((MAXROUTERS+1+4  )*8))+ 
			(IDseq  << ((MAXROUTERS+4    )*8))+ 
			(IDmask << ((MAXROUTERS      )*8))+ 
			linkqualroutedata		   			),
		MAXROUTERS+1+1+1+4);
	*/

};


