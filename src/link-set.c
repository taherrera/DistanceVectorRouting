#include "../platform/platform.h"
#include "link-set.h"
#include "constants.h"
void FirstOrderFilter(Neighbor * aNeighbor, uint16_t aNewLinkMargin)
{
	
	aNeighbor->mIncomingLink.mAverage =\
					(1-A)*aNeighbor->mIncomingLink.mAverage +\
					aNewLinkMargin*A;

	// to do: set variable mage to Neighbor
}



void SetQuality(Neighbor * aNeighbor)
{
	uint16_t linkdb = aNeighbor->mIncomingLink.mAverage;
	if       (linkdb > DB_20){
		aNeighbor->mIncomingLink.mQuality = QUALITY_DB20;
	}else if (linkdb > DB_10){
		aNeighbor->mIncomingLink.mQuality = QUALITY_DB10;
	}else if (linkdb >DB_2)  {
		aNeighbor->mIncomingLink.mQuality =  QUALITY_DB2;
	}else{
		aNeighbor->mIncomingLink.mQuality = QUALITY_DB2M;
	}


}
