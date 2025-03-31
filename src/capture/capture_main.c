#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netpacket/packet.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include "../include/common.h"

extern void start_capture_thread(int sock);

int main() {
    int sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }
    printf("Starting packet capture...\n");
    start_capture_thread(sock);
    close(sock);
    return 0;
}
