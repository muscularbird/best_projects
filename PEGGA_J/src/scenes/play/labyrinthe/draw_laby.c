/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** draw_laby
*/

#include "rpg.h"

void draw_laby(game_t *g)
{
    sfRenderWindow_clear(g->window, sfWhite);
    sfRenderWindow_drawSprite(g->window, g->sc_play->laby->map, NULL);
    sfRenderWindow_drawSprite(g->window, g->sc_play->laby->a->sprite, NULL);
    sfRenderWindow_drawText(g->window, g->sc_play->laby->txt_timer, NULL);
    sfRenderWindow_drawText(g->window, g->sc_play->laby->txt_cp, NULL);
    sfRenderWindow_drawSprite(g->window, g->cursor, NULL);
    sfRenderWindow_display(g->window);
}
