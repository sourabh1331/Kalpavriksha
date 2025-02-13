#include <stdio.h>
#include <stdlib.h>

#define max 100

void bubblesort(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void sort_mat(int mat[max][max],int row,int col){
    int size=row*col;
    int arr[size];
    int k=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr[k++]=mat[i][j];
        }
    }
    bubblesort(arr,size);
    k=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j]=arr[k++];
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
    int matrix[max][max], rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    inputMatrix(matrix, rows, cols);

    sort_mat(matrix,rows,cols);

    printf("Sorted matrix:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}