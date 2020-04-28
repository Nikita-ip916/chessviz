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
