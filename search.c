#include<stdio.h>
#include<stdlib.h>

#define max 100
void search_matrix(int mat[max][max],int row,int col,int key){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==key){
                printf("Element found at position %d %d\n",i,j);
                return;
            }
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

int main(){
    int matrix[max][max], rows, cols,key;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    inputMatrix(matrix, rows, cols);

    printf("Enter element to search: ");
    scanf("%d",&key);

    search_matrix(matrix,rows,cols,key);

    return 0;
}