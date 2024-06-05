/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** update_death
*/

#include "rpg.h"

void update_death(game_t *g)
{
    g->mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPositionRenderWindow(g->window), sfFalse);
    sfSprite_setPosition(g->cursor, g->mouse_pos);
}
