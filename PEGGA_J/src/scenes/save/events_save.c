/*
** EPITECH PROJECT, 2024
** src/scenes/save/events_save
** File description:
** well, real programmers use ed
*/

#include "rpg.h"

void events_save_scene(game_t *g)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        eevent_button(g, g->sc_save->button, event);
        event_sound(g);
    }
}
