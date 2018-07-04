#include "../platform/platform.h"
#include "link-set.h"
#include "constants.h"
void FirstOrderFilter(Neighbor * aNeighbor, uint16_t aNewLinkMargin)
{
	
	aNeighbor->mIncomingLink.mAverage =\
					(1-A)*aNeighbor->mIncomingLink.mAverage +\
					aNewLinkMargin*A;
}


void SetQuality(Neighbor * aNeighbor)
{	
	unsigned short linkdb = aNeighbor->mIncomingLink.mAverage;
	if       (linkdb > DB_20){
		aNeighbor->mIncomingLink.mQuality = QUALITY_DB20;
		aNeighbor->mIncomingLink.mLinkCost = LINKCOST_DB20;
	}else if (linkdb > DB_10){
		aNeighbor->mIncomingLink.mQuality = QUALITY_DB10;
		aNeighbor->mIncomingLink.mLinkCost = LINKCOST_DB10;
	}else if (linkdb >DB_2)  {
		aNeighbor->mIncomingLink.mQuality =  QUALITY_DB2;
		aNeighbor->mIncomingLink.mLinkCost = LINKCOST_DB2;
	}else{
		aNeighbor->mIncomingLink.mQuality = QUALITY_DB2M;
		aNeighbor->mIncomingLink.mLinkCost = LINKCOST_DB2M;
	}
	unsigned short linkqual = aNeighbor->mOutgoingLink.mQuality;
	if(linkqual == QUALITY_DB20){
		aNeighbor->mOutgoingLink.mLinkCost = LINKCOST_DB20;
	}else if (linkqual == QUALITY_DB10){
		aNeighbor->mOutgoingLink.mLinkCost = LINKCOST_DB10;
	}else if (linkqual == QUALITY_DB2)  {
		aNeighbor->mOutgoingLink.mLinkCost = LINKCOST_DB2;
	}else{
		aNeighbor->mOutgoingLink.mLinkCost = LINKCOST_DB2M;
	}

}


void setCost(Neighbor * aNeighbor)
{

	unsigned char linkquality =  aNeighbor->mOutgoingLink.mQuality;

	if(linkquality == QUALITY_DB20){
		aNeighbor->mOutgoingLink.mLinkCost = LINKCOST_DB20;
	}else if(linkquality == QUALITY_DB10){
		aNeighbor->mOutgoingLink.mLinkCost = LINKCOST_DB10;
	}else if(linkquality == QUALITY_DB2){
		aNeighbor->mOutgoingLink.mLinkCost = LINKCOST_DB2;
	}else{
		aNeighbor->mOutgoingLink.mLinkCost = LINKCOST_DB2M;
	}

}

unsigned char QualityToCost(unsigned char aQuality)
{

	if(aQuality == QUALITY_DB20){
		return LINKCOST_DB20;
	}else if (aQuality == QUALITY_DB10){
		return LINKCOST_DB10;
	}else if(aQuality == QUALITY_DB2){
		return LINKCOST_DB2;
	}else{
		return LINKCOST_DB2M;
	}

}


void ageTimeOut(RouterSet *aRouterSet,LinkSet *aLinkSet)
{

	unsigned int routerid;
	unsigned char aage;
	for (routerid=0;routerid<MAXROUTERS;routerid++)
	{
		aage = aLinkSet->mNeighborList[routerid].mage;
		if (aage > 0)
		{
			aLinkSet->mNeighborList[routerid].mage += 1;
		}

		if (aage >= AGETIMEOUT) // timedout link
		{	// reset to original values
			aLinkSet->mNeighborList[routerid].mLastLinkMargin = 0;
			aLinkSet->mNeighborList[routerid].mage = 0;
			aLinkSet->mNeighborList[routerid].mIncomingLink.mAverage = DB_MINF;
			aLinkSet->mNeighborList[routerid].mOutgoingLink.mAverage = DB_MINF;
			aLinkSet->mNeighborList[routerid].mIncomingLink.mQuality = QUALITY_DB2M;
			aLinkSet->mNeighborList[routerid].mOutgoingLink.mQuality = QUALITY_DB2M;
			aLinkSet->mNeighborList[routerid].mOutgoingLink.mLinkCost= LINKCOST_DB2M;

			// remove this router from any nexthop router entry
			int i;
			for(i=0;i<MAXROUTERS;i++)
			{
				if (aRouterSet->mRouterSet[i].mNextHop == routerid)
				{
					aRouterSet->mRouterSet[i].mNextHop = 0;
					aRouterSet->mRouterSet[i].mRouteCost = 0;
				}
			}
		}
	}
}
