#ifndef PACKET_ANALYZER_H
#define PACKET_ANALYZER_H

#include "EthernetFrame.h"
#include "IPPacket.h"
#include "TransportPacket.h"
#include <vector>

class PacketAnalyzer {
    std::vector<IPPacket> ip_packets;

public:
    void analyze(const unsigned char* buffer, int len);
    int get_packet_count() const;
};

#endif
