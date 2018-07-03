CC=gcc
CFLAGS=-Wall -I. -lrt -D POSIX

POSIXOBJS=main.o src/mleroute64tlv.o src/link-set.o platform/posixradio.o platform/posixtimer.o src/init.o gui/printtables.o

POSIXDEPS=platform/posixradio.h platform/posixtimer.h src/link-set.h src/route-set.h platform/platform.h src/constants.h src/init.h src/mleroute64tlv.h src/ot-info.h gui/printtables.h

%.o: %.c $(POSIXDEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


posix: $(POSIXOBJS)
	$(CC) $(CFLAGS) $(POSIXOBJS) -o main -lrt


clean:
	-rm -f $(POSIXOBJS)
	-rm -f main
