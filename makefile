CC=gcc
CFLAGS=-Wall -I. -D POSIX

POSIXOBJS=main.o src/link-set.o platform/posix.o src/init.o

POSIXDEPS=platform/posix.h src/link-set.h src/route-set.h platform/platform.h src/constants.h src/init.h

%.o: %.c $(POSIXDEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


posix: $(POSIXOBJS)
	$(CC) $(CFLAGS) $(POSIXOBJS) -o main


clean:
	-rm -f $(POSIXOBJS)
	-rm -f main
