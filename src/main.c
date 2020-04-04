#include "board_fill_plain.h"
#include "board_print_plain.h"
#include "board_read.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 9, a[n][n], m = 16, k = 40, b[m][k];
    FillBoard(n, n, a);
    PrintBoard(n, n, a);
    ReadBoard(m, k, b);
}
