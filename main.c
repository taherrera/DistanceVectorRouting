
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

// Init the router set
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



/* SOME TESTS */
//printrouterset(&mRouterSet); 
//printlinkset(&mLinkSet);
//test_filter()  #include "test/test-filter.c"

//unsigned char tlv[MAXROUTERS+4+1+1+1] = {0};


//createroutertlv(ot.mRouterSet, ot.mLinkSet, tlv);

//int i;
//for (i=0;i<MAXROUTERS+4+1+1+1;i++){
//printf("%u\n",tlv[i]);}

// Broadcast every PERIOD miliseconds
//const char h[2] = {mRouterSet.mRouterSet[2].mRouterID+'0','\0'};
//write(1,h,2);

broadcastinit(PERIOD, &ot);

// listen to channel CHANNEL
radiolisten(CHANNEL, &ot);	


while(1);;

return -1; // Always return error
}
