#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include "../src/route-set.h"
#include "../src/ot-info.h"
#include "../src/constants.h"
#include "../src/link-set.h"
#include "../src/mleroute64tlv.h"
#include "../platform/posixradio.h"


static void timerHandler( int sig, siginfo_t *si, void *uc )
{

	OpenThread *aot = (OpenThread *) si->si_value.sival_ptr;
	
	//char c = aot->mRouterSet->mRouterSet[3].mRouterID + '0';
	//write(1,&c,1);




	unsigned char tlv[MAXROUTERS+4+1+1+1];

	createroutertlv(aot->mRouterSet, aot->mLinkSet, tlv);
	//write(1,&tlv,MAXROUTERS+4+1+1+1);

	//radiosendbeacon("WeNa!");
	
	
}

int broadcastinit(uint16_t expireS, OpenThread* aot)
{
	struct sigevent te;
	struct itimerspec its;
	struct sigaction sa; 
	timer_t timerID;
	int sigNo = SIGRTMIN;

	/* Set up signal handler. */
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = timerHandler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(sigNo, &sa, NULL) == -1) {
	perror("sigaction");
	}

	/* Set and enable alarm */
	te.sigev_notify = SIGEV_SIGNAL;
	te.sigev_signo = sigNo;
	te.sigev_value.sival_ptr = aot;
	timer_create(CLOCK_REALTIME, &te, &timerID);

	its.it_interval.tv_sec = expireS;
	its.it_interval.tv_nsec = 0;
	its.it_value.tv_sec = expireS;
	its.it_value.tv_nsec = 0;
	timer_settime(timerID, 0, &its, NULL);

	return 0;
}
