void FillBoard(int board_size, int game_board[][board_size])
{
    int i, j;
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            game_board[i][j] = ' ';
        }
    }
    for (i = 1; i < board_size; i++) {
        game_board[i - 1][0] = '0' + board_size - i;
        game_board[board_size - 1][i] = i - 1 + 'a';
        game_board[1][i] = 'p';
        game_board[6][i] = 'P';
    }
    game_board[0][1] = game_board[0][8] = 'r';
    game_board[0][2] = game_board[0][7] = 'n';
    game_board[0][3] = game_board[0][6] = 'b';
    game_board[0][4] = 'q';
    game_board[0][5] = 'k';
    for (i = 1; i < board_size; i++) {
        game_board[7][i] = game_board[0][i] - ' ';
    }
}
