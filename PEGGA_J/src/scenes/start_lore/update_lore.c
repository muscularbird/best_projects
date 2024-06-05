/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** update_lore
*/

#include "rpg.h"

void update_lore(game_t *g)
{
    float sec = sfClock_restart(g->clock).microseconds / MILION;
    sfVector2f pos_txt = {0, 0};

    for (int i = 0; i != 16; i++) {
        pos_txt = sfText_getPosition(g->sc_lore->lore[i]);
        sfText_setPosition(g->sc_lore->lore[i],
        ch_coor((sfVector2f){pos_txt.x, pos_txt.y - 70 * sec}, g->w_size));
    }
    pos_txt = sfText_getPosition(g->sc_lore->lore[15]);
    if (pos_txt.y <= 0)
        fade_transition(g, START, "LORE", "START");
}
