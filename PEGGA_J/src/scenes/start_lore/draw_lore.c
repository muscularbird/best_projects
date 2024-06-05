/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** draw_lore
*/

#include "rpg.h"

void draw_lore(game_t *g)
{
    sfRenderWindow_clear(g->window, sfBlack);
    for (int i = 0; i != 16; i++)
        sfRenderWindow_drawText(g->window, g->sc_lore->lore[i], NULL);
    sfRenderWindow_display(g->window);
}
