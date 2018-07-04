#ifndef ROUTE_SET_H
#define ROUTE_SET_H

#include "../platform/platform.h"
#include "constants.h"

/*
*
*  Defines what a router is
*
*/

typedef struct
{
	unsigned char mRouterID;
	unsigned char mNextHop;
	unsigned char mRouteCost;

} Router;


/*
*
*   Just a list of Routers (the router set)
*
*/


typedef struct
{
	Router mRouterSet[MAXROUTERS];

} RouterSet;


#endif
