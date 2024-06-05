/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** draw_button
*/

#include "rpg.h"

void draw_button(game_t *g, button_t *btn)
{
    button_t *tmp = btn;

    while (tmp) {
        if (tmp->circle != NULL)
            sfRenderWindow_drawCircleShape(g->window, tmp->circle, NULL);
        if (tmp->rect != NULL)
            sfRenderWindow_drawRectangleShape(g->window, tmp->rect, NULL);
        tmp = tmp->next;
    }
}
