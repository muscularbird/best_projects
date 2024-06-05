/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/buttons/del_save
** File description:
** no, real programmers use cat
*/

#include "rpg.h"

static void del_save1(game_t *g)
{
    g->which_save = 1;
    delete_save(g);
}

static void del_save2(game_t *g)
{
    g->which_save = 2;
    delete_save(g);
}

static void del_save3(game_t *g)
{
    g->which_save = 3;
    delete_save(g);
}

void del_save(game_t *g, button_t *btn)
{
    play_sound(g);
    if (btn->id == 2)
        del_save1(g);
    if (btn->id == 5)
        del_save2(g);
    if (btn->id == 8)
        del_save3(g);
}
