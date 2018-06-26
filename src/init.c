
#include "../platform/platform.h"
#include "../src/route-set.h"
#include "../src/constants.h"



void initRouterList(uint16_t myRouterID, const uint16_t RouterIDs[MAXROUTERS], RouterList *aRouterList)
{

	int i;
	for(i=0;i<MAXROUTERS;i++)
	{
		if (RouterIDs[i] == myRouterID) // its me !
		{
			aRouterList->mRouterList[i].mRouterID = myRouterID;
			aRouterList->mRouterList[i].mNextHop = myRouterID;
			aRouterList->mRouterList[i].mRouteCost = 0;
			
		}else{
			aRouterList->mRouterList[i].mRouterID = RouterIDs[i];
			aRouterList->mRouterList[i].mNextHop = '\0';
			aRouterList->mRouterList[i].mRouteCost = '\0';
		}
		
	}

}


