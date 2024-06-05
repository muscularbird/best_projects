/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** events_boss
*/

#include "rpg.h"

void events_boss(game_t *g)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        eevent_button(g, g->sc_boss->btn, event);
    }
}
