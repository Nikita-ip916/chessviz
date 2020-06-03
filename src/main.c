#include "board.h"
#include "board_fill_plain.h"
#include "board_print_plain.h"
#include "board_read.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 0, board_size = 9, game_board[board_size][board_size];
    int move_count = 128, move_size = 40, move_reader[move_count][move_size];
    FillBoard(board_size, game_board);
    PrintBoard(board_size, game_board);
    ReadBoard(move_count, move_size, move_reader);
    while (move_reader[i][0] != 0) {
        Board(board_size, game_board, move_count, move_size, move_reader, i);
        PrintBoard(board_size, game_board);
        i++;
    }
    printf("\n");
}
