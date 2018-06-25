//#ifndef NEIGHBOR_H
//#define NEIGHBOR_H
#include "../platform/platform.h"
#include "constants.h"

typedef struct
{
        uint16_t mAverage;
        uint8_t mQuality;

} Link;



typedef struct
{
	uint8_t mRouterID;
	uint16_t mLastLinkMargin;
	Link mIncomingLink;
	Link mOutgoingLink;
	uint8_t mage;

} Neighbor;


void FirstOrderFilter(Neighbor *aNeighbor, uint16_t aNewLinkMargin);

void SetQuality(Neighbor * aNeighbor);

//#endif
