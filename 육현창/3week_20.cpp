#include <stdio.h>
#include <stdlib.h>

// 다항식 항(term)을 나타내는 구조체 정의
struct Term {
    int coefficient; // 계수
    int exponent;    // 지수
    struct Term* next;
};

// 다항식을 나타내는 구조체 정의
struct Polynomial {
    struct Term* head;
};

// 다항식의 항을 추가하는 함수
void insertTerm(struct Polynomial* poly, int coeff, int expo) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coeff;
    newTerm->exponent = expo;
    newTerm->next = NULL;

    if (poly->head == NULL) {
        poly->head = newTerm;
    } else {
        struct Term* current = poly->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// 두 다항식을 더하는 함수
struct Polynomial addPolynomials(struct Polynomial* poly1, struct Polynomial* poly2) {
    struct Polynomial result;
    result.head = NULL;

    struct Term* term1 = poly1->head;
    struct Term* term2 = poly2->head;

    while (term1 != NULL && term2 != NULL) {
        if (term1->exponent == term2->exponent) {
            int coeff_sum = term1->coefficient + term2->coefficient;
            int expo = term1->exponent;
            insertTerm(&result, coeff_sum, expo);
            term1 = term1->next;
            term2 = term2->next;
        } else if (term1->exponent > term2->exponent) {
            insertTerm(&result, term1->coefficient, term1->exponent);
            term1 = term1->next;
        } else {
            insertTerm(&result, term2->coefficient, term2->exponent);
            term2 = term2->next;
        }
    }

    // 남은 항들을 결과 다항식에 추가
    while (term1 != NULL) {
        insertTerm(&result, term1->coefficient, term1->exponent);
        term1 = term1->next;
    }

    while (term2 != NULL) {
        insertTerm(&result, term2->coefficient, term2->exponent);
        term2 = term2->next;
    }

    return result;
}

// 다항식을 출력하는 함수
void printPolynomial(struct Polynomial* poly) {
    struct Term* current = poly->head;

    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Polynomial poly1, poly2;
    poly1.head = NULL;
    poly2.head = NULL;

    // f(x) = 3x^6 + 7x^3 - 2x^2 - 9
    insertTerm(&poly1, 3, 6);
    insertTerm(&poly1, 7, 3);
    insertTerm(&poly1, -2, 2);
    insertTerm(&poly1, -9, 0);

    // g(x) = -2x^6 - 4x^4 + 6x^2 + 6x + 1
    insertTerm(&poly2, -2, 6);
    insertTerm(&poly2, -4, 4);
    insertTerm(&poly2, 6, 2);
    insertTerm(&poly2, 6, 1);
    insertTerm(&poly2, 1, 0);

    printf("f(x) = ");
    printPolynomial(&poly1);
    printf("g(x) = ");
    printPolynomial(&poly2);

    struct Polynomial sum = addPolynomials(&poly1, &poly2);
    printf("f(x) + g(x) = ");
    printPolynomial(&sum);

    return 0;
}