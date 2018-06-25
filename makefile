CC=gcc
CFLAGS=-Wall -I.
POSIXFLAGS=-D POSIX
OBJS=main.o src/link-set.o
POSIXOBJS=platform/posix.o
DEPS= main.h src/link-set.h src/route-set.h platform/platform.h src/constants.h
POSIXDEPS=platform/posix.h

default: main

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)

main: $(OBJS)
	$(CC) $(OBJS) -o $@

posix: $(OBJS) $(POSIXOBJS)
	$(CC) $(POSIXFLAGS) $(CFLAGS) $(OBJS) -o $@


clean:
	-rm -f $(OBJS)
	-rm -f main
