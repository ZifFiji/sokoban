/*
** EPITECH PROJECT, 2023
** mysokoban
** File description:
** display.c
*/

#include <ncurses.h>
#include <unistd.h>
#include "struct.h"
#include "my.h"

static void display_every_char(game_t *game, int i, int j)
{
    if (game->map[i][j] == ' ' && game->map_reset[i][j] == 'O')
        mvaddch(LINES / 2 + i, COLS / 2 + j, 'O');
    else
        mvaddch(LINES / 2 + i, COLS / 2 + j, game->map[i][j]);
}

static void display_player(game_t *game, int i, int j)
{
    if (i == game->player.x && j == game->player.y)
        mvaddch(LINES / 2 + i, COLS / 2 + j, 'P');
    else
        display_every_char(game, i, j);
}

void display_result(game_t *game)
{
    if (game->win == true)
        return;
    if (game->lose == true)
        return;
}

void display_map(game_t *game)
{
    int i = 0;
    int j = 0;
    char *txt = "enlarge";

    clear();
    if (COLS < game->size.max_cols || LINES < game->size.max_rows) {
        mvprintw(LINES / 2, COLS / 2 - my_strlen(txt) / 2, "%s\n", txt);
        return;
    }
    for (i = 0; game->map[i] != NULL; i++) {
        for (j = 0; game->map[i][j] != '\0'; j++) {
            display_player(game, i, j);
        }
        mvaddch(LINES / 2 + i, COLS / 2 + j, '\n');
    }
    refresh();
}
