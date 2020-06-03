#include <stdio.h>
#include <stdlib.h>
void ReadBoard(int move_count, int move_size, int move_reader[][move_size])
{
    int i, j;
    char ch;
    FILE* f;
    f = fopen("data.txt", "r");
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
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
            move_reader[i][j] = ch;
            j++;
        }
    } while (ch != EOF);
    fclose(f);
}
