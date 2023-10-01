#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void initQueue(QueueType *q) {
    q->rear = -1;
    q->front = -1;
}

int isFull(QueueType *q) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(QueueType *q) {
    if (q->front == q->rear) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(QueueType *q, int item) {
    if (isFull(q)) {
        fprintf(stderr, "큐 포화 에러\n");
        exit(1);
    }
    q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q) {
    if (isEmpty(q)) {
        fprintf(stderr, "큐 공백 에러\n");
        exit(1);
    }
    int item = q->data[++(q->front)];
    return item;
}


int main() {
    QueueType queue;
    initQueue(&queue);

    for (int i = 1; i <= 5; i++) {
        enqueue(&queue, i * 10);
    }

    for (int i = 0; i < 3; i++) {
        dequeue(&queue);
    }

    printf("남아 있는 항목: ");
    for (int i = queue.front + 1; i <= queue.rear; i++) {
        printf("%d ", queue.data[i]);
    }
    return 0;
}