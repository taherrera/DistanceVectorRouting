CC=gcc
CFLAGS=-Wall -I. -lrt -D POSIX

POSIXOBJS=main.o src/mleroute64tlv.o src/link-set.o platform/posix.o platform/posixtimer.o src/init.o

POSIXDEPS=platform/posix.h platform/posixtimer.h src/link-set.h src/route-set.h platform/platform.h src/constants.h src/init.h src/mleroute64tlv.h

%.o: %.c $(POSIXDEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


posix: $(POSIXOBJS)
	$(CC) $(CFLAGS) $(POSIXOBJS) -o main -lrt


clean:
	-rm -f $(POSIXOBJS)
	-rm -f main
