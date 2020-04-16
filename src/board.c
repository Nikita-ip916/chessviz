#include "board_print_plain.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void Board(int k, int l, int a[][l], int n, int m, int b[][m])
{
    int i = 0;
    while (b[i][0] != 0) {
        if (b[i][2] == 45 && b[i][0] >= 97 && b[i][0] <= 104
            && b[i][0] == b[i][3]
            && b[i][5] == 0) { // 3el "-"; 1el=4el "a"-"h"; 6el empty
            if (i % 2 == 0 && b[i][1] == 50 && (b[i][4] == 51 || b[i][4] == 52)
                && a[56 - b[i][1]][b[i][0] - 96] == 80
                && a[56 - b[i][4]][b[i][3] - 96]
                        == 32) { // m.white; 2el "2"; 5el "3"or"4"; aTake="p";
                                 // aPut=" "
                printf("\nRight %d move of white pawn\n", i + 1);
                a[56 - b[i][1]][b[i][0] - 96] = 32;
                a[56 - b[i][4]][b[i][3] - 96] = 80;
                PrintBoard(k, l, a);
            } else if (
                    i % 2 == 1 && b[i][1] == 55
                    && (b[i][4] == 54 || b[i][4] == 53)
                    && a[56 - b[i][1]][b[i][0] - 96] == 112
                    && a[56 - b[i][4]][b[i][3] - 96]
                            == 32) { // m.black; 2el "7"; 5el "6"or"5";
                                     // aTake="p"; aPut=" "
                printf("\nRight %d move of black pawn\n", i + 1);
                a[56 - b[i][1]][b[i][0] - 96] = 32;
                a[56 - b[i][4]][b[i][3] - 96] = 112;
                PrintBoard(k, l, a);
            } else {
                printf("\nWrong %d move ", i + 1);
            }
        } else if (
                b[i][3] == 45 && b[i][1] >= 97 && b[i][1] <= 104
                && b[i][2] >= 49 && b[i][2] <= 56 && b[i][6] == 0
                && (a[56 - b[i][2]][b[i][1] - 96] == b[i][0]
                    || a[56 - b[i][2]][b[i][1] - 96] == b[i][0] + 32)
                && a[56 - b[i][5]][b[i][4] - 96] == 32) {
            switch (b[i][0]) {
            case 75: // King
                if (abs(b[i][4] - b[i][1]) < 2 && abs(b[i][5] - b[i][2]) < 2) {
                    if (i % 2 == 0) {
                        printf("\nRight %d move of white king\n", i + 1);
                        a[56 - b[i][5]][b[i][4] - 96] = b[i][0];
                    } else {
                        printf("\nRight %d move of black king\n", i + 1);
                        a[56 - b[i][5]][b[i][4] - 96] = b[i][0] + 32;
                    }
                    a[56 - b[i][2]][b[i][1] - 96] = 32;
                    PrintBoard(k, l, a);
                }
                break;
            case 81: // Queen
                if (abs(b[i][4] - b[i][1]) == abs(b[i][5] - b[i][2])
                    || b[i][4] - b[i][1] == 0 || b[i][5] - b[i][2] == 0) {
                    if (i % 2 == 0) {
                        printf("\nRight %d move of white queen\n", i + 1);
                        a[56 - b[i][5]][b[i][4] - 96] = b[i][0];
                    } else {
                        printf("\nRight %d move of black queen\n", i + 1);
                        a[56 - b[i][5]][b[i][4] - 96] = b[i][0] + 32;
                    }
                    a[56 - b[i][2]][b[i][1] - 96] = 32;
                    PrintBoard(k, l, a);
                }
                break;
            case 82: // Rook
            case 78: // kNight
            case 66: // Bishop
            case 80: // Pawn
            default:
                printf("\nWrong %d move ", i + 1);
                break;
            }
        } else {
            printf("\nWrong %d move ", i + 1);
        }
        i++;
    }
    puts("\n");
}
