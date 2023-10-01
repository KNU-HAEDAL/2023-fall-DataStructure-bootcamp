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

    enqueue(&queue, 0);
    enqueue(&queue, 1);

    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("0 \n");
    } else if (n == 2) {
        printf("0 1 \n");
    } else {
        for (int i = 2; i < n; i++) {
            enqueue(&queue, queue.data[i - 1] + queue.data[i - 2]);
            int item = dequeue(&queue);
            printf("%d ", item);
        }
        printf("%d ", queue.data[queue.rear - 1]);
        printf("%d\n", queue.data[queue.rear]);
    }

    return 0;
}