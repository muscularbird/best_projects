/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/scenes/start/events_start
** File description:
** r/ProgrammerHumor
*/

#include "rpg.h"

void events_start_scene(game_t *g)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        eevent_button(g, g->sc_st->button, event);
        event_sound(g);
    }
}
