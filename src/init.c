
#include "../platform/platform.h"
#include "../src/route-set.h"




void initRouter(uint16_t myRouterID, uint16_t RouterIDs[], RouterList *aRouterList)
{

	int i:
	for(i=0;i<N;i++)
	{
		if (RouterIDs[i] == myRouterID) // its me !
		{
			aRouterList->RouterIDs[i].mRouterID = myRouterID;
			aRouterList->RouterIDs[i].mNextHop = myRouterID;
			aRouterList->RouterIDs[i].mRouteCost = 0;
			
		}else{
			aRouterList->RouterIDs[i].mRouterID = RouterIDs[i];
			aRouterList->RouterIDs[i].mNextHop = '\0';
			aRouterList->RouterIDs[i].mRouteCost = '\0';
		}
		
	}

}


