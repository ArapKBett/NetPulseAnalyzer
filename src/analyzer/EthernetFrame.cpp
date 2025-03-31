#include "EthernetFrame.h"
#include <iostream>
#include <iomanip>

EthernetFrame::EthernetFrame(const unsigned char* buffer) {
    memcpy(dest_mac, buffer, 6);
    memcpy(src_mac, buffer + 6, 6);
    ethertype = (buffer[12] << 8) | buffer[13];
}

void EthernetFrame::print() const {
    std::cout << "Ethernet: ";
    for (int i = 0; i < 6; i++)
        std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)dest_mac[i] << (i < 5 ? ":" : " ");
    std::cout << "-> ";
    for (int i = 0; i < 6; i++)
        std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)src_mac[i] << (i < 5 ? ":" : " ");
    std::cout << "Type: " << std::hex << ethertype << std::dec << "\n";
}
