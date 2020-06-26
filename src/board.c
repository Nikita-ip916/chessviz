#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void Board(
        int board_size,
        int game_board[][board_size],
        int move_count,
        int move_size,
        int move_reader[][move_size],
        int i)
{
    if (move_reader[i][2] == '-' && move_reader[i][0] >= 'a'
        && move_reader[i][0] <= 'h' && move_reader[i][0] == move_reader[i][3]
        && move_reader[i][5] == 0) {
        if (i % 2 == 0 && move_reader[i][1] == '2'
            && (move_reader[i][4] == '3' || move_reader[i][4] == '4')
            && game_board['8' - move_reader[i][1]][move_reader[i][0] - '`']
                    == 'P'
            && game_board['8' - move_reader[i][4]][move_reader[i][3] - '`']
                    == ' ') {
            printf("\nRight %d first move of white pawn\n", i + 1);
            game_board['8' - move_reader[i][1]][move_reader[i][0] - '`'] = ' ';
            game_board['8' - move_reader[i][4]][move_reader[i][3] - '`'] = 'P';
        } else if (
                i % 2 == 1 && move_reader[i][1] == '7'
                && (move_reader[i][4] == '6' || move_reader[i][4] == '5')
                && game_board['8' - move_reader[i][1]][move_reader[i][0] - '`']
                        == 'p'
                && game_board['8' - move_reader[i][4]][move_reader[i][3] - '`']
                        == ' ') {
            printf("\nRight %d first move of black pawn\n", i + 1);
            game_board['8' - move_reader[i][1]][move_reader[i][0] - '`'] = ' ';
            game_board['8' - move_reader[i][4]][move_reader[i][3] - '`'] = 'p';
        } else {
            printf("\nWrong %d first move (invalid order) pawn\n", i + 1);
        }
    } else if (
            ((move_reader[i][3] == '-'
              && game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                      == ' ')
             || (move_reader[i][3] == 'x'
                 && game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                         != ' '))
            && move_reader[i][1] >= 'a' && move_reader[i][1] <= 'h'
            && move_reader[i][2] >= '1' && move_reader[i][2] <= '8'
            && move_reader[i][6] == 0
            && (game_board['8' - move_reader[i][2]][move_reader[i][1] - '`']
                        == move_reader[i][0]
                || game_board['8' - move_reader[i][2]][move_reader[i][1] - '`']
                        == move_reader[i][0] + ' ')) {
        switch (move_reader[i][0]) {
        case 'K': // King
            if (abs(move_reader[i][4] - move_reader[i][1]) < 2
                && abs(move_reader[i][5] - move_reader[i][2]) < 2) {
                if (i % 2 == 0
                    && game_board['8' - move_reader[i][2]]
                                 [move_reader[i][1] - '`']
                            <= 'Z') {
                    printf("\nRight %d move of white king\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0];
                } else if (
                        i % 2 == 1
                        && game_board['8' - move_reader[i][2]]
                                     [move_reader[i][1] - '`']
                                >= 'a') {
                    printf("\nRight %d move of black king\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0] + ' ';
                } else {
                    printf("\nWrong %d move (invalid order) king\n", i + 1);
                    break;
                }
                game_board['8' - move_reader[i][2]][move_reader[i][1] - '`']
                        = ' ';
            } else {
                printf("\nWrong %d move (invalid position) king\n", i + 1);
            }
            break;
        case 'Q': // Queen
            if (abs(move_reader[i][4] - move_reader[i][1])
                        == abs(move_reader[i][5] - move_reader[i][2])
                || move_reader[i][4] - move_reader[i][1] == 0
                || move_reader[i][5] - move_reader[i][2] == 0) {
                if (i % 2 == 0
                    && game_board['8' - move_reader[i][2]]
                                 [move_reader[i][1] - '`']
                            <= 'Z') {
                    printf("\nRight %d move of white queen\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0];
                } else if (
                        i % 2 == 1
                        && game_board['8' - move_reader[i][2]]
                                     [move_reader[i][1] - '`']
                                >= 'a') {
                    printf("\nRight %d move of black queen\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0] + ' ';
                } else {
                    printf("\nWrong %d move (invalid order) queen\n", i + 1);
                    break;
                }
                game_board['8' - move_reader[i][2]][move_reader[i][1] - '`']
                        = ' ';
            } else {
                printf("\nWrong %d move (invalid position) queen\n", i + 1);
            }
            break;
        case 'R': // Rook
            if (move_reader[i][4] - move_reader[i][1] == 0
                || move_reader[i][5] - move_reader[i][2] == 0) {
                if (i % 2 == 0
                    && game_board['8' - move_reader[i][2]]
                                 [move_reader[i][1] - '`']
                            <= 'Z') {
                    printf("\nRight %d move of white rook\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0];
                } else if (
                        i % 2 == 1
                        && game_board['8' - move_reader[i][2]]
                                     [move_reader[i][1] - '`']
                                >= 'a') {
                    printf("\nRight %d move of black rook\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0] + ' ';
                } else {
                    printf("\nWrong %d move (invalid order) rook\n", i + 1);
                    break;
                }
                game_board['8' - move_reader[i][2]][move_reader[i][1] - '`']
                        = ' ';
            } else {
                printf("\nWrong %d move (invalid position) rook\n", i + 1);
            }
            break;
        case 'N': // kNight
            if ((abs(move_reader[i][4] - move_reader[i][1]) == 2
                 && abs(move_reader[i][5] - move_reader[i][2]) == 1)
                || (abs(move_reader[i][4] - move_reader[i][1]) == 1
                    && abs(move_reader[i][5] - move_reader[i][2]) == 2)) {
                if (i % 2 == 0
                    && game_board['8' - move_reader[i][2]]
                                 [move_reader[i][1] - '`']
                            <= 'Z') {
                    printf("\nRight %d move of white knight\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0];
                } else if (
                        i % 2 == 1
                        && game_board['8' - move_reader[i][2]]
                                     [move_reader[i][1] - '`']
                                >= 'a') {
                    printf("\nRight %d move of black knight\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0] + ' ';
                } else {
                    printf("\nWrong %d move (invalid order) knight\n", i + 1);
                    break;
                }
                game_board['8' - move_reader[i][2]][move_reader[i][1] - '`']
                        = ' ';
            } else {
                printf("\nWrong %d move (invalid position) knight\n", i + 1);
            }
            break;
        case 'B': // Bishop
            if (abs(move_reader[i][4] - move_reader[i][1])
                == abs(move_reader[i][5] - move_reader[i][2])) {
                if (i % 2 == 0
                    && game_board['8' - move_reader[i][2]]
                                 [move_reader[i][1] - '`']
                            <= 'Z') {
                    printf("\nRight %d move of white bishop\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0];
                } else if (
                        i % 2 == 1
                        && game_board['8' - move_reader[i][2]]
                                     [move_reader[i][1] - '`']
                                >= 'a') {
                    printf("\nRight %d move of black bishop\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0] + ' ';
                } else {
                    printf("\nWrong %d move (invalid order) bishop\n", i + 1);
                    break;
                }
                game_board['8' - move_reader[i][2]][move_reader[i][1] - '`']
                        = ' ';
            } else {
                printf("\nWrong %d move (invalid position) bishop\n", i + 1);
            }
            break;
        case 'P': // Pawn
            if (abs(move_reader[i][5] - move_reader[i][2]) == 1
                && move_reader[i][4] - move_reader[i][1] == 0) {
                if (move_reader[i][5] - move_reader[i][2] == 1 && i % 2 == 0
                    && game_board['8' - move_reader[i][2]]
                                 [move_reader[i][1] - '`']
                            <= 'Z') {
                    printf("\nRight %d move of white pawn\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0];
                } else if (
                        move_reader[i][5] - move_reader[i][2] == -1
                        && i % 2 == 1
                        && game_board['8' - move_reader[i][2]]
                                     [move_reader[i][1] - '`']
                                >= 'a') {
                    printf("\nRight %d move of black pawn\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0] + ' ';
                } else {
                    printf("\nWrong %d move (invalid order) pawn\n", i + 1);
                    break;
                }
                game_board['8' - move_reader[i][2]][move_reader[i][1] - '`']
                        = ' ';
            } else if (
                    abs(move_reader[i][5] - move_reader[i][2]) == 1
                    && abs(move_reader[i][4] - move_reader[i][1]) == 1) {
                if (move_reader[i][5] - move_reader[i][2] == 1 && i % 2 == 0
                    && game_board['8' - move_reader[i][2]]
                                 [move_reader[i][1] - '`']
                            <= 'Z') {
                    printf("\nRight %d take of white pawn\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0];
                } else if (
                        move_reader[i][5] - move_reader[i][2] == -1
                        && i % 2 == 1
                        && game_board['8' - move_reader[i][2]]
                                     [move_reader[i][1] - '`']
                                >= 'a') {
                    printf("\nRight %d take of black pawn\n", i + 1);
                    game_board['8' - move_reader[i][5]][move_reader[i][4] - '`']
                            = move_reader[i][0] + ' ';
                } else {
                    printf("\nWrong %d take (invalid order) pawn\n", i + 1);
                    break;
                }
                game_board['8' - move_reader[i][2]][move_reader[i][1] - '`']
                        = ' ';
            } else {
                printf("\nWrong %d move (invalid position) pawn\n", i + 1);
            }
            break;
        default:
            printf("\nWrong %d move (invalid figure)\n", i + 1);
            break;
        }
    } else {
        printf("\nWrong %d move (invalid enter)\n", i + 1);
    }
}
