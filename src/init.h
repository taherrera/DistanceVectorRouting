#ifndef INIT_H
#define INIT_h

#include "../platform/platform.h"
#include "../src/route-set.h"


void initRouterList(uint16_t myRouterID, const uint16_t RouterIDs[MAXROUTERS],RouterList *aRouterList);


#endif
