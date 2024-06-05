/*
** EPITECH PROJECT, 2024
** start/draw_start
** File description:
** don't forget to free at the end
*/

#include "rpg.h"

void draw_start_scene(game_t *g)
{
    button_t *tmp = g->sc_st->button;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->sc_st->back_sprite, sfFalse);
    for (int i = 0; i < NB_OF_RAINS_DROPS; ++i) {
        sfRenderWindow_drawPrimitives(g->window, g->sc_st->rain[i].line, 2,
        sfLines, NULL);
    }
    sfRenderWindow_drawSprite(g->window, g->sc_st->logo, NULL);
    draw_button(g, tmp);
    sfRenderWindow_drawSprite(g->window, g->cursor, sfFalse);
    sfRenderWindow_display(g->window);
}
