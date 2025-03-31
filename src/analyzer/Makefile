CXX = g++
CXXFLAGS = -Wall -O2 -fPIC
LDFLAGS = -shared

all: libnetpulse_analyzer.so

libnetpulse_analyzer.so: EthernetFrame.o IPPacket.o TransportPacket.o PacketAnalyzer.o
    $(CXX) $(LDFLAGS) -o ../../bin/$@ $^

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f *.o ../../bin/libnetpulse_analyzer.so
