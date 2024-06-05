/*
** EPITECH PROJECT, 2023
** my_apply_on_m_nodes
** File description:
** my_apply_on_m_nodes
*/

#include "../include/my_chn_lst.h"

chn_lst_t *my_find_node(chn_lst_t *begin, void const *data_ref)
{
    if (begin == NULL)
        return (void *)0;
    while (begin) {
        if (begin->data == data_ref)
            return begin;
        begin = begin->next;
    }
    return (void *)0;
}
