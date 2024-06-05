/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** func_scene
*/

#include "rpg.h"

void update_start_scene(game_t *g)
{
    update_rain(g);
    g->mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPositionRenderWindow(g->window), sfFalse);
    sfSprite_setPosition(g->cursor, g->mouse_pos);
}
