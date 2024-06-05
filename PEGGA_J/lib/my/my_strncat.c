/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** my_strncat
*/

#include "include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0' && i < nb; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
