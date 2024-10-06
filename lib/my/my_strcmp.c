/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** compare two string
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

int my_strcmp(char const *s1, char const *s2)
{
    int idx = 0;

    if ((condition_null(s1) == 1) || (condition_null(s2) == 1)) {
        return 84;
    }
    while (s1[idx] != '\0' && s2[idx] != '\0' && s1[idx] == s2[idx]) {
        idx ++;
    }
    return (s1[idx] - s2[idx]);
}
