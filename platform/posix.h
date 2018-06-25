
#ifndef POSIX_H_
#define POSIX_H_

#include "platform.h"

/*
*
*  Define radiolisten abstraction
*
*/

void radiolisten(uint8_t channel);



/*
*
*  Define radiosendbeacon abstraction.
*  In this case we are going to use
*  UDP in the loopback
*
*/

void radiosendbeacon(char *aPayload);


#endif
