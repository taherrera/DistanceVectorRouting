
#include "../platform/platform.h"
#include "../src/route-set.h"
#include "../src/link-set.h"
#include "../src/constants.h"



void initRouterSet(unsigned short myRouterID, const unsigned short RouterIDs[MAXROUTERS], RouterSet *aRouterSet)
{

	int i;
	for(i=0;i<MAXROUTERS;i++)
	{
		if (RouterIDs[i] == myRouterID) // its me !
		{
			aRouterSet->mRouterSet[i].mRouterID = myRouterID;
			aRouterSet->mRouterSet[i].mNextHop = myRouterID;
			aRouterSet->mRouterSet[i].mRouteCost = 1;
			
		}else{
			aRouterSet->mRouterSet[i].mRouterID = RouterIDs[i];
			aRouterSet->mRouterSet[i].mNextHop = 0;
			aRouterSet->mRouterSet[i].mRouteCost = 0;
		}
		
	}

}

void initLinkSet(unsigned short myRouterID, const unsigned short RouterIDs[MAXROUTERS], LinkSet *aLinkSet)
{

	int i;
	for(i=0;i<MAXROUTERS;i++)
	{
		if (RouterIDs[i] == myRouterID) // its ME !
		{
			aLinkSet->mNeighborList[i].mRouterID = myRouterID;
			aLinkSet->mNeighborList[i].mLastLinkMargin = DB_INF;
			aLinkSet->mNeighborList[i].mage = 1;
			aLinkSet->mNeighborList[i].mIncomingLink.mAverage = DB_INF; // infinite decibels
			aLinkSet->mNeighborList[i].mOutgoingLink.mQuality = QUALITY_DB20; // best quality
		}else{
			aLinkSet->mNeighborList[i].mRouterID = RouterIDs[i];
			aLinkSet->mNeighborList[i].mLastLinkMargin = 0;
			aLinkSet->mNeighborList[i].mage = 0; // must be greater than 0 to be a neighbor
			aLinkSet->mNeighborList[i].mIncomingLink.mAverage = DB_MINF;
			aLinkSet->mNeighborList[i].mOutgoingLink.mQuality=QUALITY_DB2M;
		}

	}


}


