/*
** EPITECH PROJECT, 2024
** events_skate
** File description:
** r/ProgrammerHumor
*/

#include "rpg.h"

void events_skate(game_t *g)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            g->sc_pau->is_pause = sfTrue;
            sfRenderWindow_setView(g->window, g->global_POV);
            g->current_scene = PAUSE;
        }
        if (!g->sc_play->sk->alive) {
            eevent_button(g, g->sc_play->sk->btn, event);
        }
    }
}
