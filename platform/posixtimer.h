#ifndef POSIXTIMER_H
#define POSIXTIMER_H

#include "../platform/platform.h"
#include "../src/ot-info.h"


int broadcastinit(int expireS, OpenThread* aot);

void timerHandler( int sig, siginfo_t *si, void *uc );


#endif 
