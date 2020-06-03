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
    exp_game_board[6][1] = 32;
    exp_game_board[5][1] = 80;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 97;
    move_reader[i][1] = 50;
    move_reader[i][2] = 45;
    move_reader[i][3] = 97;
    move_reader[i][4] = 51;
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
    exp_game_board[1][1] = 32;
    exp_game_board[2][1] = 112;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 97;
    move_reader[i][1] = 55;
    move_reader[i][2] = 45;
    move_reader[i][3] = 97;
    move_reader[i][4] = 54;
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
    exp_game_board[6][1] = 32;
    exp_game_board[4][1] = 80;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 97;
    move_reader[i][1] = 50;
    move_reader[i][2] = 45;
    move_reader[i][3] = 97;
    move_reader[i][4] = 52;
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
    exp_game_board[1][1] = 32;
    exp_game_board[3][1] = 112;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 97;
    move_reader[i][1] = 55;
    move_reader[i][2] = 45;
    move_reader[i][3] = 97;
    move_reader[i][4] = 53;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(first_pawn_move, wrong_move)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 105;
    move_reader[i][1] = 55;
    move_reader[i][2] = 45;
    move_reader[i][3] = 105;
    move_reader[i][4] = 53;
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
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 104;
    move_reader[i][1] = 55;
    move_reader[i][2] = 45;
    move_reader[i][3] = 104;
    move_reader[i][4] = 53;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(king_move, moveW)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 75;
    exp_game_board[6][2] = 32;
    exp_game_board[5][2] = 75;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 75;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 98;
    move_reader[i][5] = 51;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(king_move, moveB)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 107;
    exp_game_board[6][2] = 32;
    exp_game_board[5][3] = 107;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 75;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 99;
    move_reader[i][5] = 51;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(king_move, wrong_move_horiz)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[4][1] = 75;
    exp_game_board[4][1] = 75;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 75;
    move_reader[i][1] = 97;
    move_reader[i][2] = 52;
    move_reader[i][3] = 45;
    move_reader[i][4] = 96;
    move_reader[i][5] = 52;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(king_move, wrong_move_vert)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[0][4] = 107;
    exp_game_board[0][4] = 107;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 75;
    move_reader[i][1] = 100;
    move_reader[i][2] = 56;
    move_reader[i][3] = 45;
    move_reader[i][4] = 100;
    move_reader[i][5] = 57;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[4][5] = 75;
    exp_game_board[4][5] = 75;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 75;
    move_reader[i][1] = 101;
    move_reader[i][2] = 52;
    move_reader[i][3] = 45;
    move_reader[i][4] = 102;
    move_reader[i][5] = 50;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 75;
    exp_game_board[6][2] = 75;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 75;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 98;
    move_reader[i][5] = 51;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_diagW)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 81;
    exp_game_board[6][2] = 32;
    exp_game_board[4][4] = 81;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 81;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 100;
    move_reader[i][5] = 52;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_vertW)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[4][5] = 81;
    exp_game_board[4][5] = 32;
    exp_game_board[0][5] = 81;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 81;
    move_reader[i][1] = 101;
    move_reader[i][2] = 52;
    move_reader[i][3] = 45;
    move_reader[i][4] = 101;
    move_reader[i][5] = 56;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_horizW)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[4][5] = 81;
    exp_game_board[4][5] = 32;
    exp_game_board[4][1] = 81;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 81;
    move_reader[i][1] = 101;
    move_reader[i][2] = 52;
    move_reader[i][3] = 45;
    move_reader[i][4] = 97;
    move_reader[i][5] = 52;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_diagB)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 113;
    exp_game_board[6][2] = 32;
    exp_game_board[4][4] = 113;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 81;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 100;
    move_reader[i][5] = 52;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_vertB)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[4][5] = 113;
    exp_game_board[4][5] = 32;
    exp_game_board[0][5] = 113;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 81;
    move_reader[i][1] = 101;
    move_reader[i][2] = 52;
    move_reader[i][3] = 45;
    move_reader[i][4] = 101;
    move_reader[i][5] = 56;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, move_horizB)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[4][5] = 113;
    exp_game_board[4][5] = 32;
    exp_game_board[4][1] = 113;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 81;
    move_reader[i][1] = 101;
    move_reader[i][2] = 52;
    move_reader[i][3] = 45;
    move_reader[i][4] = 97;
    move_reader[i][5] = 52;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, wrong_move_vert)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[4][5] = 81;
    exp_game_board[4][5] = 81;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 81;
    move_reader[i][1] = 101;
    move_reader[i][2] = 52;
    move_reader[i][3] = 45;
    move_reader[i][4] = 101;
    move_reader[i][5] = 48;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(queen_move, wrong_move_horiz)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[4][5] = 113;
    exp_game_board[4][5] = 113;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 81;
    move_reader[i][1] = 101;
    move_reader[i][2] = 52;
    move_reader[i][3] = 45;
    move_reader[i][4] = 105;
    move_reader[i][5] = 52;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[4][5] = 81;
    exp_game_board[4][5] = 81;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 81;
    move_reader[i][1] = 101;
    move_reader[i][2] = 52;
    move_reader[i][3] = 45;
    move_reader[i][4] = 99;
    move_reader[i][5] = 53;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[4][5] = 113;
    exp_game_board[4][5] = 113;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 81;
    move_reader[i][1] = 101;
    move_reader[i][2] = 52;
    move_reader[i][3] = 45;
    move_reader[i][4] = 97;
    move_reader[i][5] = 52;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(rook_move, move_vertW)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 82;
    exp_game_board[6][2] = 32;
    exp_game_board[2][2] = 82;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 82;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 98;
    move_reader[i][5] = 54;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(rook_move, move_horizW)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 82;
    exp_game_board[6][2] = 32;
    exp_game_board[6][6] = 82;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 2;
    move_reader[i][0] = 82;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 102;
    move_reader[i][5] = 50;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(rook_move, move_vertB)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 114;
    exp_game_board[6][2] = 32;
    exp_game_board[2][2] = 114;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 82;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 98;
    move_reader[i][5] = 54;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(rook_move, move_horizB)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 114;
    exp_game_board[6][2] = 32;
    exp_game_board[6][6] = 114;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 3;
    move_reader[i][0] = 82;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 102;
    move_reader[i][5] = 50;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 114;
    exp_game_board[6][2] = 114;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 82;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 102;
    move_reader[i][5] = 52;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 82;
    exp_game_board[6][2] = 82;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 3;
    move_reader[i][0] = 82;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 98;
    move_reader[i][5] = 54;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(knight_move, move_2h1vW)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 78;
    exp_game_board[6][2] = 32;
    exp_game_board[5][4] = 78;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 78;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 100;
    move_reader[i][5] = 51;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(knight_move, move_1h2vW)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 78;
    exp_game_board[6][2] = 32;
    exp_game_board[4][1] = 78;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 2;
    move_reader[i][0] = 78;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 97;
    move_reader[i][5] = 52;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(knight_move, move_2h1vB)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 110;
    exp_game_board[6][2] = 32;
    exp_game_board[5][4] = 110;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 78;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 100;
    move_reader[i][5] = 51;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(knight_move, move_1h2vB)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 110;
    exp_game_board[6][2] = 32;
    exp_game_board[4][1] = 110;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 3;
    move_reader[i][0] = 78;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 97;
    move_reader[i][5] = 52;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 78;
    exp_game_board[6][2] = 78;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 78;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 101;
    move_reader[i][5] = 51;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 78;
    exp_game_board[6][2] = 78;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 3;
    move_reader[i][0] = 78;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 97;
    move_reader[i][5] = 52;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(bishop_move, moveW)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 66;
    exp_game_board[6][2] = 32;
    exp_game_board[4][4] = 66;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 66;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 100;
    move_reader[i][5] = 52;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(bishop_move, moveB)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 98;
    exp_game_board[6][2] = 32;
    exp_game_board[4][4] = 98;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 66;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 100;
    move_reader[i][5] = 52;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 66;
    exp_game_board[6][2] = 66;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 2;
    move_reader[i][0] = 66;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 101;
    move_reader[i][5] = 52;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 98;
    exp_game_board[6][2] = 98;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 2;
    move_reader[i][0] = 66;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 100;
    move_reader[i][5] = 52;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(pawn_move, moveW)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 80;
    exp_game_board[6][2] = 32;
    exp_game_board[5][2] = 80;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 80;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 98;
    move_reader[i][5] = 51;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(pawn_move, moveB)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[1][2] = 112;
    exp_game_board[1][2] = 32;
    exp_game_board[2][2] = 112;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 80;
    move_reader[i][1] = 98;
    move_reader[i][2] = 55;
    move_reader[i][3] = 45;
    move_reader[i][4] = 98;
    move_reader[i][5] = 54;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 80;
    exp_game_board[6][2] = 80;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 80;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 45;
    move_reader[i][4] = 98;
    move_reader[i][5] = 53;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[1][2] = 112;
    exp_game_board[1][2] = 112;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 2;
    move_reader[i][0] = 80;
    move_reader[i][1] = 98;
    move_reader[i][2] = 55;
    move_reader[i][3] = 45;
    move_reader[i][4] = 98;
    move_reader[i][5] = 54;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(pawn_take, moveW)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[6][2] = 80;
    game_board[5][3] = 112;
    exp_game_board[6][2] = 32;
    exp_game_board[5][3] = 80;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 80;
    move_reader[i][1] = 98;
    move_reader[i][2] = 50;
    move_reader[i][3] = 120;
    move_reader[i][4] = 99;
    move_reader[i][5] = 51;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
