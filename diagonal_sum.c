#include<stdio.h>
#include<stdlib.h>

#define max 100

int sumOfDiagonals(int matrix[max][max], int row,int col) {
    int sum = 0;
    int minDim = (row < col) ? row : col; // Get the smaller dimension

    for (int i = 0; i < minDim; i++) {
        sum += matrix[i][i];               // Primary diagonal
        if (i != col - 1 - i)             // Avoid double counting
            sum += matrix[i][col - 1 - i]; // Secondary diagonal
    }

    return sum;
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

int main() {
    int matrix[max][max], rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    inputMatrix(matrix, rows, cols);

    printf("Matrix:\n");
    displayMatrix(matrix, rows, cols);

    printf("Sum of diagonals: %d\n", sumOfDiagonals(matrix, rows, cols));

    return 0;
}