/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** draw_play2
*/

#include "rpg.h"

void draw_ennemies3(game_t *g, pnj_t *tmp)
{
    orientation(tmp->anim->sprite, tmp->cu_pos, g->mc->pos, tmp->k);
    sfRenderWindow_drawRectangleShape(g->window, tmp->bck_lifebar, 0);
    sfRenderWindow_drawRectangleShape(g->window, tmp->lifebar, NULL);
}
