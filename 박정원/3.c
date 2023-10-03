// 해달 부트캠프 자료구조 <Week 2. Queue>
// p.171 3번 (공통 문제)
// 2021115029 박정원
#include <stdio.h>
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;
QueueType k;

void init_queue(QueueType* q);
void enqueue(QueueType* q, int item);
int dequeue(QueueType* q);


int main() {
	init_queue(&k);

	//값 입력
	for (int i = 10; i <= 50; i += 10) { 
		enqueue(&k, i);
	}
	printf("항목 입력 후 큐의 data: ");
	for (int i = k.front+1; i <= k.rear; i++) {
			printf("%d ", k.data[i]);
	}

	//값 삭제
	for (int i = 0; i < 3; i++) { 
		printf("\n%d 삭제!", dequeue(&k));
	}
	printf("\n3개 삭제 후 큐의 data: ");
	for (int i = k.front+1; i <= k.rear; i++) {
			printf("%d ", k.data[i]);
	}
}

void init_queue(QueueType* q) {
	q->rear = -1;
	q->front = -1;
}

void enqueue(QueueType* q, int item) {
	if (q->rear == MAX_QUEUE_SIZE - 1) {
		printf("\n큐 포화 에러");
		exit(1);
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q) {
	if (q->rear == q->front) {
		printf("\n큐 공백 에러");
		exit(1);
	}
	return q->data[++(q->front)];
}