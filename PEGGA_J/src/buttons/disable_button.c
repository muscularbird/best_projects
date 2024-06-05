/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/buttons/disable_button
** File description:
** you're a bad developer
*/

#include "rpg.h"

void disable_button(button_t **btn, int id)
{
    button_t *tmp = *btn;

    for (; tmp; tmp = tmp->next) {
        if (tmp->id == id) {
            tmp->state = DESACTIVATE;
            return;
        }
    }
}

void enable_button(button_t **btn, int id)
{
    button_t *tmp = *btn;

    for (; tmp; tmp = tmp->next) {
        if (tmp->id == id) {
            tmp->state = NONE;
            return;
        }
    }
}
