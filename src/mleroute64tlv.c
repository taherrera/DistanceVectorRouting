#include "route-set.h"
#include "../platform/platform.h"
#include "../src/constants.h"
#include "../src/mleroute64tlv.h"


void createroutertlv(RouterSet* aRouterSet, LinkSet* aLinkSet, unsigned char* tlv)
{

	static unsigned char type = 9;
	static unsigned char length = MAXROUTERS+1+4;
	static unsigned char IDseq = 0;
	static unsigned char IDmask[] = {0xf8,0x00,0x00,0x00};
	unsigned char linkqualroutedata[MAXROUTERS];
	int i;

	for (i=0;i<MAXROUTERS;i++)
	{
		if (aRouterSet->mRouterSet[i].mRouterID == MYROUTER) // if router == me
		{
			linkqualroutedata[i] = 0x01;
		}else{
			unsigned char out = aLinkSet->mNeighborList[i].mOutgoingLink.mQuality;
			unsigned char in = aLinkSet->mNeighborList[i].mIncomingLink.mQuality;
			unsigned char route = aRouterSet->mRouterSet[i].mRouteCost;
			linkqualroutedata[i] = (out << 6) + (in << 4) + route;	
		}
	} 


	// [MAXROUTERS+1+1+1+4]
	memcpy(&tlv			,&linkqualroutedata,	MAXROUTERS*8);
	memcpy(&tlv[MAXROUTERS]		,&IDmask,		(4)*8);
	memcpy(&tlv[MAXROUTERS+4]	,&IDseq,		(1)*8);
	memcpy(&tlv[MAXROUTERS+4+1]	,&length,		(1)*8);
	memcpy(&tlv[MAXROUTERS+4+1+1]	,&type,			(1)*8);
	/*
	memcpy(tlv, (	(type   << ((MAXROUTERS+1+1+4)*8))+ 
			(length << ((MAXROUTERS+1+4  )*8))+ 
			(IDseq  << ((MAXROUTERS+4    )*8))+ 
			(IDmask << ((MAXROUTERS      )*8))+ 
			linkqualroutedata		   			),
		MAXROUTERS+1+1+1+4);
	*/

};


