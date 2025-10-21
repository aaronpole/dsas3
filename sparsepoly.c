#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coeff;
    int exp;
} Term;

void createPoly(Term poly[], int polysize) {
    for (int i = 0; i < polysize; ++i) {
        printf("Term %d - Enter exponent: ", i + 1);
        scanf("%d", &poly[i].exp);
        printf("Term %d - Enter coefficient: ", i + 1);
        scanf("%d", &poly[i].coeff);
    }
}

/*
 * Adds poly1 and poly2 (both sorted in descending exponents).
 * Fills result[] and returns number of terms written into result (resSize).
 */
int add(Term poly1[], Term poly2[], Term result[], int poly1size, int poly2size) {
    int i = 0, j = 0, k = 0;
    while (i < poly1size && j < poly2size) {
        if (poly1[i].exp == poly2[j].exp) {
            int sum = poly1[i].coeff + poly2[j].coeff;
            if (sum != 0) {                      // skip zero coefficient results
                result[k].exp = poly1[i].exp;
                result[k].coeff = sum;
                k++;
            }
            i++; j++;
        } else if (poly1[i].exp > poly2[j].exp) {
            result[k++] = poly1[i++];
        } else { // poly1[i].exp < poly2[j].exp
            result[k++] = poly2[j++];
        }
    }
    while (i < poly1size)  result[k++] = poly1[i++];
    while (j < poly2size)  result[k++] = poly2[j++];
    return k; // actual number of terms in result
}

void printPoly(Term poly[], int polysize) {
    if (polysize == 0) {
        printf("0\n");
        return;
    }
    for (int i = 0; i < polysize; ++i) {
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if (i + 1 < polysize) printf(" + ");
    }
    printf("\n");
}

int main(void) {
    int poly1size, poly2size;
    printf("Enter number of non-zero terms in polynomial one: ");
    if (scanf("%d", &poly1size) != 1 || poly1size < 0) return 1;
    printf("Enter number of non-zero terms in polynomial two: ");
    if (scanf("%d", &poly2size) != 1 || poly2size < 0) return 1;

    Term *poly1 = malloc(poly1size * sizeof(Term));
    Term *poly2 = malloc(poly2size * sizeof(Term));
    Term *result = malloc((poly1size + poly2size) * sizeof(Term));
    if (!poly1 || !poly2 || !result) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter terms for polynomial 1 (in descending exponent order):\n");
    createPoly(poly1, poly1size);
    printf("Enter terms for polynomial 2 (in descending exponent order):\n");
    createPoly(poly2, poly2size);

    printf("\nPoly1: ");
    printPoly(poly1, poly1size);
    printf("Poly2: ");
    printPoly(poly2, poly2size);

    int resSize = add(poly1, poly2, result, poly1size, poly2size);

    printf("\nSum: ");
    printPoly(result, resSize);

    free(poly1);
    free(poly2);
    free(result);
    return 0;
}
