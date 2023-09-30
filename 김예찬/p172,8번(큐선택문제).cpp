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
void error(char* message) {
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
		error((char*)"큐가 포화됨");
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
	return q->data[(q->front + 1) % SIZE];
}

int get_count(QueueType* q) { //요소의 개수를 찾는 함수
	int count = 0; 
	int front = (q->front) % SIZE;

	if (is_empty(q)) //비었으면 0을 반환
		return 0;

	do { //비어있지 않은 경우 front를 하나씩 올리며 요소의 개수를 셈
		count += 1;
		front = (front+1) % SIZE;
	} while (front != q->rear);

	return count; //요소 개수 반환
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

	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);

	enqueue(&queue, 30);

	printf("큐 요소 갯수는: %d", get_count(&queue));

}