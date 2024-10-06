/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** dup a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char *my_strndup(char const *src, int i)
{
    char *dup;

    dup = malloc(sizeof(char) * (i + 1));
    for (int j = 0; src[j] != '\0' && j < i; j ++) {
        dup[j] = src[j];
    }
    dup[i] = '\0';
    return dup;
}
