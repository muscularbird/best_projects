/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** my_show_word_array
*/

#include "include/my.h"

int my_array_size(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}
