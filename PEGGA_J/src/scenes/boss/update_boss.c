/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** update_boss
*/

#include "rpg.h"

void update_boss(game_t *g)
{
    static int cp = 0;

    if (!cp)
        sfRenderWindow_setView(g->window, g->global_POV);
    cp++;
    g->mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPositionRenderWindow(g->window), sfFalse);
    sfSprite_setPosition(g->cursor, g->mouse_pos);
    return;
}
