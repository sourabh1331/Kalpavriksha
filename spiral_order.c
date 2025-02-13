#include <stdio.h>
#include <stdlib.h>

#define max 100

void printspiral(int mat[max][max],int row,int col){
    int top=0,left=0;
    int bottom=row-1,right=col-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            printf("%d ",mat[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            printf("%d ",mat[i][right]);
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", mat[bottom][i]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", mat[i][left]);
            left++;
        }
    }
}

void inputMatrix(int matrix[max][max], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int matrix[max][max], rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    inputMatrix(matrix, rows, cols);

    printf("Spiral Order Output:\n");
    printspiral(matrix, rows, cols);

    return 0;
}