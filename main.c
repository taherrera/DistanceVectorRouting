
#include "platform/platform.h"
#include "src/link-set.h"
#include "src/route-set.h"
#include "src/init.h"

#ifdef POSIX
#include "platform/posix.h"
#endif
 
#define CHANNEL 26
#define N 0

int main()
{

// Init the router set

RouterList mRouterList;
const uint16_t ROUTERLIST[] = {ROUTERID_1, ROUTERID_2, ROUTERID_3, ROUTERID_4, ROUTERID_5, ROUTERID_6};
initRouterList(ROUTERLIST[N], ROUTERLIST , &mRouterList);


// listen to channel CHANNEL
//radiolisten(CHANNEL);	



return -1; // Always return error
}
