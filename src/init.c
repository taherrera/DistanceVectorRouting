
#include "../platform/platform.h"
#include "../src/route-set.h"
#include "../src/link-set.h"
#include "../src/constants.h"



void initRouterSet(const unsigned short RouterIDs[MAXROUTERS], RouterSet *aRouterSet)
{

	int i;
	for(i=0;i<MAXROUTERS;i++)
	{
		if (RouterIDs[i] == MYROUTERID) // its me !
		{
			aRouterSet->mRouterSet[i].mRouterID = MYROUTERID;
			aRouterSet->mRouterSet[i].mNextHop = MYROUTERID;
			aRouterSet->mRouterSet[i].mRouteCost = 0;
	
			
		}else{
			aRouterSet->mRouterSet[i].mRouterID = RouterIDs[i];
			aRouterSet->mRouterSet[i].mNextHop = 0;
			aRouterSet->mRouterSet[i].mRouteCost = 0;
		}
		
	}

}

void initLinkSet( const unsigned short RouterIDs[MAXROUTERS], LinkSet *aLinkSet)
{

	int i;
	for(i=0;i<MAXROUTERS;i++)
	{
		if (RouterIDs[i] == MYROUTERID) // its ME !
		{
			aLinkSet->mNeighborList[i].mRouterID = MYROUTERID;
			aLinkSet->mNeighborList[i].mLastLinkMargin = DB_INF;
			aLinkSet->mNeighborList[i].mage = 0x01;
			aLinkSet->mNeighborList[i].mIncomingLink.mAverage = DB_INF; // infinite decibels
			aLinkSet->mNeighborList[i].mIncomingLink.mQuality = QUALITY_DB20;
			aLinkSet->mNeighborList[i].mOutgoingLink.mAverage = DB_INF;	
			aLinkSet->mNeighborList[i].mOutgoingLink.mQuality = QUALITY_DB20; // best quality
			aLinkSet->mNeighborList[i].mOutgoingLink.mLinkCost= LINKCOST_DB20; // best COST
			
		}else{
			aLinkSet->mNeighborList[i].mRouterID = RouterIDs[i];
			aLinkSet->mNeighborList[i].mLastLinkMargin = 0;
			aLinkSet->mNeighborList[i].mage = 0; // must be greater than 0 to be a neighbor
			aLinkSet->mNeighborList[i].mIncomingLink.mAverage = DB_MINF;
			aLinkSet->mNeighborList[i].mOutgoingLink.mAverage = DB_MINF;
			aLinkSet->mNeighborList[i].mIncomingLink.mQuality = QUALITY_DB2M;
			aLinkSet->mNeighborList[i].mOutgoingLink.mQuality = QUALITY_DB2M;
			aLinkSet->mNeighborList[i].mOutgoingLink.mLinkCost= LINKCOST_DB2M; // worst COST
		}

	}


}


