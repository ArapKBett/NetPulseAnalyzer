#include "PacketAnalyzer.h"
#include <net/ethernet.h>

void PacketAnalyzer::analyze(const unsigned char* buffer, int len) {
    if (len < 14) return; // Minimum Ethernet frame size
    EthernetFrame eth(buffer);
    if (ntohs(eth.ethertype) == ETH_P_IP) { // IPv4
        IPPacket ip(buffer + 14);
        TransportPacket tp(buffer + 14, ip.protocol, ip.ihl);
        ip_packets.push_back(ip);
        eth.print();
        ip.print();
        tp.print();
    }
}

int PacketAnalyzer::get_packet_count() const {
    return ip_packets.size();
}
