CC = gcc
CFLAGS = -Wall -O2
LDFLAGS = -pthread

all: netpulse_capture

netpulse_capture: capture_main.o capture_threads.o capture_buffer.o
    $(CC) -o ../../bin/netpulse_capture $^ $(LDFLAGS)

%.o: %.c
    $(CC) $(CFLAGS) -I../../include -c $< -o $@

clean:
    rm -f *.o ../../bin/netpulse_capture
