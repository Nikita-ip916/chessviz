#include <stdio.h>
#include <stdlib.h>
void PrintBoard(int n, int m, int a[][m])
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}
