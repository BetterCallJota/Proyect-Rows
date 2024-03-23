#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 6

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int value) {
    if (!isFull(q)) {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Cliente %d se ha unido a la fila\n", value);
    } else {
        printf("La fila está llena, el cliente %d no puede unirse\n", value);
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        int item = q->items[q->front];
        q->front++;
        printf("Cliente %d ha sido atendido\n", item);
        return item;
    } else {
        printf("La fila está vacía\n");
        return -1;
    }
}

int main() {
    Queue regularQueue;
    initQueue(&regularQueue);

    enqueue(&regularQueue, 101); // Cliente 101 se une a la fila
    enqueue(&regularQueue, 102); // Cliente 102 se une a la fila
    enqueue(&regularQueue, 103); // Cliente 103 se une a la fila
    enqueue(&regularQueue, 104); // Cliente 104 se une a la fila
    enqueue(&regularQueue, 105); // Cliente 105 se une a la fila
    enqueue(&regularQueue, 106); // Cliente 106 se une a la fila

    dequeue(&regularQueue); // Atender al próximo cliente

    return 0;
}

