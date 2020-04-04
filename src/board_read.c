#include <stdio.h>
#include <stdlib.h>
void ReadBoard(int n, int m, int b[][m])
{
    int i, j;
    char ch;
    FILE* f;
    f = fopen("data.txt", "r");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            b[i][j] = 0;
        }
    }
    i = 0; // i-строка матрицы b
    j = 0; // j-столбец матрицы b
    do {
        ch = fgetc(f);
        if (ch == EOF) {
            break;
        } else if (ch == '\n' || ch == ' ') {
            j = 0;
            i++;
        } else {
            b[i][j] = ch;
            j++;
        }
    } while (ch != EOF);
    fclose(f);
}
