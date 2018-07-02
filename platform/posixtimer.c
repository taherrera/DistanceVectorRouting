#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include "../src/route-set.h"
#include "../src/constants.h"
#include "../platform/posixradio.h"


void timerHandler( int sig, siginfo_t *si, void *uc )
{


	//int node = si->si_value.sival_int;
	//printf("%p",si->si_value.sival_ptr);
	//printf("%s","hola");

	//write(1,"timerHandler\n",15);
	radiosendbeacon("WeNa!");
	
	
}

int broadcastinit(uint16_t expireS, RouterSet* aRouterSet)
{
	struct sigevent te;
	struct itimerspec its;
	struct sigaction sa;
	timer_t timerID = MYROUTER;
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
	te.sigev_value.sival_ptr = aRouterSet;
	te.sigev_value.sival_int = MYROUTER;
	timer_create(CLOCK_REALTIME, &te, &timerID);

	its.it_interval.tv_sec = expireS;
	its.it_interval.tv_nsec = 0;
	its.it_value.tv_sec = expireS;
	its.it_value.tv_nsec = 0;
	timer_settime(timerID, 0, &its, NULL);

	return 0;
}
