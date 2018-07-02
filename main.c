
#include "platform/platform.h"
#include "src/link-set.h"
#include "src/route-set.h"
#include "src/init.h"
#include "src/constants.h"

#ifdef POSIX
#include "platform/posix.h"
#include "platform/posixtimer.h" 
#endif


int main()
{

// Init the router set
RouterSet mRouterSet;
LinkSet mLinkSet;
const uint16_t ROUTERSET[] = {	ROUTERID_0,
				ROUTERID_1,
				ROUTERID_2,
				ROUTERID_3,
				ROUTERID_4,
				ROUTERID_5};

initRouterSet(ROUTERSET[MYROUTER], ROUTERSET, &mRouterSet);
initLinkSet(  ROUTERSET[MYROUTER], ROUTERSET, &mLinkSet  );



/* SOME TESTS */
//printrouterset(&mRouterSet);  #include "test/test-init.c"
//printlinkset(&mLinkSet); #include "test/test-init.c"
//test_filter()  #include "test/test-filter.c"

// Broadcast every PERIOD miliseconds
//broadcastinit(PERIOD, &mRouterSet);

// listen to channel CHANNEL
//radiolisten(CHANNEL);	


//while(1);;

return -1; // Always return error
}
