#ifndef ETHERNET_FRAME_H
#define ETHERNET_FRAME_H

#include <cstdint>

class EthernetFrame {
public:
    uint8_t dest_mac[6];
    uint8_t src_mac[6];
    uint16_t ethertype;

    EthernetFrame(const unsigned char* buffer);
    void print() const;
};

#endif
