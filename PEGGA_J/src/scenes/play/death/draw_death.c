/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** draw_death
*/

#include "rpg.h"

void draw_death(game_t *g)
{
    button_t *tmp = g->dth_sc->btn;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->sc_st->back_sprite, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->dth_sc->opacity, NULL);
    sfRenderWindow_drawText(g->window, g->dth_sc->text, NULL);
    while (tmp) {
        draw_button(g, tmp);
        tmp = tmp->next;
    }
    sfRenderWindow_drawSprite(g->window, g->cursor, NULL);
    sfRenderWindow_display(g->window);
    return;
}
