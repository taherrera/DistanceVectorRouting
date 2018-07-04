#include "../src/route-set.h"
#include "../src/link-set.h"
#include "../src/constants.h"


void printrouterset(RouterSet *aRouterSet)
{


	int i;
	unsigned char routerid;
	unsigned char nexthopid;
	unsigned char routecost;

	for (i=0;i<MAXROUTERS;i++)
	{

		printf("Router %d: ",i);
		routerid = aRouterSet->mRouterSet[i].mRouterID;
		nexthopid = aRouterSet->mRouterSet[i].mNextHop;
		routecost = aRouterSet->mRouterSet[i].mRouteCost;

		printf("ID = %d, NextHop = %u, RouteCost = %d\n",routerid, nexthopid, routecost);
		
	}
	
};


void printlinkset(LinkSet *aLinkSet)
{


	int i;
	unsigned char routerid;
	unsigned short inlinkmar;
	unsigned char inlinkqual, outlinkqual;
	unsigned char age;
	unsigned char inlinkcost, outlinkcost;
	unsigned short inlinkmaravrg;
	
	printf("   ID  |LnkMarg|LnkMAVG|LnkQIN|LnkCIN|LnkQOUT|LnkCOUT|age\n");
	for (i=0;i<MAXROUTERS;i++)
	{

		printf("R%d: ",i);
		routerid = aLinkSet->mNeighborList[i].mRouterID;
		inlinkmar = aLinkSet->mNeighborList[i].mLastLinkMargin;
		inlinkqual = aLinkSet->mNeighborList[i].mIncomingLink.mQuality;
		inlinkcost = aLinkSet->mNeighborList[i].mIncomingLink.mLinkCost;
		inlinkmaravrg = aLinkSet->mNeighborList[i].mIncomingLink.mAverage;
		outlinkqual = aLinkSet->mNeighborList[i].mOutgoingLink.mQuality;
		outlinkcost = aLinkSet->mNeighborList[i].mOutgoingLink.mLinkCost;
		age = aLinkSet->mNeighborList[i].mage;
		

		printf("%u  |  %u    |  %u  |  %u   |  %u   |  %u   |  %u  |  %u ",
			routerid, inlinkmar,inlinkmaravrg, inlinkqual ,inlinkcost, outlinkqual , outlinkcost, age);
		printf("\n");
	}

};
