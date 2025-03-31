#ifndef IP_PACKET_H
#define IP_PACKET_H

#include <cstdint>
#include <arpa/inet.h>

class IPPacket {
public:
    uint8_t version;
    uint8_t ihl;
    uint16_t total_length;
    uint32_t src_ip;
    uint32_t dest_ip;
    uint8_t protocol;

    IPPacket(const unsigned char* buffer);
    void print() const;
};

#endif
