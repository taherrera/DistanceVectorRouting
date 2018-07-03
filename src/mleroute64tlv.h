#ifndef MLE_ROUTE64_H
#define MLE_ROUTE64_H

#include "route-set.h"
#include "link-set.h"

/*
*
*  Decide on minimum cost router
*
*/

void minimizeroute(RouterSet* aRouterSet, LinkSet* aLinkSet, unsigned int incomingrouter,unsigned int destrouter,unsigned char routecost);


/*
*
*  Creates a Route64 TLV to send routing info to ff02::01
*  tlv should be a unsigned char of MAXROUTERS+1+1+1+4 bytes long
*
*/

void createroutertlv(RouterSet* aRouterSet, LinkSet* aLinkSet, unsigned char* tlv);

/*
*
* This function checks if the received message is of type 9 (route 64 tlv)
* Then changes the routing table acordingly
*
*/

void readroutertlvandchangerouting(RouterSet *aRouterSet, LinkSet *aLinkSet, char * message, unsigned char RSSI);

#endif
