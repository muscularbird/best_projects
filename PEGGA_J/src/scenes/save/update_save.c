/*
** EPITECH PROJECT, 2024
** src/scenes/save/update_save
** File description:
** C-x C-c
*/

#include "rpg.h"

void update_save_scene(game_t *g)
{
    g->mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPositionRenderWindow(g->window), sfFalse);
    sfSprite_setPosition(g->cursor, g->mouse_pos);
    if (g->previous_scene == START) {
        disable_button(&g->sc_save->button, 0);
        disable_button(&g->sc_save->button, 3);
        disable_button(&g->sc_save->button, 6);
    } else {
        enable_button(&g->sc_save->button, 0);
        enable_button(&g->sc_save->button, 3);
        enable_button(&g->sc_save->button, 6);
    }
}
