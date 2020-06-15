#include <board.h>
#include <board_fill_plain.h>
#include <ctest.h>
CTEST(first_pawn_move, one_step_move_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    exp_game_board[6][1] = ' ';
    exp_game_board[5][1] = 'P';
    i = 0;
    move_reader[i][0] = move_reader[i][3] = 'a';
    move_reader[i][1] = '2';
    move_reader[i][2] = '-';
    move_reader[i][4] = '3';
    move_reader[i][5] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(first_pawn_move, one_step_move_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    exp_game_board[1][1] = ' ';
    exp_game_board[2][1] = 'p';
    i = 1;
    move_reader[i][0] = move_reader[i][3] = 'a';
    move_reader[i][1] = '7';
    move_reader[i][2] = '-';
    move_reader[i][4] = '6';
    move_reader[i][5] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(first_pawn_move, two_step_move_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    exp_game_board[6][1] = ' ';
    exp_game_board[4][1] = 'P';
    i = 0;
    move_reader[i][0] = move_reader[i][3] = 'a';
    move_reader[i][1] = '2';
    move_reader[i][2] = '-';
    move_reader[i][4] = '4';
    move_reader[i][5] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(first_pawn_move, two_step_move_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    exp_game_board[1][1] = ' ';
    exp_game_board[3][1] = 'p';
    i = 1;
    move_reader[i][0] = move_reader[i][3] = 'a';
    move_reader[i][1] = '7';
    move_reader[i][2] = '-';
    move_reader[i][4] = '5';
    move_reader[i][5] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(first_pawn_move, wrong_move_order)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    i = 0;
    move_reader[i][0] = move_reader[i][3] = 'h';
    move_reader[i][1] = '7';
    move_reader[i][2] = '-';
    move_reader[i][4] = '5';
    move_reader[i][5] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(king_move, move_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[5][2] = 'K';
    exp_game_board[6][2] = ' ';
    i = 0;
    move_reader[i][0] = 'K';
    move_reader[i][1] = move_reader[i][4] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][5] = '3';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(king_move, move_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[5][3] = 'k';
    exp_game_board[6][2] = ' ';
    i = 1;
    move_reader[i][0] = 'K';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'c';
    move_reader[i][5] = '3';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(king_move, wrong_move_rules)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[4][5] = exp_game_board[4][5] = 'K';
    i = 0;
    move_reader[i][0] = 'K';
    move_reader[i][1] = 'e';
    move_reader[i][2] = '4';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'f';
    move_reader[i][5] = '2';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(king_move, wrong_move_order)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[6][2] = 'K';
    i = 1;
    move_reader[i][0] = 'K';
    move_reader[i][1] = move_reader[i][4] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][5] = '3';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_diag_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[4][4] = 'Q';
    exp_game_board[6][2] = ' ';
    i = 0;
    move_reader[i][0] = 'Q';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'd';
    move_reader[i][5] = '4';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_vert_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[4][5] = exp_game_board[0][5] = 'Q';
    exp_game_board[4][5] = ' ';
    i = 0;
    move_reader[i][0] = 'Q';
    move_reader[i][1] = move_reader[i][4] = 'e';
    move_reader[i][2] = '4';
    move_reader[i][3] = '-';
    move_reader[i][5] = '8';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_horiz_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[4][5] = exp_game_board[4][1] = 'Q';
    exp_game_board[4][5] = ' ';
    i = 0;
    move_reader[i][0] = 'Q';
    move_reader[i][1] = 'e';
    move_reader[i][2] = move_reader[i][5] = '4';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'a';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_diag_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[4][4] = 'q';
    exp_game_board[6][2] = ' ';
    i = 1;
    move_reader[i][0] = 'Q';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'd';
    move_reader[i][5] = '4';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_vert_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[4][5] = exp_game_board[0][5] = 'q';
    exp_game_board[4][5] = ' ';
    i = 1;
    move_reader[i][0] = 'Q';
    move_reader[i][1] = move_reader[i][4] = 'e';
    move_reader[i][2] = '4';
    move_reader[i][3] = '-';
    move_reader[i][5] = '8';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_horiz_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[4][5] = exp_game_board[4][1] = 'q';
    exp_game_board[4][5] = ' ';
    i = 1;
    move_reader[i][0] = 'Q';
    move_reader[i][1] = 'e';
    move_reader[i][2] = move_reader[i][5] = '4';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'a';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, wrong_move_rules)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[4][5] = exp_game_board[4][5] = 'Q';
    i = 0;
    move_reader[i][0] = 'Q';
    move_reader[i][1] = 'e';
    move_reader[i][2] = '4';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'c';
    move_reader[i][5] = '5';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, wrong_move_order)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[4][5] = exp_game_board[4][5] = 'q';
    i = 0;
    move_reader[i][0] = 'Q';
    move_reader[i][1] = 'e';
    move_reader[i][2] = move_reader[i][5] = '4';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'a';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(rook_move, move_vert_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[2][2] = 'R';
    exp_game_board[6][2] = ' ';
    i = 0;
    move_reader[i][0] = 'R';
    move_reader[i][1] = move_reader[i][4] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][5] = '6';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(rook_move, move_horiz_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[6][6] = 'R';
    exp_game_board[6][2] = ' ';
    i = 2;
    move_reader[i][0] = 'R';
    move_reader[i][1] = 'b';
    move_reader[i][2] = move_reader[i][5] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'f';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(rook_move, move_vert_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[2][2] = 'r';
    exp_game_board[6][2] = ' ';
    i = 1;
    move_reader[i][0] = 'R';
    move_reader[i][1] = move_reader[i][4] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][5] = '6';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(rook_move, move_horiz_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[6][6] = 'r';
    exp_game_board[6][2] = ' ';
    i = 3;
    move_reader[i][0] = 'R';
    move_reader[i][1] = 'b';
    move_reader[i][2] = move_reader[i][5] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'f';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(rook_move, wrong_move_rules)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[6][2] = 'r';
    i = 0;
    move_reader[i][0] = 'R';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'f';
    move_reader[i][5] = '4';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(rook_move, wrong_move_order)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[6][2] = 'R';
    i = 3;
    move_reader[i][0] = 'R';
    move_reader[i][1] = move_reader[i][4] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][5] = '6';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(knight_move, move_2h1v_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[5][4] = 'N';
    exp_game_board[6][2] = ' ';
    i = 0;
    move_reader[i][0] = 'N';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'd';
    move_reader[i][5] = '3';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(knight_move, move_1h2v_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[4][1] = 'N';
    exp_game_board[6][2] = ' ';
    i = 2;
    move_reader[i][0] = 'N';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'a';
    move_reader[i][5] = '4';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(knight_move, move_2h1v_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[5][4] = 'n';
    exp_game_board[6][2] = ' ';
    i = 1;
    move_reader[i][0] = 'N';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'd';
    move_reader[i][5] = '3';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(knight_move, move_1h2v_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[4][1] = 'n';
    exp_game_board[6][2] = ' ';
    i = 3;
    move_reader[i][0] = 'N';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'a';
    move_reader[i][5] = '4';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(knight_move, wrong_move_rules)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[6][2] = 'N';
    i = 0;
    move_reader[i][0] = 'N';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'e';
    move_reader[i][5] = '3';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(knight_move, wrong_move_order)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[6][2] = 'N';
    i = 3;
    move_reader[i][0] = 'N';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'a';
    move_reader[i][5] = '4';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(bishop_move, move_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[4][4] = 'B';
    exp_game_board[6][2] = ' ';
    i = 0;
    move_reader[i][0] = 'B';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'd';
    move_reader[i][5] = '4';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(bishop_move, move_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[4][4] = 'b';
    exp_game_board[6][2] = ' ';
    i = 1;
    move_reader[i][0] = 'B';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'd';
    move_reader[i][5] = '4';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(bishop_move, wrong_move_rules)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[6][2] = 'B';
    i = 2;
    move_reader[i][0] = 'B';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'e';
    move_reader[i][5] = '4';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(bishop_move, wrong_move_order)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[6][2] = 'b';
    i = 2;
    move_reader[i][0] = 'B';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][4] = 'd';
    move_reader[i][5] = '4';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(pawn_move, move_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[5][2] = 'P';
    exp_game_board[6][2] = ' ';
    i = 0;
    move_reader[i][0] = 'P';
    move_reader[i][1] = move_reader[i][4] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][5] = '3';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(pawn_move, move_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[1][2] = exp_game_board[2][2] = 'p';
    exp_game_board[1][2] = ' ';
    i = 1;
    move_reader[i][0] = 'P';
    move_reader[i][1] = move_reader[i][4] = 'b';
    move_reader[i][2] = '7';
    move_reader[i][3] = '-';
    move_reader[i][5] = '6';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(pawn_move, wrong_move_rules)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[6][2] = 'P';
    i = 0;
    move_reader[i][0] = 'P';
    move_reader[i][1] = move_reader[i][4] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][5] = '5';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(pawn_move, wrong_move_order)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[1][2] = exp_game_board[1][2] = 'p';
    i = 2;
    move_reader[i][0] = 'P';
    move_reader[i][1] = move_reader[i][4] = 'b';
    move_reader[i][2] = '7';
    move_reader[i][3] = '-';
    move_reader[i][5] = '6';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(pawn_take, move_w)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[5][3] = 'P';
    game_board[5][3] = 'p';
    exp_game_board[6][2] = ' ';
    i = 0;
    move_reader[i][0] = 'P';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = 'x';
    move_reader[i][4] = 'c';
    move_reader[i][5] = '3';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(pawn_take, move_b)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[1][2] = exp_game_board[2][3] = 'p';
    game_board[2][3] = 'P';
    exp_game_board[1][2] = ' ';
    i = 1;
    move_reader[i][0] = 'P';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '7';
    move_reader[i][3] = 'x';
    move_reader[i][4] = 'c';
    move_reader[i][5] = '6';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(pawn_take, wrong_move_order)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[1][2] = exp_game_board[1][2] = 'p';
    game_board[2][3] = exp_game_board[2][3] = 'P';
    i = 0;
    move_reader[i][0] = 'P';
    move_reader[i][1] = 'b';
    move_reader[i][2] = '7';
    move_reader[i][3] = 'x';
    move_reader[i][4] = 'c';
    move_reader[i][5] = '6';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(wrong_move, invalid_figure)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = ' ';
        }
    }
    game_board[6][2] = exp_game_board[6][2] = 'F';
    i = 0;
    move_reader[i][0] = 'F';
    move_reader[i][1] = move_reader[i][4] = 'b';
    move_reader[i][2] = '2';
    move_reader[i][3] = '-';
    move_reader[i][5] = '3';
    move_reader[i][6] = 0;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(wrong_move, invalid_enter)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    i = 1;
    move_reader[i][0] = move_reader[i][3] = 'd';
    move_reader[i][1] = '7';
    move_reader[i][2] = '-';
    move_reader[i][4] = '5';
    move_reader[i][5] = 1;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
