// 해달 부트캠프 자료구조 <Week 3. Linked List>
// p.218 15번 (공통 문제)
// 정렬되지 않은 정수들이 저장된 단순 연결 리스트에서 최댓값과 최솟값 찾기
// 2021115029 박정원
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, int value);
void print_list(ListNode* head);
int cmp_max(ListNode* head, int max_data);
int cmp_min(ListNode* head, int min_data);


int main() {
	int max_data = -99999;
	int min_data = 99999;
	ListNode* head = NULL;

	//리스트 생성(10, 3, 27, 45, 9)
	head = insert_first(head, 9);
	head = insert_first(head, 45);
	head = insert_first(head, 27);
	head = insert_first(head, 3);
	head = insert_first(head, 10);

	printf("주어진 List: ");
	print_list(head);

	//최대값 최소값 찾기
	max_data = cmp_max(head, max_data);
	min_data = cmp_min(head, min_data);

	printf("최댓값: %d / 최솟값: %d", max_data, min_data);
}


ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
}

int cmp_max(ListNode* head, int max_data) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data > max_data) {
			max_data = p->data;
		}
	}

	return max_data;
}

int cmp_min(ListNode* head, int min_data) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data < min_data) {
			min_data = p->data;
		}
	}

	return min_data;
}