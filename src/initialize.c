/*
** EPITECH PROJECT, 2023
** mysokoban
** File description:
** initialize.c
*/

#include "struct.h"
#include "my.h"

static void get_player(game_t *game, int i, int j)
{
    if (game->map[i][j] == 'P')
        game->map[i][j] = ' ';
}

static void set_valid_map(game_t *game, int i, int j)
{
    if (game->map[i][j] == '\n' && j < game->size.max_rows) {
        for (; j < game->size.max_rows; j++) {
            game->map[i][j] = ' ';
        }
        game->map[i][j + 1] = '\0';
    }
}

static void get_valid_map(game_t *game)
{
    for (int i = 0; game->map[i] != NULL; i ++)
        for (int j = 0; game->map[i][j] != '\0'; j ++)
            set_valid_map(game, i, j);
}

void get_map(game_t *game)
{
    for (int i = 0; game->map[i] != NULL; i ++) {
        for (int j = 0; game->map[i][j] != '\0'; j ++) {
            get_player(game, i, j);
        }
    }
}

static void number_holes(char *map_from_file, game_t *game)
{
    for (int i = 0; map_from_file[i] != '\0'; i ++)
        if (map_from_file[i] == 'O')
            game->nb_O += 1;
}

static int is_upper(int i, size_map_t *size, char **map)
{
    for (int j = 0; map[i][j] != '\0'; j ++)
        if (j > size->max_cols)
            size->max_cols = j;
    return size->max_cols;
}

static void get_size(char **map, size_map_t *size)
{
    size->max_cols = 0;
    size->max_rows = 0;
    for (int i = 0; map[i] != NULL; i ++) {
        size->max_rows = i;
        size->max_cols = is_upper(i, size, map);
    }
}

static void is_pos(char **map, int i, int j, pos_player_t *player)
{
    if (map[i][j] == 'P') {
        player->x = i;
        player->y = j;
        player->x_prev = i;
        player->y_prev = j;
    }
}

static void get_pos(char **map, pos_player_t *player)
{
    for (int i = 0; map[i] != NULL; i ++) {
        for (int j = 0; map[i][j] != '\0'; j ++) {
            is_pos(map, i, j, player);
        }
    }
}

void initialize(char *map_from_file, game_t *game)
{
    game->map_ff = map_from_file;
    game->map = my_str_to_word_array(map_from_file, '\n');
    game->map_reset = my_str_to_word_array(map_from_file, '\n');
    get_pos(game->map_reset, &game->player);
    get_pos(game->map_reset, &game->p_reset);
    get_map(game);
    game->event = true;
    game->win = false;
    game->lose = false;
    game->nb_blocked = 0;
    get_size(game->map, &game->size);
    get_valid_map(game);
    number_holes(game->map_ff, game);
}
