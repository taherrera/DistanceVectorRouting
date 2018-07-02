#ifndef NEIGHBOR_H
#define NEIGHBOR_H
#include "../platform/platform.h"
#include "constants.h"

typedef struct
{
        unsigned short mAverage;
        unsigned char mQuality;

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


void FirstOrderFilter(Neighbor *aNeighbor, uint16_t aNewLinkMargin);

void SetQuality(Neighbor * aNeighbor);

#endif
