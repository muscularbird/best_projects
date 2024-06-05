/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** draw_start_transition
*/

#include "rpg.h"

void draw_lore_tr(game_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    for (int i = 0; i != 16; i++)
        sfRenderWindow_drawText(g->window, g->sc_lore->lore[i], NULL);
}

void draw_start_scene_tr(game_t *g)
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
}
