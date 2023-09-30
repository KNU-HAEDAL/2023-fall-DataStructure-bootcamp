#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//초기 세팅

#define SIZE 6
typedef int element;
typedef struct {
	element data[SIZE];
	int front, rear;
} QueueType;


//큐 기본 함수들
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % SIZE == q->front);
}

void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
		printf("\n");
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error((char *)"큐가 포화됨");
	q->rear = (q->rear + 1) % SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error((char*)"큐가 공백");
	q->front = (q->front + 1) % SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error((char*)"큐가 공백");
	return q->data[(q->front +1) % SIZE];
}

int main() {
	QueueType queue;
	int element;
	init_queue(&queue);

	//10~50까지 큐에 넣기
	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);
	enqueue(&queue, 40);
	enqueue(&queue, 50);

	// 큐 현황 출력
	queue_print(&queue);

	//큐에서 값 3번 가져오기
	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);

	// 큐 현황 출력
	queue_print(&queue);

	//정답 40,50이 남아있음
}