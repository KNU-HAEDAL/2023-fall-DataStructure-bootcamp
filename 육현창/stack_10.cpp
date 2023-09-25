#define MAX_SIZE 6
#include <stdio.h>

typedef struct stack
{
    int data[MAX_SIZE];
    int top;
}StackT;

void make_stack(StackT* T);
int is_empty(StackT* T);
int is_pull(StackT* T);
void push(StackT* T,int d);
int pop(StackT* T);
void reverse_print(StackT* T);

int main(){
    StackT a;
    make_stack(&a);
    printf("정수 배열의 크기: %d\n",MAX_SIZE);
    printf("정수를 입력하시오: ");
    for(int i=0;i<MAX_SIZE;i++){
        int temp;
        scanf("%d",&temp);
        push(&a,temp);
    }
    reverse_print(&a);
}

void make_stack(StackT* T){
    T->top = -1;
}

int is_empty(StackT* T){
    if(T->top == -1)
        return 1;
    else
        return 0;
}

int is_pull(StackT* T){
    if(T->top >= 5)
        return 1;
    else
        return 0;
}

void push(StackT* T,int d){
    if(is_pull(T)){
        printf("ERROR: The stack is pull\n");
        return;
    }
    else{
        T->data[++(T->top)] = d;
    }
}

int pop(StackT* T){
    if(is_empty(T))
    {
        printf("ERROR: The stack is empty\n");
        return 0;
    }
    else{
        return T->data[(T->top)--];
    }
}

void reverse_print(StackT* T){
    printf("반전된 정수 배열:");
    for(int i=0;i<MAX_SIZE;i++){
        printf(" %d",pop(T));
    }
}

