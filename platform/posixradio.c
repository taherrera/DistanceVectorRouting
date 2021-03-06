
#include "platform.h"
#include "posixradio.h"
#include "../src/ot-info.h"
#include "../src/constants.h"
#include "../src/mleroute64tlv.h"

#define MAXBUFFER 1027
#define IPV4ADDR "239.0.0.1"
#define PORT 1000

void radiolisten(uint8_t channel, OpenThread * aot)
{

	struct sockaddr_in addr;
	int sock, cnt;
	socklen_t addrlen;
	struct ip_mreq mreq;
	char message[MAXROUTERS+4+1+1+1];

	/* set up socket, DOMAIN IPV4, type datagram (connectionless, unreliable)*/
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		perror("socket");
		exit(1);
	}
	bzero((char *)&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(PORT);
	addrlen = sizeof(addr);
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
	{      
		perror("setsockopt(SO_REUSEADDR) failed");
		exit(1);
	}

	if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0)
	{        
		perror("bind");
		exit(1);
	}



	mreq.imr_multiaddr.s_addr = inet_addr(IPV4ADDR);         
	mreq.imr_interface.s_addr = htonl(INADDR_ANY);         
	if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP,
	&mreq, sizeof(mreq)) < 0) 
	{
		perror("setsockopt mreq");
		exit(1);
	}         
	while (1) 
	{
		cnt = recvfrom(sock, message, sizeof(message), 0, 
		(struct sockaddr *) &addr, &addrlen);

		if (cnt>0)
		{
			// Function reads if it is type 9 and changes the routing acordingly
			unsigned char RSSI = 10; //(received signal strenght)
			readroutertlvandchangerouting(aot->mRouterSet, aot->mLinkSet, message, RSSI);
		}
	}
}

void radiosendbeacon(unsigned char *aPayLoad)
{
	struct sockaddr_in addr;
	int sock, cnt;
	socklen_t addrlen;


	/* set up socket, DOMAIN IPV4, type datagram (connectionless, unreliable)*/
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) 
	{
		perror("socket");
		exit(1);
	}
	bzero((char *)&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(PORT);
	addrlen = sizeof(addr);

	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
	{      
		perror("setsockopt(SO_REUSEADDR) failed");
		exit(1);
	}

	/* send */
	addr.sin_addr.s_addr = inet_addr(IPV4ADDR);
	cnt = sendto(sock, aPayLoad, MAXROUTERS+4+1+1+1,
			0, (struct sockaddr *) &addr, addrlen);

	
	if (cnt < 0) {
		perror("sendto");
		exit(1);
	}


}

