#ifndef MLE_ROUTE64_H
#define MLE_ROUTE64_H

#include "route-set.h"
#include "link-set.h"

/*
*
*  Creates a Route64 TLV to send routing info to ff02::01
*  tlv should be a unsigned char of MAXROUTERS+1+1+1+4 bytes long
*
*/

void createroutertlv(RouterSet* aRouterSet, LinkSet* aLinkSet, unsigned char* tlv);



#endif
