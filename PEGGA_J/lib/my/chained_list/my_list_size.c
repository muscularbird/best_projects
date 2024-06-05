/*
** EPITECH PROJECT, 2023
** my_list_size
** File description:
** my_list_size
*/

#include "../include/my_chn_lst.h"

int my_list_size(chn_lst_t const *begin)
{
    int i = 0;

    if (begin == NULL)
        return (0);
    for (; begin->next != NULL; begin = begin->next)
        i++;
    return (i + 1);
}
