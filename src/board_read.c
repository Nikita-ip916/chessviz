#include <stdio.h>
#include <stdlib.h>
void Board_read(int n, int m, int b[][m])
{
    int i, j;
    FILE* f;
    f = fopen("data.txt", "r");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            b[i][j] = 0;
        }
    }
}
