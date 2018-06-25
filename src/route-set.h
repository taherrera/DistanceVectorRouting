#ifndef ROUTE_SET_H
#define ROUTE_SET_H

#include "../platform/platform.h"
#include "constants.h"

typedef struct
{
	uint8_t mRouterID;
	uint8_t mNextHop;
	uint16_t mRouteCost;

} Router;




#endif
