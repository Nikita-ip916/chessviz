void FillBoard(int board_size, int game_board[][board_size])
{
    int i, j;
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            game_board[i][j] = 32;
        }
    }
    for (i = 1; i < board_size; i++) {
        game_board[i - 1][0] = 48 + board_size - i;
        game_board[board_size - 1][i] = i + 96;
        game_board[1][i] = 112;
        game_board[6][i] = 80;
    }
    game_board[0][1] = 114;
    game_board[0][2] = 110;
    game_board[0][3] = 98;
    game_board[0][4] = 113;
    game_board[0][5] = 107;
    game_board[0][6] = 98;
    game_board[0][7] = 110;
    game_board[0][8] = 114;
    for (i = 1; i < board_size; i++) {
        game_board[7][i] = game_board[0][i] - 32;
    }
}
