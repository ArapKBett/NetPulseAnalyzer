#ifndef TRANSPORT_PACKET_H
#define TRANSPORT_PACKET_H

#include <cstdint>

class TransportPacket {
public:
    uint16_t src_port;
    uint16_t dest_port;
    bool is_tcp;

    TransportPacket(const unsigned char* buffer, uint8_t protocol, uint8_t ihl);
    void print() const;
};

#endif
