// �ش� ��Ʈķ�� �ڷᱸ�� <Week 2. Queue>
// p.171 3�� (���� ����)
// 2021115029 ������
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

	//�� �Է�
	for (int i = 10; i <= 50; i += 10) { 
		enqueue(&k, i);
	}
	printf("�׸� �Է� �� ť�� data: ");
	for (int i = k.front+1; i <= k.rear; i++) {
			printf("%d ", k.data[i]);
	}

	//�� ����
	for (int i = 0; i < 3; i++) { 
		printf("\n%d ����!", dequeue(&k));
	}
	printf("\n3�� ���� �� ť�� data: ");
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
		printf("\nť ��ȭ ����");
		exit(1);
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q) {
	if (q->rear == q->front) {
		printf("\nť ���� ����");
		exit(1);
	}
	return q->data[++(q->front)];
}