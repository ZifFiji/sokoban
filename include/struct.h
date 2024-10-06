/*
** EPITECH PROJECT, 2023
** struct.h
** File description:
** struct for sokoban
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <ncurses.h>

    #define MY_POS game->map[i][j] == 'X'
    #define UP_H game->map[i - 1][j] == '#'
    #define DOWN_H game->map[i + 1][j] == '#'
    #define LEFT_H game->map[i][j - 1] == '#'
    #define RIGHTH game->map[i][j + 1] == '#'
    #define UP_X game->map[i - 1][j] == 'X'
    #define DOWN_X game->map[i + 1][j] == 'X'
    #define LEFT_X game->map[i][j - 1] == 'X'
    #define RIGHTX game->map[i][j + 1] == 'X'
    #define O_N_UNDER game->map_reset[i][j] != 'O'
    #define B_P buff[i] != 'P'
    #define B_BS buff[i] != '\n'
    #define B_X buff[i] != 'X'
    #define B_O buff[i] != 'O'
    #define B_H buff[i] != '#'
    #define B_S buff[i] != ' '

typedef struct pos_player_s {
    int x;
    int y;
    int x_prev;
    int y_prev;
} pos_player_t;

typedef struct size_map_s {
    int max_rows;
    int max_cols;
} size_map_t;

typedef struct game_s {
    char *map_ff;
    char **map;
    char **map_reset;
    bool event;
    int nb_O;
    bool win;
    bool lose;
    pos_player_t player;
    pos_player_t p_reset;
    size_map_t size;
    int nb_blocked;
} game_t;

#endif /* !STRUCT_H_ */
