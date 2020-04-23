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
