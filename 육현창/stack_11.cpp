#define MAX_SIZE 100
#include <stdio.h>
#include <string.h>

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

int main(){
    StackT a;
    int P_number=1;
    char str[100];
    make_stack(&a);
    printf("수식: ");
    scanf("%s",str);
    printf("괄호 수:");
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='('){
            push(&a,P_number);
            printf(" %d",P_number);
            P_number++;
        }
        else{
            printf(" %d",pop(&a));
        }
    }
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


