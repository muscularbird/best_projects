/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/scenes/pause/draw
** File description:
** code on paper!
*/

#include "rpg.h"

void draw_pause_scene(game_t *g)
{
    button_t *tmp = g->sc_pau->button;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->sc_st->back_sprite, sfFalse);
    sfRenderWindow_drawRectangleShape(g->window, g->opacity, sfFalse);
    sfRenderWindow_drawSprite(g->window, g->sc_pau->bck_stat, sfFalse);
    sfRenderWindow_drawSprite(g->window, g->sc_pau->bck_inv, sfFalse);
    sfRenderWindow_drawText(g->window, g->sc_pau->stat, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(g->window, g->sc_pau->stats[i], NULL);
    sfRenderWindow_drawText(g->window, g->sc_pau->quest, NULL);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawText(g->window, g->sc_pau->quests[i], NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->sc_pau->outline_name, ZO);
    sfRenderWindow_drawText(g->window, g->sc_pau->name, NULL);
    draw_inv(g);
    draw_button(g, tmp);
    sfRenderWindow_drawSprite(g->window, g->sc_pau->mc, sfFalse);
    sfRenderWindow_drawSprite(g->window, g->cursor, sfFalse);
    sfRenderWindow_display(g->window);
}
