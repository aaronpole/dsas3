#include <stdio.h>
#define MAX 100

typedef struct{
    int col;
    int row;
    int value;
} Term;

void readSparse(Term a[]){
    printf("Enter number of rows, columns and non-zero elements: ");
    scanf("%d %d %d",&a[0].row,&a[0].col,&a[0].value);

    printf("Enter row, column and value for each non-zero element:\n");
    for (int i = 1; i <= a[0].value; i++)
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
}

void printSparse(Term a[]){
    printf("Row\tCol\tVal\n");
    for (int i = 0; i <= a[0].value; i++)
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
}

void Transpose(Term a[], Term b[]){
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    int k = 1;
    for (int i = 0; i < a[0].col; i++){
        for (int j = 1; j < a[0].value; j++){
            if (a[j].col == i){
                b[k].row = a[j].col;
                b[k].col = a[j].col;
                b[k].value = a[j].value;
                k++;
            }
        }
    }
}

void addSparse(Term a[], Term b[], Term c[]){
    if (a[0].row != b[0].row || a[0].col != b[0].col){
        printf("Addition not possible — dimensions differ!\n");
        return;
    }
    c[0].row = a[0].row;
    c[0].col = a[0].col;

    int i = 1, j = 1, k = 1;
    while ( i <= a[0].value && j <= a[0].value){
        if (a[i].row == b[i].row && a[i].col == b[i].col){
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].value = a[i].value + b[j].value;
            i++; j++; k++;
        } else if (a[i].row < b[i].row || a[i].row == b[i].row && a[i].col < b[i].col){
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i <= a[0].value){c[k++] = a[i++];}
    while ( j <= b[0].value){c[k++] = b[j++];}
    c[0].value = k - 1;
}

int main() {
    Term a[MAX], b[MAX], sum[MAX], trans[MAX];

    printf("Enter first sparse matrix:\n");
    readSparse(a);
    printf("Enter second sparse matrix:\n");
    readSparse(b);

    printf("\nFirst Matrix:\n");
    displaySparse(a);
    printf("\nSecond Matrix:\n");
    displaySparse(b);

    addSparse(a, b, sum);
    printf("\nSum Matrix:\n");
    displaySparse(sum);

    transpose(a, trans);
    printf("\nTranspose of First Matrix:\n");
    displaySparse(trans);

    return 0;
}