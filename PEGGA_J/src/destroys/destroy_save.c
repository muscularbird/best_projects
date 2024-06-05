/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/destroys/destroy_save
** File description:
** you're a bad developer
*/

#include "rpg.h"

void free_save_scene(game_t *g)
{
    free_buttons(&g->sc_save->button);
    sfSprite_destroy(g->sc_save->back_sprite);
    free(g->sc_save);
}
