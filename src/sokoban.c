/*
** EPITECH PROJECT, 2023
** sokoban.c
** File description:
** game of sokoban
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"

static void move_up(char **map, game_t *game)
{
    int up = game->player.x - 1;
    char up_map = map[up][game->player.y];
    int box_row;

    if (up > 0 && up_map != '#' && up_map != 'X') {
        map[game->player.x][game->player.y] = ' ';
        game->player.x = up;
    }
    if (map[up][game->player.y] == 'X'
    && map[up - 1][game->player.y] != '#'
    && map[up - 1][game->player.y] != 'X'
    && up - 1 > 0) {
        box_row = up - 1;
        game->player.x = up;
        map[box_row][game->player.y] = 'X';
        map[box_row + 1][game->player.y] = ' ';
    }
}

static void move_left(char **map, game_t *game)
{
    int left = game->player.y - 1;
    char left_map = map[game->player.x][left];
    int box_col;

    if (left >= 0 && left_map != '#' && left_map != 'X') {
        map[game->player.x][game->player.y] = ' ';
        game->player.y = left;
    }
    if (map[game->player.x][left] == 'X'
    && map[game->player.x][left - 1] != '#'
    && map[game->player.x][left - 1] != 'X'
    && left - 1 >= 0) {
        box_col = left - 1;
        game->player.y = left;
        map[game->player.x][box_col] = 'X';
        map[game->player.x][box_col + 1] = ' ';
    }
}

static void move_right(char **map, game_t *game)
{
    int right = game->player.y + 1;
    char right_map = map[game->player.x][right];
    int box_col;

    if (right < my_strlen(map[game->player.x]) && right_map != '#'
    && right_map != 'X') {
        map[game->player.x][game->player.y] = ' ';
        game->player.y = right;
    }
    if (map[game->player.x][right] == 'X'
    && map[game->player.x][right + 1] != '#'
    && map[game->player.x][right + 1] != 'X'
    && map[game->player.x][right + 1] != '\0') {
        box_col = right + 1;
        game->player.y = right;
        map[game->player.x][box_col] = 'X';
        map[game->player.x][box_col - 1] = ' ';
    }
}

static void move_down(char **map, game_t *game)
{
    int down = game->player.x + 1;
    char down_map = map[down][game->player.y];
    char temp = ' ';
    int box_row;

    if (down < game->size.max_rows && down_map != '#' && down_map != 'X') {
        map[game->player.x][game->player.y] = ' ';
        game->player.x = down;
    }
    if (map[down][game->player.y] == 'X'
    && map[down + 1][game->player.y] != '#'
    && map[down + 1][game->player.y] != 'X'
    && down + 1 < game->size.max_rows) {
        box_row = down + 1;
        map[box_row - 1][game->player.y] = temp;
        game->player.x = down;
        map[box_row][game->player.y] = 'X';
    }
}

static void free_all(game_t *game)
{
    for (int i = 0; game->map[i] != NULL; i ++) {
        free(game->map[i]);
    }
    for (int i = 0; game->map_reset[i] != NULL; i ++) {
        free(game->map_reset[i]);
    }
    free(game->map_reset);
    free(game->map);
}

static void key_press(game_t *game, int key)
{
    switch (key) {
        case ' ':
            game->map = my_str_to_word_array(game->map_ff, '\n');
            get_map(game);
            game->player = game->p_reset;
            break;
        case KEY_UP:
            move_up(game->map, game);
            break;
        case KEY_LEFT:
            move_left(game->map, game);
            break;
        case KEY_RIGHT:
            move_right(game->map, game);
            break;
        case KEY_DOWN:
            move_down(game->map, game);
            break;
    }
}

game_t sokoban(char *map_from_file)
{
    game_t game;

    initialize(map_from_file, &game);
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    display_map(&game);
    while (game.event) {
        key_press(&game, getch());
        display_map(&game);
        check_win(&game);
        check_lose(&game);
    }
    endwin();
    free_all(&game);
    return game;
}
