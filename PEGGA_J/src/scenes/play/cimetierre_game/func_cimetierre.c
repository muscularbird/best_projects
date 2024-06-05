/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** func_cimetierre
*/

#include "rpg.h"

static int check_ennemy(game_t *g)
{
    pnj_t *tmp = g->sc_play->cimetierre;
    int killed = 0;

    while (tmp != NULL) {
        if (!tmp->alive)
            killed++;
        tmp = tmp->next;
    }
    if (killed == 7)
        g->sc_play->cimetierre_end = 1;
    return killed;
}

void events_cimetierre2(game_t *g, int *spawn, int skeleton_killed)
{
    static int i = 0;

    if (skeleton_killed == 3 && *spawn == 3) {
        add_pnj(&g->sc_play->cimetierre,
            "1553 537 0.08 170 1.0 skeleton 100 1", g);
        add_pnj(&g->sc_play->cimetierre,
            "1680 513 0.08 170 1.0 skeleton 100 1", g);
        add_pnj(&g->sc_play->cimetierre,
            "1713 656 0.08 170 1.0 skeleton 100 1", g);
        add_pnj(&g->sc_play->cimetierre,
            "1521 656 0.08 170 1.0 skeleton 100 1", g);
        *spawn = 7;
    }
    if (g->sc_play->cimetierre_end && !i) {
        g->mc->lvl_nb++;
        g->sc_play->current_quest++;
        i++;
    }
    return;
}

void events_cimetierre(game_t *g)
{
    static int spawn = 0;
    int skeleton_killed = check_ennemy(g);

    if (spawn == 0 &&
        g->mc->pos.x >= 1487 && (g->mc->pos.y >= 561 && g->mc->pos.y <= 610)) {
        add_pnj(&g->sc_play->cimetierre,
            "1651 633 0.08 170 1.0 skeleton 100 1", g);
        spawn = 1;
    }
    if (skeleton_killed == 1 && spawn == 1) {
        add_pnj(&g->sc_play->cimetierre,
            "1553 611 0.08 170 1.0 skeleton 100 1", g);
        add_pnj(&g->sc_play->cimetierre,
            "1619 562 0.08 170 1.0 skeleton 100 1", g);
        spawn = 3;
    }
    events_cimetierre2(g, &spawn, skeleton_killed);
    return;
}
