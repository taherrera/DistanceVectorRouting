#include "platform.h"
#include "posix.h"

#define MAXBUFFER 100
#define IPV4ADDR "127.0.0.1"
#define PORT 1000

void radiolisten(uint8_t channel)
{

char buffer[MAXBUFFER];

static struct sockaddr_in servaddr, cliaddr;

// create socket file descriptor
int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

// reset the vars to 0 ?
memset(&servaddr, 0, sizeof(servaddr));
memset(&cliaddr , 0, sizeof(cliaddr ));

servaddr.sin_family      = AF_INET;
servaddr.sin_port        = htons(PORT);
inet_aton(IPV4ADDR , &servaddr.sin_addr);


// bind socket to port
bind(sockfd, (const struct sockaddr *) &servaddr, sizeof(servaddr));
int len;
ssize_t n = recvfrom(sockfd, (char *)buffer, (size_t) 1024, MSG_WAITALL,(struct sockaddr*) &cliaddr, (socklen_t*) &len);

buffer[n] = '\0';

printf("%s\n" ,buffer);

}


void radiosendbeacon(char *aPayload)
{

}

