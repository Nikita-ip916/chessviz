#include <board.h>
#include <board_fill_plain.h>
#include <ctest.h>
#include <sum.h>

CTEST(arithmetic_suite, simple_sum)
{
    // Given
    const int a = 1;
    const int b = 2;

    // When
    const int result = sum(a, b);

    // Then
    const int expected = 3;
    ASSERT_EQUAL(expected, result);
}
CTEST(arithmetic_suite2, simple_sum)
{
    // Given
    const int a = 34;
    const int b = 52;

    // When
    const int result = sum(a, b);

    // Then
    const int expected = 86;
    ASSERT_EQUAL(expected, result);
}
CTEST(first_pawn_move, one_step_move)
{
    // Given
    int i = 0, n = 9, a[n][n], m = 16, k = 40, b[m][k];
    int exp[n][n];
    FillBoard(n, n, a);
    FillBoard(n, n, exp);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            b[i][j] = 0;
        }
    }
    b[0][0] = 97;
    b[0][1] = 50;
    b[0][2] = 45;
    b[0][3] = 97;
    b[0][4] = 51;

    // When
    Board(n, n, a, m, k, b, i);

    // Then
}
