/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** protos for mysokoban
*/

#ifndef MY_H_
    #define MY_H_

    #include "struct.h"

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
game_t sokoban(char *map);
char **my_str_to_word_array(char const *str, char const separator);
void my_show_tab(char **tab);
void initialize(char *map_from_file, game_t *game);
void display_map(game_t *game);
void display_result(game_t *game);
int check_win(game_t *game);
int check_lose(game_t *game);
void get_map(game_t *game);

#endif /* !MY_H_ */
