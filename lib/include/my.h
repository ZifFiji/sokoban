/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** macro for lib
*/

#ifndef MY_H_
    #define MY_H_

char **my_str_to_word_array(char const *str, char const separator);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strndup(char const *src, int n);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
void my_show_tab(char **tab);

#endif /* !MY_H_ */
