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
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}
