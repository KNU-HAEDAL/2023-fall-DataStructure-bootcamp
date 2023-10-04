#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)\
    if ((p = malloc(s)) == NULL) {\
        fprintf(stderr, "Insufficient memory");\
        exit(1);\
    }

typedef struct polyNode *polyPointer;
typedef struct polyNode {
    float coef;
    int expon;
    polyPointer link;
} polyNode;

polyPointer insert(polyPointer *first, polyPointer x, float coefficient, int exponent);
int compare(int a, int b);
void attach(float coefficient, int exponent, polyPointer *ptr);
polyPointer padd(polyPointer a, polyPointer b);
void printPolynomial(polyPointer poly);

int main() {
    polyPointer a = NULL, b = NULL;
    polyPointer currentA = a;
    polyPointer currentB = b;
    int numTermsA, numTermsB;
    float coef;
    int expon;

    printf("A식의 항의 개수를 입력하세요: ");
    scanf("%d", &numTermsA);
    printf("계수와 지수를 입력하세요 (계수 지수):\n");
    for (int i = 0; i < numTermsA; ++i) {
        scanf("%f %d", &coef, &expon);
        currentA = insert(&a, currentA, coef, expon);
    }

    printf("B식의 항의 개수를 입력하세요: ");
    scanf("%d", &numTermsB);
    printf("계수와 지수를 입력하세요 (계수 지수):\n");
    for (int i = 0; i < numTermsB; ++i) {
        scanf("%f %d", &coef, &expon);
        currentB = insert(&b, currentB, coef, expon);
    }

    polyPointer result = padd(a, b);
    printf("두 식의 합: ");
    printPolynomial(result);

    return 0;
}

polyPointer insert(polyPointer *first, polyPointer x, float coefficient, int exponent) {
    polyPointer temp;
    MALLOC(temp, sizeof(polyNode));
    temp->coef = coefficient;
    temp->expon = exponent;

    if (*first) {
        temp->link = x->link;
        x->link = temp;
    } else {
        temp->link = NULL;
        *first = temp;
    }

    return temp;
}

int compare(int a, int b) {
    if (a < b) return -1;
    else if (a == b) return 0;
    else return 1;
}

void attach(float coefficient, int exponent, polyPointer *ptr) {
    polyPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->coef = coefficient;
    temp->expon = exponent;
    (*ptr)->link = temp;
    *ptr = temp;
}

polyPointer padd(polyPointer a, polyPointer b) {
    polyNode *c, *rear, *temp;
    int sum;
    MALLOC(rear, sizeof(polyNode));
    c = rear;
    while (a && b) {
        switch (compare(a->expon, b->expon)) {
            case -1:
                attach(b->coef, b->expon, &rear);
                b = b->link;
                break;
            case 0:
                sum = a->coef + b->coef;
                if (sum) attach(sum, a->expon, &rear);
                a = a->link;
                b = b->link;
                break;
            case 1:
                attach(a->coef, a->expon, &rear);
                a = a->link;
                break;
        }
    }

    for (; a; a = a->link) {
        attach(a->coef, a->expon, &rear);
    }
    
    for (; b; b = b->link) {
        attach(b->coef, b->expon, &rear);
    }
    rear->link = NULL;

    // 추가 노드 지우기
    temp = c;
    c = c->link;
    free(temp);
    return c;
}

void printPolynomial(polyPointer poly) {
    while (poly != NULL) {
        printf("%.2fx^%d ", poly->coef, poly->expon);
        poly = poly->link;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}
