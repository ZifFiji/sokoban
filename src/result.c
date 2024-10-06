/*
** EPITECH PROJECT, 2023
** mysokoban
** File description:
** result.c
*/

#include <ncurses.h>
#include <unistd.h>
#include "struct.h"

static void box_in_hole(int *verif, game_t *game, int i, int j)
{
    if (game->map[i][j] == 'X' && game->map_reset[i][j] == 'O')
        *verif += 1;
}

int check_win(game_t *game)
{
    int verif = 0;

    for (int i = 0; game->map[i] != NULL; i ++) {
        for (int j = 0; game->map[i][j] != '\0'; j ++) {
            box_in_hole(&verif, game, i, j);
        }
    }
    if (verif == game->nb_O) {
        game->win = true;
        usleep(1000000);
        game->event = false;
    }
    return 0;
}

static void do_one_time(int *temp, bool *cond)
{
    if (*cond == false) {
        *temp += 1;
        *cond = (bool *)true;
    }
}

static void is_in_corner(game_t *game, int i, int *temp)
{
    bool cond = false;

    for (int j = 1; game->map[i][j] != '\0'; j ++) {
        if (MY_POS && (UP_X || UP_H) && (RIGHTX || RIGHTH) && O_N_UNDER) {
            do_one_time(temp, &cond);
        }
        if (MY_POS && (UP_X || UP_H) && (LEFT_H || LEFT_X) && O_N_UNDER) {
            do_one_time(temp, &cond);
        }
        if (MY_POS && (DOWN_X || DOWN_H) && (RIGHTX || RIGHTH) && O_N_UNDER) {
            do_one_time(temp, &cond);
        }
        if (MY_POS && (DOWN_X || DOWN_H) && (LEFT_H || LEFT_X) && O_N_UNDER) {
            do_one_time(temp, &cond);
        }
        cond = false;
    }
}

int check_lose(game_t *game)
{
    int temp = 0;

    game->nb_blocked = 0;
    for (int i = 1; game->map[i] != NULL; i ++) {
        is_in_corner(game, i, &temp);
        game->nb_blocked = temp;
    }
    if (game->nb_blocked >= game->nb_O) {
        game->lose = true;
        game->event = false;
    }
    return 0;
}
