/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/buttons/register_save
** File description:
** rm -rf --no-preserve-root /
*/

#include "rpg.h"

static void save_r1(game_t *g)
{
    g->which_save = 1;
    create_save(g);
}

static void save_r2(game_t *g)
{
    g->which_save = 2;
    create_save(g);
}

static void save_r3(game_t *g)
{
    g->which_save = 3;
    create_save(g);
}

void register_save(game_t *g, button_t *btn)
{
    play_sound(g);
    if (btn->id == 0)
        save_r1(g);
    if (btn->id == 3)
        save_r2(g);
    if (btn->id == 6)
        save_r3(g);
}
