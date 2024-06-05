/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** events_lore
*/

#include "rpg.h"

void events_lore(game_t *g)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (event.key.code == sfKeySpace)
            g->next_scene = START;
    }
}
