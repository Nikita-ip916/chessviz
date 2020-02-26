#include "Procedures.c"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 9, a[n][n];
    int i, j;
    FillBoard(n, n, a);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}
