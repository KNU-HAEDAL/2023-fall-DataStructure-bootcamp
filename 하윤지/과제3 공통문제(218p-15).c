// 218p 15번 - 단순 연결 리스트에서 최대, 최솟값 찾기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode
{
	int data;
	listPointer link;
}listNode;

void insert(listPointer* first, listPointer* x, int data);
void clear(listPointer* first);

int main()
{
	listPointer first = NULL, trail, curr;
	int min, max;

	trail = first;
	insert(&first, &trail, 3);
	insert(&first, &trail, 5);
	insert(&first, &trail, 2);
	insert(&first, &trail, 4);
	insert(&first, &trail, 1);

	// 최댓값, 최솟값 찾기
	curr = first;
	min = max = first->data;
	while (curr != NULL) // 리스트의 끝이 아닐때
	{
		if (curr->data < min)
		{
			min = curr->data;
		}
		if (curr->data > max)
		{
			max = curr->data;
		}
		curr = curr->link; // 노드 이동
	}

	printf("최댓값: %d, 최솟값: %d\n", max, min);

	clear(&first);

	return 0;
}

void insert(listPointer* first, listPointer* x, int data) // x는 삽입할 위치 바로 앞 노드
{
	listPointer temp;
	temp = malloc(sizeof(*temp));
	temp->data = data;
	if (*first == NULL) // 빈 리스트에 추가하는 경우
	{
		temp->link = NULL;
		*first = temp;
		*x = temp; // 방금 삽입된 노드를 x가 가리키게 함 (main에서 trail이 계속 갱신됨)
	}
	else // 빈 리스트가 아닌 경우
	{
		if (x == NULL) // 가장 앞에 집어넣는 경우
		{
			temp->link = *first;
			*first = temp;
			*x = temp;
		}
		else
		{
			temp->link = (*x)->link;
			(*x)->link = temp;
			*x = temp;
		}
	}
}

void clear(listPointer* first)
{
	listPointer curr;
	while (*first != NULL)
	{
		curr = (*first)->link;
		free(*first);
		(*first) = curr;
	}
}
