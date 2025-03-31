#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include "../include/common.h"

void* capture_thread(void* arg) {
    int sock = *(int*)arg;
    unsigned char buffer[BUFFER_SIZE];
    while (1) {
        int len = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (len < 0) {
            perror("recvfrom failed");
            continue;
        }
        printf("Captured packet of length: %d\n", len);
        // TODO: Pass buffer to analyzer (e.g., via shared memory or socket)
    }
    return NULL;
}

void start_capture_thread(int sock) {
    pthread_t tid;
    if (pthread_create(&tid, NULL, capture_thread, &sock) != 0) {
        perror("Thread creation failed");
        exit(1);
    }
    pthread_join(tid, NULL);
}
