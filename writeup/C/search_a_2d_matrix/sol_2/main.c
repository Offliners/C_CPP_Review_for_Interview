#include<stdio.h>
#include<stdlib.h>

_Bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int front = 0;
    int end = matrixSize * (*matrixColSize) - 1;

    while(front <= end)
    {
        int mid = front + (end - front) / 2;
        int row = mid / (*matrixColSize);
        int col = mid % (*matrixColSize);

        if(matrix[row][col] > target)
            end = mid - 1;
        else if(matrix[row][col] < target)
            front = mid + 1;
        else
            return 1;
    }

    return 0;
}

int main(void)
{
    int target, temp;
    temp = scanf("%d", &target);

    int row, col;
    temp = scanf("%d %d", &row, &col);

    int **matrix = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < row; ++i)
        matrix[i] = (int*)malloc(col * sizeof(int));

    for(int i = 0; i < row; ++i)
        for(int j = 0; j <col; ++j)
            temp = scanf("%d", &matrix[i][j]);

    if(searchMatrix(matrix, row, &col, target))
        printf("true\n");
    else
        printf("false\n");

    for(int i = 0; i < row; ++i)
        free(matrix[i]);

    free(matrix);

    return 0;
}