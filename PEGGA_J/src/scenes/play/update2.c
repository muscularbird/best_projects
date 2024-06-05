/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** update2
*/

#include "rpg.h"

static int tab_len(sfRectangleShape **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}

void update_archi_quest(game_t *g)
{
    if (g->sc_play->current_quest == 5 && tab_len(g->mc->full_inv) == 5) {
        g->mc->lvl_nb++;
        g->sc_play->current_quest = 6;
    }
}
