/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** boss
*/

#include "rpg.h"

void spawn_boss(game_t *g)
{
    pnj_t *tmp = g->pnj;

    while (tmp) {
        if (!strcmp(tmp->type, "orc") && !tmp->alive && g->mc->lvl_nb == 8) {
            tmp->alive = sfTrue;
        }
        if (!strcmp(tmp->type, "orc") && tmp->HP <= 0)
            g->current_scene = BOSS;
        tmp = tmp->next;
    }
}
