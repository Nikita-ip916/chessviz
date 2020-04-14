#include <stdio.h>
#include <stdlib.h>
void Board(int k, int l, int a[][l], int n, int m, int b[][m])
{
    int i = 0;
    while (b[i][0] != 0) {
        if (b[i][2] == 45 && b[i][0] >= 97 && b[i][0] <= 104
            && b[i][0] == b[i][3]
            && b[i][5] == 0) { // 3el "-"; 1el=4el "a"-"h"; 6el empty
            if (i % 2 == 0 && b[i][1] == 50
                && (b[i][4] == 51
                    || b[i][4] == 52)) { // m.white; 2el "2"; 5el "3"or"4"
                printf("\nRight %d move of white pawn ", i + 1);
            } else if (
                    i % 2 == 1 && b[i][1] == 55
                    && (b[i][4] == 54
                        || b[i][4] == 53)) { // m.black; 2el "7"; 5el "6"or"5"
                printf("\nRight %d move of black pawn  ", i + 1);
            }
        } else {
            printf("\nWrong %d move ", i + 1);
        }
        i++;
    }
    puts("\n");
}
