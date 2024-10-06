/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** number of letters
*/

#include <stddef.h>

static
int condition_null(char const *str)
{
    if (str == NULL) {
        return 1;
    }
    return 0;
}

int my_strlen(char const *str)
{
    int cpt;

    if (condition_null(str) == 1) {
        return -1;
    }
    cpt = 0;
    while (str[cpt] != '\0') {
        cpt += 1;
    }
    return (cpt);
}
