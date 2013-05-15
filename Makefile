CC=gcc
CFLAGS=-I/usr/local/include/nanomsg -lnanomsg

all: myclient myserver myserver2

myclient: myclient.c
	$(CC) $(CFLAGS) $< -o $@

myserver: myclient.c
	$(CC) $(CFLAGS) $< -o $@

myserver2: myclient.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f myclient myserver myserver2 test.ipc
