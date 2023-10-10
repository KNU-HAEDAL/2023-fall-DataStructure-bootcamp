#include <stdio.h>
#include <stdlib.h>

typedef struct Listnode
{
    int data;
    struct Listnode* link;
} Listnode;

Listnode* insert_F(Listnode* head, int v);
Listnode* insert(Listnode* head, Listnode* pre, int v);
Listnode* delete_F(Listnode* head);
int find_max(Listnode* head);
int find_min(Listnode* head);

int main() {
    Listnode* head = NULL;

    head = insert_F(head, 3);
    head = insert(head, head, 1);
    head = insert(head, head, 5);
    head = insert(head, head, 9);

    Listnode* current = head;
    printf("연결 리스트에 저장된 수열: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");

    int max = find_max(head);
    int min = find_min(head);

    printf("Min Value: %d\nMax Value: %d\n", min, max);

    // 동적 할당된 메모리를 해제해야 합니다.
    while (head != NULL) {
        head = delete_F(head);
    }

    return 0;
}

Listnode* insert_F(Listnode* head, int v) {
    Listnode* p = (Listnode*)malloc(sizeof(Listnode));
    p->data = v;
    p->link = head;
    return p; // 변경된 head 포인터를 반환합니다.
}

Listnode* insert(Listnode* head, Listnode* pre, int v) {
    Listnode* p = (Listnode*)malloc(sizeof(Listnode));
    p->data = v;
    p->link = pre->link;
    pre->link = p;
    return head;
}

Listnode* delete_F(Listnode* head) {
    Listnode* removed;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

int find_min(Listnode* head) {
    if (head == NULL) {
        printf("연결 리스트가 비어 있습니다.\n");
        return -1; // 에러를 나타내는 값
    }

    int min = head->data;
    Listnode* current = head;

    while (current != NULL) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->link;
    }

    return min;
}

int find_max(Listnode* head) {
    if (head == NULL) {
        printf("연결 리스트가 비어 있습니다.\n");
        return -1; // 에러를 나타내는 값
    }

    int max = head->data;
    Listnode* current = head;

    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->link;
    }

    return max;
}