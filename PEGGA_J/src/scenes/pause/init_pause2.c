/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** init_pause2
*/

#include "rpg.h"

void init_sai4(game_t *g)
{
    g->sc_pau->name = sfText_create();
    sfText_setFont(g->sc_pau->name, g->font);
    sfText_setString(g->sc_pau->name, "MERJ SIMPSON");
    sfText_setPosition(g->sc_pau->name,
    ch_coor((sfVector2f){1462, 125}, g->w_size));
    sfText_setScale(g->sc_pau->name,
    ch_coor((sfVector2f){1, 1}, g->w_size));
    g->sc_pau->cp = 0;
}

void init_sai3(game_t *g)
{
    g->sc_pau->bck_inv = sfSprite_copy(g->sc_pau->bck_stat);
    sfSprite_setPosition(g->sc_pau->bck_inv,
    ch_coor((sfVector2f){1380, 50}, g->w_size));
    g->sc_pau->mc = sfSprite_copy(g->mc->animation->sprite);
    sfSprite_setPosition(g->sc_pau->mc,
    ch_coor((sfVector2f){1600, 340}, g->w_size));
    sfSprite_setScale(g->sc_pau->mc, ch_coor((sfVector2f){8, 8}, g->w_size));
    g->sc_pau->outline_name = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(g->sc_pau->outline_name, sfWhite);
    sfRectangleShape_setFillColor(g->sc_pau->outline_name, sfTransparent);
    sfRectangleShape_setPosition(g->sc_pau->outline_name,
    ch_coor((sfVector2f){1424, 110}, g->w_size));
    sfRectangleShape_setOutlineThickness(g->sc_pau->outline_name, 2.0);
    sfRectangleShape_setSize(g->sc_pau->outline_name,
    ch_coor((sfVector2f){350, 70}, g->w_size));
    init_sai4(g);
}
