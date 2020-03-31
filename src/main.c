#include "board_fill_plain.h"
#include "board_print_plain.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 9, a[n][n];
    FillBoard(n, n, a);
    PrintBoard(n, n, a);
}
