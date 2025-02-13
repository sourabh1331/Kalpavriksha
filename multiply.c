#include<stdio.h>
#include<stdlib.h>

#define max 10

void multiplymatrix(int a[max][max],int b[max][max],int c[max][max],int r1,int c1,int r2,int c2){
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            c[i][j]=0;
            for(int k=0;k<r2;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}

void inputmatrix(int a[max][max],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
}

void printMatrix(int a[max][max],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d\n",a[i][j]);
        }
    }
}


int main() {
    int A[max][max], B[max][max], C[max][max];
    int r1, c1, r2, c2;

    printf("Enter rows and columns for matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible. Columns of A must equal rows of B.\n");
        return 1;
    }

    printf("Enter elements of matrix A:\n");
    inputmatrix(A, r1, c1);

    printf("Enter elements of matrix B:\n");
    inputmatrix(B, r2, c2);

    multiplymatrix(A, B, C, r1, c1, r2, c2);

    printf("Resultant Matrix C:\n");
    printMatrix(C, r1, c2);

    return 0;
}