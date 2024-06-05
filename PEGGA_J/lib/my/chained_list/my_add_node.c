/*
** EPITECH PROJECT, 2023
** my_add_node
** File description:
** my_add_node
*/

#include "../include/my_chn_lst.h"

void my_add_node_first(chn_lst_t **begin, void *data)
{
    chn_lst_t *new_node = malloc(sizeof(chn_lst_t));

    new_node->data = data;
    new_node->next = *begin;
    *begin = new_node;
}

void my_add_node(chn_lst_t **begin, void *data)
{
    if (*begin == NULL) {
        *begin = malloc(sizeof(chn_lst_t));
        (*begin)->data = data;
        (*begin)->next = NULL;
    } else
        my_add_node(&(*begin)->next, data);
}

void my_free_list(chn_lst_t **begin)
{
    chn_lst_t *clone = *begin;

    while (*begin != NULL) {
        clone = (*begin)->next;
        free((*begin)->data);
        free(*begin);
        *begin = clone;
    }
}
