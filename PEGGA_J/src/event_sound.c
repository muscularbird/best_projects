/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** event_sound
*/

#include "rpg.h"

void play_sound(game_t *g)
{
    sfMusic_play(g->music->sound);
    g->music->start_time = sfClock_getElapsedTime(g->clock);
    g->click = sfTrue;
}

void event_sound(game_t *g)
{
    if (sfClock_getElapsedTime(g->clock).microseconds -
    g->music->start_time.microseconds >
    sfMusic_getDuration(g->music->sound).microseconds && g->click == sfTrue) {
        sfMusic_stop(g->music->sound);
        g->click = sfFalse;
    }
}
