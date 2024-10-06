/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** copies a string
*/

#include <stddef.h>

static
int condition_null(const char *str)
{
    if (str == NULL) {
        return 1;
    }
    return 0;
}

char *my_strcpy(char *dest, char const *src)
{
    int cpt = 0;

    if (condition_null(src) == 1) {
        return NULL;
    }
    while (src[cpt] != '\0') {
        dest[cpt] = src[cpt];
        cpt ++;
    }
    dest[cpt] = '\0';
    return dest;
}
