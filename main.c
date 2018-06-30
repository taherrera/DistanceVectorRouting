
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
RouterList mRouterList;
const uint16_t ROUTERLIST[] = {	ROUTERID_1,\
				ROUTERID_2,\
				ROUTERID_3,\
				ROUTERID_4,\
				ROUTERID_5,\
				ROUTERID_6};

initRouterList(ROUTERLIST[ROUTER], ROUTERLIST , &mRouterList);


// Broadcast every PERIOD miliseconds
broadcastinit(PERIOD, &mRouterList);

// listen to channel CHANNEL
//radiolisten(CHANNEL);	


while(1);;

return -1; // Always return error
}
