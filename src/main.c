/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main for setting up
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "struct.h"

static
void display_info(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./my_sokoban map\n", 18);
    write(1, "DESCRIPTION\n", 12);
    write(1, "\tmap file representing the warehouse map,", 41);
    write(1, "containing ‘#’ for walls,\n", 30);
    write(1, "\t\t‘P’ for the player, ‘X’ ", 26);
    write(1, "for boxes and ‘O’ for storage locations.\n", 45);
}

static char *get_buff(char const *filepath)
{
    int fd;
    char *buff = NULL;
    struct stat s = {0};

    stat(filepath, &s);
    fd = open(filepath, O_RDONLY);
    buff = malloc(sizeof(char) * (s.st_size + 2));
    read(fd, buff, s.st_size);
    close(fd);
    buff[s.st_size] = '\0';
    return buff;
}

static int condition_file_empty_or_not_exist(char const *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer = NULL;
    int check = 0;
    struct stat s = {0};

    stat(file, &s);
    buffer = malloc(sizeof(char) * s.st_size + 1);
    check = read(fd, buffer, s.st_size);
    if (check == -1) {
        write(2, "Not able to read this file\n", 28);
        return 1;
    }
    if (check == 0) {
        write(2, "The file is empty\n", 19);
        return 1;
    }
    return 0;
}

static int condition_no_file(int ac)
{
    if (ac == 1) {
        write(2, "No file to read\n", 17);
        return 1;
    }
    return 0;
}

static int same_h_b(char const *buff)
{
    int box_count = 0;
    int hole_count = 0;

    for (int i = 0; buff[i] != '\0'; i ++) {
        if (buff[i] == 'X')
            box_count ++;
        if (buff[i] == 'O')
            hole_count ++;
    }
    if (box_count != hole_count) {
        write(2, "Different numbers of boxes and holes\n", 37);
        return 1;
    }
    return 0;
}

static int not_only_characters(char const *buff)
{
    int count = 0;

    for (int i = 0; buff[i] != '\0'; i ++)
        if (B_BS && B_P && B_O && B_H && B_S && B_X)
            count += 1;
    if (count != 0) {
        write(2, "Different characters in the map\n", 32);
        return 1;
    }
    return 0;
}

static int multiple_players(char const *buff)
{
    int count_p = 0;

    for (int i = 0; buff[i] != '\0'; i ++)
        if (buff[i] == 'P')
            count_p ++;
    if (count_p != 1) {
        if (count_p > 1)
            write(2, "Too many players\n", 17);
        if (count_p < 1)
            write(2, "Too few players\n", 16);
        return 1;
    }
    return 0;
}

static int error_case(int ac, char const **av)
{
    if (ac > 2) {
        write(2, "Too much arguments\n", 19);
        return 84;
    }
    if (condition_no_file(ac) == 1)
        return 84;
    if (condition_file_empty_or_not_exist(av[1]) == 1)
        return 84;
    if (not_only_characters(get_buff(av[1])) == 1)
        return 84;
    if (multiple_players(get_buff(av[1])) == 1)
        return 84;
    if (same_h_b(get_buff(av[1])) == 1)
        return 84;
    return 0;
}

int main(int ac, char const **av)
{
    char *buff = NULL;
    char flag[3] = "-h";
    game_t game;

    if (my_strcmp(av[1], flag) == 0) {
        display_info();
        return 0;
    }
    if (error_case(ac, av) == 84)
        return 84;
    buff = get_buff(av[1]);
    game = sokoban(buff);
    display_result(&game);
    if (game.lose == true)
        return 1;
    if (game.win == true) {
        return 0;
    }
}
