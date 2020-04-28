#include <board.h>
#include <board_fill_plain.h>
#include <ctest.h>
CTEST(first_pawn_move, one_step_move_w1)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    exp[6][1] = 32;
    exp[5][1] = 80;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    b[0][0] = 97;
    b[0][1] = 50;
    b[0][2] = 45;
    b[0][3] = 97;
    b[0][4] = 51;
    // When
    i = 0;
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(first_pawn_move, one_step_move_w2)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    exp[6][8] = 32;
    exp[5][8] = 80;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    b[0][0] = 104;
    b[0][1] = 50;
    b[0][2] = 45;
    b[0][3] = 104;
    b[0][4] = 51;
    // When
    i = 0;
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(first_pawn_move, one_step_move_b1)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    exp[1][1] = 32;
    exp[2][1] = 112;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    b[1][0] = 97;
    b[1][1] = 55;
    b[1][2] = 45;
    b[1][3] = 97;
    b[1][4] = 54;
    // When
    i = 1;
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(first_pawn_move, one_step_move_b2)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    exp[1][8] = 32;
    exp[2][8] = 112;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    b[1][0] = 104;
    b[1][1] = 55;
    b[1][2] = 45;
    b[1][3] = 104;
    b[1][4] = 54;
    // When
    i = 1;
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(first_pawn_move, two_step_move_w1)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    exp[6][1] = 32;
    exp[4][1] = 80;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    b[0][0] = 97;
    b[0][1] = 50;
    b[0][2] = 45;
    b[0][3] = 97;
    b[0][4] = 52;
    // When
    i = 0;
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(first_pawn_move, two_step_move_w2)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    exp[6][8] = 32;
    exp[4][8] = 80;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    b[0][0] = 104;
    b[0][1] = 50;
    b[0][2] = 45;
    b[0][3] = 104;
    b[0][4] = 52;
    // When
    i = 0;
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(first_pawn_move, two_step_move_b1)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    exp[1][1] = 32;
    exp[3][1] = 112;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    b[1][0] = 97;
    b[1][1] = 55;
    b[1][2] = 45;
    b[1][3] = 97;
    b[1][4] = 53;
    // When
    i = 1;
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(first_pawn_move, two_step_move_b2)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    exp[1][8] = 32;
    exp[3][8] = 112;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    b[1][0] = 104;
    b[1][1] = 55;
    b[1][2] = 45;
    b[1][3] = 104;
    b[1][4] = 53;
    // When
    i = 1;
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(first_pawn_move, wrong_move1)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    b[1][0] = 105;
    b[1][1] = 55;
    b[1][2] = 45;
    b[1][3] = 105;
    b[1][4] = 53;
    // When
    i = 1;
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(first_pawn_move, wrong_move2)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    b[1][0] = 96;
    b[1][1] = 55;
    b[1][2] = 45;
    b[1][3] = 96;
    b[1][4] = 53;
    // When
    i = 1;
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(king_move, moveW)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < n; j++) {
            a[i][j] = exp[i][j] = 32;
        }
    }
    a[6][2] = 75;
    exp[6][2] = 32;
    exp[5][2] = 75;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    i = 0;
    b[i][0] = 75;
    b[i][1] = 98;
    b[i][2] = 50;
    b[i][3] = 45;
    b[i][4] = 98;
    b[i][5] = 51;
    // When
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(king_move, moveB)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < n; j++) {
            a[i][j] = exp[i][j] = 32;
        }
    }
    a[6][2] = 107;
    exp[6][2] = 32;
    exp[5][3] = 107;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    i = 1;
    b[i][0] = 75;
    b[i][1] = 98;
    b[i][2] = 50;
    b[i][3] = 45;
    b[i][4] = 99;
    b[i][5] = 51;
    // When
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(king_move, wrong_move_horiz)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < n; j++) {
            a[i][j] = exp[i][j] = 32;
        }
    }
    a[4][1] = 75;
    exp[4][1] = 75;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    i = 0;
    b[i][0] = 75;
    b[i][1] = 97;
    b[i][2] = 52;
    b[i][3] = 45;
    b[i][4] = 96;
    b[i][5] = 52;
    // When
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(king_move, wrong_move_vert)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < n; j++) {
            a[i][j] = exp[i][j] = 32;
        }
    }
    a[0][4] = 107;
    exp[0][4] = 107;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    i = 1;
    b[i][0] = 75;
    b[i][1] = 100;
    b[i][2] = 56;
    b[i][3] = 45;
    b[i][4] = 100;
    b[i][5] = 57;
    // When
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
CTEST(king_move, wrong_move_rules)
{
    // Given
    int i, j, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);
    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < n; j++) {
            a[i][j] = exp[i][j] = 32;
        }
    }
    a[4][5] = 75;
    exp[4][5] = 75;
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    i = 0;
    b[i][0] = 75;
    b[i][1] = 101;
    b[i][2] = 52;
    b[i][3] = 45;
    b[i][4] = 102;
    b[i][5] = 50;
    // When
    Board(n, n, a, m, k, b, i);
    // Then
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ASSERT_EQUAL(exp[i][j], a[i][j]);
        }
    }
}
