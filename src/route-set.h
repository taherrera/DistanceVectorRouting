#ifndef ROUTE_SET_H
#define ROUTE_SET_H

#include "../platform/platform.h"
#include "constants.h"

typedef struct
{
	uint16_t mRouterID;
	uint16_t mNextHop;
	uint16_t mRouteCost;

} Router;


typedef struct
{
	Router mRouterList[MAXROUTERS];

} RouterList;


#endif
