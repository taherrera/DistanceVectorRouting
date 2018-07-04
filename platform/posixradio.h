
#ifndef POSIX_H_
#define POSIX_H_

#include "platform.h"
#include "../src/ot-info.h"
/*
*
*  Define radiolisten abstraction: program stays forever in this function listening to the radio
*
*/

void radiolisten(uint8_t channel, OpenThread * aot);



/*
*
*  Define radiosendbeacon abstraction. This function sends aPayload to a multicast group
*  In this case we are going to use AF_INET DGRAM (IPV4)
*  
*
*/

void radiosendbeacon(unsigned char *aPayload);


#endif
