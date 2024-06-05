/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** string
*/

#include "rpg.h"

const char *substring(const char *str, int start, int end)
{
    int length = end - start;
    char *sub = malloc(length + 1);

    for (int i = start; i < end; ++i) {
        sub[i - start] = str[i];
    }
    sub[length] = '\0';
    return sub;
}
