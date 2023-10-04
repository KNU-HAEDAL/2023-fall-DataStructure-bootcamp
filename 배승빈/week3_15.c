#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)\
    if ((p = malloc(s)) == NULL) {\
        fprintf(stderr, "Insufficient memory");\
        exit(1);\
    }


typedef struct ListNode {
    int data;
    struct ListNode *link;
} ListNode;

ListNode* insertFirst(ListNode *head, int value) {
    ListNode *p;
    MALLOC(p, sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode *head, ListNode *pre, int value) {
    ListNode *p;
    MALLOC(p, sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* deleteFirst(ListNode *head) {
    ListNode *removed;
    if (head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode *head, ListNode *pre) {
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return removed;
}

void printList(ListNode *head) {
    for(; head; head = head->link) {
        printf("%d ", head->data);
    }
    printf("\n");
}

int findMin(ListNode *head) {
    if (head == NULL) {
        fprintf(stderr, "리스트 공백 에러\n");
        exit(1);
    }

    int min = head->data;
    ListNode *temp = head->link;
    while(temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
        }
        temp = temp->link;
    }

    return min;
}

int findMax(ListNode *head) {
    if (head == NULL) {
        fprintf(stderr, "리스트가 공백 에러\n");
        exit(1);
    }

    int max = head->data;
    ListNode *temp = head->link;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->link;
    }

    return max;
}

int main() {
    ListNode* head = NULL;
    head = insertFirst(head, 5);
    head = insert(head, head, 10);
    head = insert(head, head, 15);
    head = insert(head, head, 20);
    head = insert(head, head, 25);

    int min = findMin(head);
    int max = findMax(head);

    printf("최소값: %d\n최대값: %d\n", min, max);

    return 0;
}