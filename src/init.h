#ifndef INIT_H
#define INIT_h

#include "../platform/platform.h"
#include "../src/route-set.h"

/* Initializes the Router set with initial values */

void initRouterSet(uint16_t myRouterID, const uint16_t RouterIDs[MAXROUTERS],RouterSet *aRouterSet);



/* Initializes the Link set with initial values */

void initLinkSet(unsigned short myRouterID, const unsigned short RouterIDs[MAXROUTERS], LinkSet *aLinkset);

#endif
