
#ifdef POSIX

#include "platform/posixradio.h"
#include "platform/posixtimer.h"

#endif

#include "platform/platform.h"
#include "src/link-set.h"
#include "src/route-set.h"
#include "src/ot-info.h"
#include "src/constants.h"
#include "src/init.h"

#include "src/mleroute64tlv.h"




							




int main()
{

// Init the sets
RouterSet mRouterSet;
LinkSet mLinkSet;
OpenThread ot;
ot.mLinkSet = &mLinkSet;
ot.mRouterSet = &mRouterSet;
const uint16_t ROUTERSET[] = {	ROUTERID_0,
				ROUTERID_1,
				ROUTERID_2,
				ROUTERID_3,
				ROUTERID_4,
				ROUTERID_5};


initRouterSet(ROUTERSET, &mRouterSet);
initLinkSet(ROUTERSET, &mLinkSet  );



/* Start a broadcast timer */
broadcastinit(PERIOD, &ot);

/* Listen to channel (forever) */
radiolisten(CHANNEL, &ot);	


while(1);;

return -1; // Always return error
}
