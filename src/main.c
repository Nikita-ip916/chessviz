#include "board_fill_plain.c"
#include "board_print_plain.c"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 9, a[n][n];
    FillBoard(n, n, a);
    PrintBoard(n, n, a);
}
