
#include "platform.h"
#include "posix.h"

#define MAXBUFFER 1027
#define IPV4ADDR "127.0.0.1"
#define PORT 1000

void radiolisten(uint8_t channel)
{

    struct sockaddr_in si_me, si_other;
     
    int s; 
    socklen_t slen = sizeof(si_other);
    socklen_t recv_len;
    char buf[MAXBUFFER];
     
    //create a UDP socket
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        perror("socket"); 
    }
     
    // zero out the structure
    memset((char *) &si_me, 0, sizeof(si_me));
     
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
     
    //bind socket to port
    if( bind(s , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
    {
        perror("bind");
    }

    if ((recv_len = recvfrom(s, buf, MAXBUFFER, 0, (struct sockaddr *) &si_other, &slen)) == -1)
        {
            perror("recvfrom()");
        }
         
        //print details of the client/peer and the data received
        printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Data: %s\n" , buf);

}


void radiosendbeacon(char *aPayload)
{

}

