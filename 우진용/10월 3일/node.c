#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE {
	int data;
	struct NODE* next;
} NODE;
NODE* list = NULL;

void add(int data)
{
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->data = data;
	p->next = NULL;
	if (list == NULL)
	{
		list = p;
		return;
	}
	else
	{
		NODE* tmp = list;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = p;
		return;
	}

}


void find_max()
{
	NODE* tmp = list;
	int max;
	max = list->data;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (max <= tmp->data)
		{
			max = tmp->data;
		}
	}
	printf("max : %d\n", max);
}


void find_min()
{
	NODE* tmp = list;
	int min;
	min = list->data;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (min >= tmp->data)
		{
			min = tmp->data;
		}
	}
	printf("min : %d", min);
}

void Nprint()
{
	NODE* tmp = list;
	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int main()
{
	srand(time(NULL));
	int data;

	for (int i = 0; i < 10; i++)
	{
		data = (rand() % 100) + 1;
		add(data);
	}

	Nprint();

	find_max();
	find_min();
}