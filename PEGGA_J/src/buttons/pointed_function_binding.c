/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** pointed_function_binding
*/

#include "rpg.h"

void binding_left(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->sc_settings->left = sfTrue;
}

void binding_right(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->sc_settings->right = sfTrue;
}

void binding_top(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->sc_settings->top = sfTrue;
}

void binding_bottom(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->sc_settings->bottom = sfTrue;
}

void binding_fight(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->sc_settings->fight = sfTrue;
}
