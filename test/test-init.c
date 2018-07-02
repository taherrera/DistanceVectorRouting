
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

		printf("ID = %d, NextHop = %u, RouteCost = %d",routerid, nexthopid, routecost);
		printf("\n ___________________________ \n");
	}

}


void printlinkset(LinkSet *aLinkSet)
{


	int i;
	unsigned char routerid;
	unsigned short linkmar;
	unsigned char linkqual;
	unsigned char age;

	for (i=0;i<MAXROUTERS;i++)
	{

		printf("Router %d: ",i);
		routerid = aLinkSet->mNeighborList[i].mRouterID;
		linkmar = aLinkSet->mNeighborList[i].mLastLinkMargin;
		linkqual = aLinkSet->mNeighborList[i].mIncomingLink.mQuality;
		age = aLinkSet->mNeighborList[i].mage;

		printf("ID = %u, LinkMargin = %u, LinkQuality = %u, age = %u",
			routerid, 	linkmar,  linkqual,	age);
		printf("\n ___________________________ \n");
	}

}
