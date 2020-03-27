#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int row, i, j;

    while(1) {
        if (scanf("%d", &row) == EOF) {
            return 0;
        }

        int matrix[row][row];
        int output[row][row];

        for (i = 0; i < row; i++) {
            for (j = 0; j < row; j++) {
                if (scanf("%d", &matrix[i][j]) == EOF) {
                    return 0;
                }
            }
        }
        for (i = 0; i < row; i++) {
            for (j = 0; j < row; j++) {
                //output[i][j] = matrix[j][row - 1 - i]; //90degree
                output[i][j] = matrix[row - 1 - i][row - 1 - j]; //180degree
            }
        }
        printf("output:\n");
        for (i = 0; i < row; i++) {
            for (j = 0; j < row; j++) {
                printf("%d ", output[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}