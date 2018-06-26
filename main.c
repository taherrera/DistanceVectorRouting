
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
initRouterList(ROUTERLIST[N], ROUTERLIST, mRouterList);


// listen to channel CHANNEL
//radiolisten(CHANNEL);	



return -1; // Always return error
}
