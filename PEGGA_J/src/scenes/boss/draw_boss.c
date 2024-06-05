/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** draw_boss
*/

#include "rpg.h"

void draw_boss(game_t *g)
{
    button_t *tmp = g->sc_boss->btn;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->sc_st->back_sprite, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->sc_boss->opacity, NULL);
    sfRenderWindow_drawText(g->window, g->sc_boss->text, NULL);
    while (tmp) {
        draw_button(g, tmp);
        tmp = tmp->next;
    }
    sfRenderWindow_drawSprite(g->window, g->cursor, NULL);
    sfRenderWindow_display(g->window);
    return;
}
