/*
** EPITECH PROJECT, 2023
** mysokoban
** File description:
** my_show_tab.c
*/

#include <stdlib.h>
#include <unistd.h>

void my_show_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i ++) {
        for (int j = 0; tab[i][j] != '\0'; j++)
            write(1, &tab[i][j], 1);
        write(1, "\n", 1);
    }
}
