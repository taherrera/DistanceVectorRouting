CC=gcc
CFLAGS=-Wall -I. -D POSIX

POSIXOBJS=main.o src/link-set.o platform/posix.o

POSIXDEPS=platform/posix.h src/link-set.h src/route-set.h platform/platform.h src/constants.h


posix: $(POSIXOBJS)
	$(CC) $(CFLAGS) $(POSIXDEPS) -o $@


clean:
	-rm -f $(POSIXOBJS)
	-rm -f posix
