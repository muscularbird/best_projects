/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** infos
*/

#include "rpg.h"

void update_mainchar_infos2(game_t *g)
{
    static int previous_lvl = 1;

    if (g->sc_play->current_quest >= 6) {
        g->sc_play->final_boss = sfTrue;
        g->sc_play->current_quest = 8;
    }
    if (g->mc->hp_nb <= 0) {
        sfRenderWindow_setView(g->window, g->global_POV);
        g->current_scene = DEATH;
    }
    if (previous_lvl < g->mc->lvl_nb) {
        g->mc->AD += 10;
        g->mc->speed += 10.0;
    }
    spawn_boss(g);
    previous_lvl = g->mc->lvl_nb;
}

void update_mainchar_infos(game_t *g)
{
    char str[24];

    sfText_setPosition(g->mc->lvl,
    (sfVector2f){g->mc->pos.x + 150, g->mc->pos.y - 110});
    sfText_setPosition(g->mc->hp,
    (sfVector2f){g->mc->pos.x - 97, g->mc->pos.y - 99});
    sfRectangleShape_setPosition(g->mc->lifebar,
    (sfVector2f){g->mc->pos.x - 180, g->mc->pos.y - 100});
    sfRectangleShape_setPosition(g->mc->bck_lifebar,
    (sfVector2f){g->mc->pos.x - 180, g->mc->pos.y - 100});
    sfRectangleShape_setSize(g->mc->lifebar,
    (sfVector2f){g->mc->hp_nb * 0.5, 10});
    sprintf(str, "Lvl %d", g->mc->lvl_nb);
    sfText_setString(g->mc->lvl, str);
    sprintf(str, "%d", g->mc->hp_nb);
    sfText_setString(g->mc->hp, str);
    update_mainchar_infos2(g);
}
