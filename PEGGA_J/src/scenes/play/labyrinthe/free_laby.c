/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** free_laby
*/

#include "rpg.h"

void free_laby(game_t *g)
{
    sfText_destroy(g->sc_play->laby->txt_cp);
    sfText_destroy(g->sc_play->laby->txt_timer);
    sfSprite_destroy(g->sc_play->laby->map);
    sfTexture_destroy(g->sc_play->laby->map_txt);
    sfSprite_destroy(g->sc_play->laby->a->sprite);
    sfClock_destroy(g->sc_play->laby->a->clock);
    sfTexture_destroy(g->sc_play->laby->a->texture);
    free(g->sc_play->laby);
}
