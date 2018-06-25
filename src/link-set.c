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
	if (linkdb > db20){
		aNeighbor->mIncomingLink.mQuality = qualitydb20;
	}else if (linkdb > db10){
		aNeighbor->mIncomingLink.mQuality = qualitydb10;
	}else if (linkdb >db2){
		aNeighbor->mIncomingLink.mQuality =  qualitydb2;
	}else{
		aNeighbor->mIncomingLink.mQuality = qualitydb2m;
	}


}
