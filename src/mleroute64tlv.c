#include "route-set.h"
#include "../platform/platform.h"
#include "../src/constants.h"


createroutertlv(RouterSet* aRouterSet, LinkSet* aLinkSet)
{

	static unsigned char type = 9;
	static unsigned char length = MAXROUTERS;
	static unsigned char IDseq = 0;
	static unsigned char IDmask = 0xf8;
	unsigned char linkqualroutedata[MAXROUTERS];
	int i;

	for (i=0;i<MAXROUTERS;i++)
	{
		if (aRouterSet[i]->mRouterID == ROUTER) // if router == me
		{
			linkqualroutedata[i] = 0x01;
		}else{
			unsigned char out = aRouterSet->
		}

	}


}


