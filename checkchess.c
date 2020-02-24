#include <stdio.h>
#include <stdlib.h>
const int n = 9;
int main()
{
    char a[n][n];
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = ' ';
        }
    }
    for (i = 1; i < n; i++) {
        a[i - 1][0] = 48 + n - i;
        a[n - 1][i] = i + 96;
        a[1][i - 1] = 112;
        a[6][i - 1] = 80;
    }
    a[0][1] = 114;
    a[0][2] = 110;
    a[0][3] = 98;
    a[0][4] = 113;
    a[0][5] = 107;
    a[0][6] = 98;
    a[0][7] = 110;
    a[0][8] = 114;
    for (i = 1; i < n; i++) {
        a[7][i] = a[0][i] - 32;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}
