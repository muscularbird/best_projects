/*
** EPITECH PROJECT, 2023
** freemywordarray
** File description:
** freemywordarray
*/

#include "include/my.h"
#include <stdlib.h>

void free_warr(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
