#ifndef INIT_H
#define INIT_h

#include "../platform/platform.h"
#include "../src/route-set.h"
#include "../src/link-set.h"
#include "../src/constants.h"

/* Initializes the Router set with initial values */

void initRouterSet(const uint16_t RouterIDs[MAXROUTERS],RouterSet *aRouterSet);



/* Initializes the Link set with initial values */

void initLinkSet(const unsigned short RouterIDs[MAXROUTERS], LinkSet *aLinkset);

#endif
