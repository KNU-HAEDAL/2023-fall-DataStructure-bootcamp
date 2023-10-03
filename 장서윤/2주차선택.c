#include <stdio.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
element queue[MAX_QUEUE_SIZE];
int front = 0;
int rear = 0;

int is_empty() {
    return front == rear;
}

int is_full() {
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

void enqueue(element item) {
    if (is_full()) {
        printf("ť�� ��ȭ�����Դϴ�.\n");
        return;
    }
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear] = item;
}

element dequeue() {
    if (is_empty()) {
        printf("ť�� ��������Դϴ�.\n");
        return -1;
    }
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}

int get_count() {
    return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("ť�� �ִ� ����� ����: %d\n", get_count()); // 3

    dequeue();
    dequeue();

    printf("ť�� �ִ� ����� ����: %d\n", get_count()); // 1

    return 0;
}
