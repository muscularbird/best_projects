/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** draw_pet
*/

#include "rpg.h"

static void event_key(game_t *g, sfEvent event)
{
    if (event.key.code == sfKeySpace && (sfClock_getElapsedTime
    (g->clock).microseconds -
    g->sc_play->pet->time_ball.microseconds > 1000000)) {
        g->sc_play->pet->time_ball = sfClock_getElapsedTime(g->clock);
        g->sc_play->pet->move_dir = sfFalse;
        g->sc_play->pet->moving_bowl = sfTrue;
        add_bowl(g,
        sfRectangleShape_getSize(g->sc_play->pet->direction).x / 192,
        sfRectangleShape_getRotation(g->sc_play->pet->direction));
        g->sc_play->pet->move_dir = sfTrue;
    }
    if (event.key.code == sfKeyEscape) {
        g->sc_pau->is_pause = sfTrue;
        sfRenderWindow_setView(g->window, g->global_POV);
        g->next_scene = PAUSE;
    }
}

void events_petanque(game_t *g)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (event.type == sfEvtKeyPressed)
            event_key(g, event);
        if (g->sc_play->pet->life == 0) {
            free_all_mob(g);
            free_all_bullet(g);
            g->sc_play->pet->kill = 0;
        }
        if (g->sc_play->pet->kill >= 5) {
            free_all_mob(g);
            free_all_bullet(g);
        }
        eevent_button(g, g->sc_play->pet->btn, event);
    }
}