CTEST(pawn_take, moveB)
{
    // Given
    int i, j, board_size = 9, game_board[board_size][board_size];
    int move_count = 16, move_size = 40, move_reader[move_count][move_size];
    int exp_game_board[board_size][board_size];
    FillBoard(board_size, game_board);
    FillBoard(board_size, exp_game_board);
    for (i = 0; i < board_size - 1; i++) {
        for (j = 1; j < board_size; j++) {
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[1][2] = 112;
    game_board[2][3] = 80;
    exp_game_board[1][2] = 32;
    exp_game_board[2][3] = 112;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 1;
    move_reader[i][0] = 80;
    move_reader[i][1] = 98;
    move_reader[i][2] = 55;
    move_reader[i][3] = 120;
    move_reader[i][4] = 99;
    move_reader[i][5] = 54;
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
            game_board[i][j] = exp_game_board[i][j] = 32;
        }
    }
    game_board[1][2] = 112;
    game_board[2][3] = 80;
    exp_game_board[1][2] = 112;
    exp_game_board[2][3] = 80;
    for (i = 0; i < move_count; i++) {
        for (j = 0; j < move_size; j++) {
            move_reader[i][j] = 0;
        }
    }
    i = 0;
    move_reader[i][0] = 80;
    move_reader[i][1] = 98;
    move_reader[i][2] = 55;
    move_reader[i][3] = 120;
    move_reader[i][4] = 99;
    move_reader[i][5] = 54;
    // When
    Board(board_size, game_board, move_count, move_size, move_reader, i);
    // Then
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            ASSERT_EQUAL(exp_game_board[i][j], game_board[i][j]);
        }
    }
}
