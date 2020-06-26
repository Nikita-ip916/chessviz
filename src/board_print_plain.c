#include <stdio.h>
#include <stdlib.h>
void PrintBoard(int board_size, int game_board[][board_size])
{
    int i, j;
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            printf("%c ", game_board[i][j]);
        }
        printf("\n");
    }
}
