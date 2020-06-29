#include <stdio.h>
#include <stdlib.h>
void ReadBoard(int move_count, int move_size, int move_reader[][move_size])
{
    int i, j;
    char symbol;
    FILE* f;
    f = fopen("data.txt", "r");
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    j = 0;
    do {
        symbol = fgetc(f);
        if (symbol == EOF || i >= move_count || j >= move_size) {
            break;
        } else if (symbol == '\n' || symbol == ' ') {
            j = 0;
            i++;
        } else {
            move_reader[i][j] = symbol;
            j++;
        }
    } while (1);
    fclose(f);
}
