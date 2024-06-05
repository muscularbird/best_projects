/*
** EPITECH PROJECT, 2023
** my_apply_on_nodes
** File description:
** my_apply_on_nodes
*/

#include "../include/my_chn_lst.h"

int my_delete_nodes(chn_lst_t **begin, void const *data_ref)
{
    chn_lst_t *temp = *begin;
    chn_lst_t *clone = NULL;

    if (temp == NULL)
        return (84);
    while (temp) {
        clone = temp;
        if (temp->next->data == data_ref) {
            temp = temp->next->next;
            free(temp->next);
        } else {
            temp = temp->next;
        }
    }
    *begin = clone;
    return (0);
}
