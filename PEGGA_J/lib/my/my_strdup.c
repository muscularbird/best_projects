/*
** EPITECH PROJECT, 2023
** strdup
** File description:
** strdup
*/

#include <stdlib.h>
#include "include/my.h"

char *my_strdup(char const *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[i] = '\0';
    return dest;
}
