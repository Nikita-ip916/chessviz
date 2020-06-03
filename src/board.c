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
    if (move_reader[i][2] == 45 && move_reader[i][0] >= 97
        && move_reader[i][0] <= 104 && move_reader[i][0] == move_reader[i][3]
        && move_reader[i][5] == 0) { // 3el "-"; 1el=4el "a"-"h"; 6el empty
        if (i % 2 == 0 && move_reader[i][1] == 50
            && (move_reader[i][4] == 51 || move_reader[i][4] == 52)
            && game_board[56 - move_reader[i][1]][move_reader[i][0] - 96] == 80
            && game_board[56 - move_reader[i][4]][move_reader[i][3] - 96]
                    == 32) { // m.white; 2el "2"; 5el "3"or"4"; aTake="p";
                             // aPut=" "
            printf("\nRight %d first move of white pawn\n", i + 1);
            game_board[56 - move_reader[i][1]][move_reader[i][0] - 96] = 32;
            game_board[56 - move_reader[i][4]][move_reader[i][3] - 96] = 80;
        } else if (
                i % 2 == 1 && move_reader[i][1] == 55
                && (move_reader[i][4] == 54 || move_reader[i][4] == 53)
                && game_board[56 - move_reader[i][1]][move_reader[i][0] - 96]
                        == 112
                && game_board[56 - move_reader[i][4]][move_reader[i][3] - 96]
                        == 32) { // m.black; 2el "7"; 5el "6"or"5";
                                 // aTake="p"; aPut=" "
            printf("\nRight %d first move of black pawn\n", i + 1);
            game_board[56 - move_reader[i][1]][move_reader[i][0] - 96] = 32;
            game_board[56 - move_reader[i][4]][move_reader[i][3] - 96] = 112;
        } else {
            printf("\nWrong %d first move (invalid order) pawn\n", i + 1);
        }
    } else if (
            ((move_reader[i][3] == 45
              && game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                      == 32)
             || (move_reader[i][3] == 120
                 && game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                         != 32))
            && move_reader[i][1] >= 97 && move_reader[i][1] <= 104
            && move_reader[i][2] >= 49 && move_reader[i][2] <= 56
            && move_reader[i][6] == 0
            && (game_board[56 - move_reader[i][2]][move_reader[i][1] - 96]
                        == move_reader[i][0]
                || game_board[56 - move_reader[i][2]][move_reader[i][1] - 96]
                        == move_reader[i][0] + 32)) {
        switch (move_reader[i][0]) {
        case 75: // King
            if (abs(move_reader[i][4] - move_reader[i][1]) < 2
                && abs(move_reader[i][5] - move_reader[i][2]) < 2) {
                if (i % 2 == 0
                    && game_board[56 - move_reader[i][2]]
                                 [move_reader[i][1] - 96]
                            < 91) {
                    printf("\nRight %d move of white king\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0];
                } else if (
                        i % 2 == 1
                        && game_board[56 - move_reader[i][2]]
                                     [move_reader[i][1] - 96]
                                > 96) {
                    printf("\nRight %d move of black king\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0] + 32;
                } else {
                    printf("\nWrong %d move (invalid order) king\n", i + 1);
                    break;
                }
                game_board[56 - move_reader[i][2]][move_reader[i][1] - 96] = 32;
            } else {
                printf("\nWrong %d move (invalid position) king\n", i + 1);
            }
            break;
        case 81: // Queen
            if (abs(move_reader[i][4] - move_reader[i][1])
                        == abs(move_reader[i][5] - move_reader[i][2])
                || move_reader[i][4] - move_reader[i][1] == 0
                || move_reader[i][5] - move_reader[i][2] == 0) {
                if (i % 2 == 0
                    && game_board[56 - move_reader[i][2]]
                                 [move_reader[i][1] - 96]
                            < 91) {
                    printf("\nRight %d move of white queen\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0];
                } else if (
                        i % 2 == 1
                        && game_board[56 - move_reader[i][2]]
                                     [move_reader[i][1] - 96]
                                > 96) {
                    printf("\nRight %d move of black queen\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0] + 32;
                } else {
                    printf("\nWrong %d move (invalid order) queen\n", i + 1);
                    break;
                }
                game_board[56 - move_reader[i][2]][move_reader[i][1] - 96] = 32;
            } else {
                printf("\nWrong %d move (invalid position) queen\n", i + 1);
            }
            break;
        case 82: // Rook
            if (move_reader[i][4] - move_reader[i][1] == 0
                || move_reader[i][5] - move_reader[i][2] == 0) {
                if (i % 2 == 0
                    && game_board[56 - move_reader[i][2]]
                                 [move_reader[i][1] - 96]
                            < 91) {
                    printf("\nRight %d move of white rook\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0];
                } else if (
                        i % 2 == 1
                        && game_board[56 - move_reader[i][2]]
                                     [move_reader[i][1] - 96]
                                > 96) {
                    printf("\nRight %d move of black rook\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0] + 32;
                } else {
                    printf("\nWrong %d move (invalid order) rook\n", i + 1);
                    break;
                }
                game_board[56 - move_reader[i][2]][move_reader[i][1] - 96] = 32;
            } else {
                printf("\nWrong %d move (invalid position) rook\n", i + 1);
            }
            break;
        case 78: // kNight
            if ((abs(move_reader[i][4] - move_reader[i][1]) == 2
                 && abs(move_reader[i][5] - move_reader[i][2]) == 1)
                || (abs(move_reader[i][4] - move_reader[i][1]) == 1
                    && abs(move_reader[i][5] - move_reader[i][2]) == 2)) {
                if (i % 2 == 0
                    && game_board[56 - move_reader[i][2]]
                                 [move_reader[i][1] - 96]
                            < 91) {
                    printf("\nRight %d move of white knight\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0];
                } else if (
                        i % 2 == 1
                        && game_board[56 - move_reader[i][2]]
                                     [move_reader[i][1] - 96]
                                > 96) {
                    printf("\nRight %d move of black knight\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0] + 32;
                } else {
                    printf("\nWrong %d move (invalid order) knight\n", i + 1);
                    break;
                }
                game_board[56 - move_reader[i][2]][move_reader[i][1] - 96] = 32;
            } else {
                printf("\nWrong %d move (invalid position) knight\n", i + 1);
            }
            break;
        case 66: // Bishop
            if (abs(move_reader[i][4] - move_reader[i][1])
                == abs(move_reader[i][5] - move_reader[i][2])) {
                if (i % 2 == 0
                    && game_board[56 - move_reader[i][2]]
                                 [move_reader[i][1] - 96]
                            < 91) {
                    printf("\nRight %d move of white bishop\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0];
                } else if (
                        i % 2 == 1
                        && game_board[56 - move_reader[i][2]]
                                     [move_reader[i][1] - 96]
                                > 96) {
                    printf("\nRight %d move of black bishop\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0] + 32;
                } else {
                    printf("\nWrong %d move (invalid order) bishop\n", i + 1);
                    break;
                }
                game_board[56 - move_reader[i][2]][move_reader[i][1] - 96] = 32;
            } else {
                printf("\nWrong %d move (invalid position) bishop\n", i + 1);
            }
            break;
        case 80: // Pawn
            if (abs(move_reader[i][5] - move_reader[i][2]) == 1
                && move_reader[i][4] - move_reader[i][1] == 0) {
                if (move_reader[i][5] - move_reader[i][2] == 1 && i % 2 == 0
                    && game_board[56 - move_reader[i][2]]
                                 [move_reader[i][1] - 96]
                            < 91) {
                    printf("\nRight %d move of white pawn\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0];
                } else if (
                        move_reader[i][5] - move_reader[i][2] == -1
                        && i % 2 == 1
                        && game_board[56 - move_reader[i][2]]
                                     [move_reader[i][1] - 96]
                                > 96) {
                    printf("\nRight %d move of black pawn\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0] + 32;
                } else {
                    printf("\nWrong %d move (invalid order) pawn\n", i + 1);
                    break;
                }
                game_board[56 - move_reader[i][2]][move_reader[i][1] - 96] = 32;
            } else if (
                    abs(move_reader[i][5] - move_reader[i][2]) == 1
                    && abs(move_reader[i][4] - move_reader[i][1]) == 1) {
                if (move_reader[i][5] - move_reader[i][2] == 1 && i % 2 == 0
                    && game_board[56 - move_reader[i][2]]
                                 [move_reader[i][1] - 96]
                            < 91) {
                    printf("\nRight %d take of white pawn\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0];
                } else if (
                        move_reader[i][5] - move_reader[i][2] == -1
                        && i % 2 == 1
                        && game_board[56 - move_reader[i][2]]
                                     [move_reader[i][1] - 96]
                                > 96) {
                    printf("\nRight %d take of black pawn\n", i + 1);
                    game_board[56 - move_reader[i][5]][move_reader[i][4] - 96]
                            = move_reader[i][0] + 32;
                } else {
                    printf("\nWrong %d take (invalid order) pawn\n", i + 1);
                    break;
                }
                game_board[56 - move_reader[i][2]][move_reader[i][1] - 96] = 32;
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
