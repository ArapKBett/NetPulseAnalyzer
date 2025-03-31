#include "TransportPacket.h"
#include <iostream>

TransportPacket::TransportPacket(const unsigned char* buffer, uint8_t protocol, uint8_t ihl) {
    int offset = ihl * 4; // IP header length in bytes
    src_port = (buffer[offset] << 8) | buffer[offset + 1];
    dest_port = (buffer[offset + 2] << 8) | buffer[offset + 3];
    is_tcp = (protocol == 6); // TCP = 6, UDP = 17
}

void TransportPacket::print() const {
    std::cout << (is_tcp ? "TCP" : "UDP") << ": "
              << src_port << " -> " << dest_port << "\n";
}
