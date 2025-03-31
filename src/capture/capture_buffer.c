#include <stdio.h>
#include <stdlib.h>
#include "../include/common.h"

// Simple circular buffer (placeholder; not used directly in this example)
struct CircularBuffer {
    unsigned char* data;
    int head, tail, size;
};

struct CircularBuffer* init_buffer() {
    struct CircularBuffer* buf = malloc(sizeof(struct CircularBuffer));
    buf->data = malloc(BUFFER_SIZE * 10); // 10 packets worth
    buf->head = buf->tail = 0;
    buf->size = BUFFER_SIZE * 10;
    return buf;
}

void free_buffer(struct CircularBuffer* buf) {
    free(buf->data);
    free(buf);
}
