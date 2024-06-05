/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** add_node
*/

#include "rpg.h"

void add_node(button_t *new_node, button_t **button)
{
    if (*button == NULL) {
        *button = new_node;
        (*button)->next = NULL;
    } else
        add_node(new_node, &(*button)->next);
}
