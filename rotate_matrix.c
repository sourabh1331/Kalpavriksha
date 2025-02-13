#include<stdio.h>
#include<stdlib.h>

#define max 100

void transpose(int mat[max][max],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=i+1;j<col;j++){
            int temp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
        }
    }
}


void rotate_90_clockwise(int mat[max][max],int row,int col){ // Reverse each row.
    transpose(mat,row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col/2;j++){
            int temp=mat[i][j];
            mat[i][j]=mat[i][col-j-1];
            mat[i][col-j-1]=temp;
        }
    }
}

void rotate_90_anticlockwise(int mat[max][max],int row,int col){ // Reverse each column.
    transpose(mat,row,col);
    for(int j=0;j<col;j++){
        for(int i=0;i<row/2;i++){
            int temp=mat[i][j];
            mat[i][j]=mat[row-i-1][j];
            mat[row-i-1][j]=temp;
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

void displayMatrix(int matrix[max][max], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matrix[max][max], rows, cols;
    int choice;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    inputMatrix(matrix, rows, cols);

    printf("Enter choice:\n1. Rotate 90 degrees clockwise\n2. Rotate 90 degrees anticlockwise\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            rotate_90_clockwise(matrix,rows,cols);
            break;
        case 2:
            rotate_90_anticlockwise(matrix,rows,cols);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("Rotated matrix:\n");
    displayMatrix(matrix, rows, cols);

    return 0;
}