/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** func_scene
*/

#include "rpg.h"

void events_pause_scene(game_t *g)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        eevent_button(g, g->sc_pau->button, event);
        event_sound(g);
        if (event.key.code == sfKeyEscape && !g->sc_pau->is_pause) {
            play_sound(g);
            sfRenderWindow_setView(g->window, g->mc->POV);
            g->next_scene = PLAY;
        }
    }
}
