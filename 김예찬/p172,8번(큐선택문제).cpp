#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�ʱ� ����

#define SIZE 6
typedef int element;
typedef struct {
	element data[SIZE];
	int front, rear;
} QueueType;


//ť �⺻ �Լ���
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
		error((char*)"ť�� ��ȭ��");
	q->rear = (q->rear + 1) % SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error((char*)"ť�� ����");
	q->front = (q->front + 1) % SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error((char*)"ť�� ����");
	return q->data[(q->front + 1) % SIZE];
}

int get_count(QueueType* q) { //����� ������ ã�� �Լ�
	int count = 0; 
	int front = (q->front) % SIZE;

	if (is_empty(q)) //������� 0�� ��ȯ
		return 0;

	do { //������� ���� ��� front�� �ϳ��� �ø��� ����� ������ ��
		count += 1;
		front = (front+1) % SIZE;
	} while (front != q->rear);

	return count; //��� ���� ��ȯ
}

int main() {
	QueueType queue;
	int element;
	init_queue(&queue);

	//10~50���� ť�� �ֱ�
	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);
	enqueue(&queue, 40);
	enqueue(&queue, 50);

	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);

	enqueue(&queue, 30);

	printf("ť ��� ������: %d", get_count(&queue));

}