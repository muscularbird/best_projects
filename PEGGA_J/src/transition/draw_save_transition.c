/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** draw_save_transition
*/

#include "rpg.h"

void draw_save_scene_tr(game_t *g)
{
    button_t *tmp = g->sc_save->button;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->sc_save->back_sprite, NULL);
    draw_button(g, tmp);
    sfRenderWindow_drawSprite(g->window, g->cursor, NULL);
}
