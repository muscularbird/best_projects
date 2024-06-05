/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** init_rain
*/

#include "rpg.h"

void init_rain(game_t *g)
{
    srand(time(NULL));
    for (int i = 0; i < NB_OF_RAINS_DROPS; ++i) {
        g->sc_st->rain[i].speed = 0.0;
        g->sc_st->rain[i].line[0].color = sfWhite;
        g->sc_st->rain[i].line[1].color = sfWhite;
        g->sc_st->rain[i].line[0].position.x =
        (float)(rand() % (int)(g->w_size.x));
        g->sc_st->rain[i].line[0].position.y =
        (float)(rand() % (int)(g->w_size.y));
        g->sc_st->rain[i].line[1].position.x =
        g->sc_st->rain[i].line[0].position.x;
        g->sc_st->rain[i].line[1].position.y =
        g->sc_st->rain[i].line[0].position.y + 10;
        g->sc_st->rain[i].speed = (float)(rand() % 5) + 1;
    }
}

void update_rain(game_t *g)
{
    for (int i = 0; i < NB_OF_RAINS_DROPS; ++i) {
        g->sc_st->rain[i].line[0].position.y += g->sc_st->rain[i].speed;
        g->sc_st->rain[i].line[1].position.y += g->sc_st->rain[i].speed;
        if (g->sc_st->rain[i].line[0].position.y > g->w_size.y) {
            g->sc_st->rain[i].line[0].position.y = -10;
            g->sc_st->rain[i].line[1].position.y = 0;
        }
    }
}
