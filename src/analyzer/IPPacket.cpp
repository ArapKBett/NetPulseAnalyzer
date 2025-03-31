#include "IPPacket.h"
#include <iostream>

IPPacket::IPPacket(const unsigned char* buffer) {
    version = (buffer[0] >> 4);
    ihl = (buffer[0] & 0x0F);
    total_length = (buffer[2] << 8) | buffer[3];
    src_ip = *(uint32_t*)(buffer + 12);
    dest_ip = *(uint32_t*)(buffer + 16);
    protocol = buffer[9];
}

void IPPacket::print() const {
    std::cout << "IP: " << (int)version << "." << (int)ihl
              << ", Src: " << inet_ntoa(*(in_addr*)&src_ip)
              << ", Dst: " << inet_ntoa(*(in_addr*)&dest_ip)
              << ", Proto: " << (int)protocol << "\n";
}
