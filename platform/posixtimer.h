#ifndef POSIXTIMER_H
#define POSIXTIMER_H

#include "../platform/platform.h"
#include "../src/route-set.h"


int broadcastinit(int expireS, RouterSet* aRouterSet);

void timerHandler( int sig, siginfo_t *si, void *uc );


#endif 
