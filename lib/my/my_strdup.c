/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** dup a string
*/

#include <stdlib.h>
#include <stddef.h>

static
int my_strlen(char const *str)
{
    int cpt = 0;

    while (str[cpt] != '\0') {
        cpt += 1;
    }
    return (cpt);
}

static
char *my_strcpy(char *dest, char const *src)
{
    int cpt = 0;

    while (src[cpt] != '\0') {
        dest[cpt] = src[cpt];
        cpt ++;
    }
    dest[cpt] = '\0';
    return 0;
}

char *my_strdup(char const *src)
{
    char *dup = NULL;
    int len = my_strlen(src);

    dup = malloc(sizeof(char) * (len + 1));
    my_strcpy(dup, src);
    return dup;
}
