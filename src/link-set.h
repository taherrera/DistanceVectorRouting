#ifndef NEIGHBOR_H
#define NEIGHBOR_H
#include "../platform/platform.h"
#include "constants.h"

typedef struct
{
        unsigned short mAverage;
        unsigned char mQuality;
	unsigned char mLinkCost;

} Link;


/*
*
*  unsigned char = 1 byte, unsigned short = 2 byte.
*
*/

typedef struct
{
	unsigned char mRouterID;
	unsigned short mLastLinkMargin;
	Link mIncomingLink;
	Link mOutgoingLink;
	unsigned char mage;

} Neighbor;

typedef struct
{

	Neighbor mNeighborList[MAXROUTERS];

} LinkSet;

/*
*
*  sets mIncomingLink.mAverage
*
*/


void FirstOrderFilter(Neighbor *aNeighbor, unsigned short aNewLinkMargin);

/*
*
*  sets mIncomingLink.mQuality
*
*/


void SetQuality(Neighbor * aNeighbor);

/*
*
*  Sets mOutgoingLink.mLinkCost
*
*/

void setCost(Neighbor * aNeighbor);

/*
*
* Transforms a quality to a cost
*
*/

unsigned char QualityToCost(unsigned char aQuality);


#endif
