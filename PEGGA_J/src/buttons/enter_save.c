/*
** EPITECH PROJECT, 2024
** src/buttons/save_buttons
** File description:
** epitech > 42
*/

#include "rpg.h"

static void save1(game_t *g)
{
    g->which_save = 1;
    open_save(g);
    init_objects(g);
    init_pnj(g);
    g->previous_scene = g->current_scene;
    fade_transition(g, PLAY, "SAVE", "PLAY");
}

static void save2(game_t *g)
{
    g->which_save = 2;
    open_save(g);
    init_objects(g);
    init_pnj(g);
    g->previous_scene = g->current_scene;
    fade_transition(g, PLAY, "SAVE", "PLAY");
}

static void save3(game_t *g)
{
    g->which_save = 3;
    open_save(g);
    init_objects(g);
    init_pnj(g);
    g->previous_scene = g->current_scene;
    fade_transition(g, PLAY, "SAVE", "PLAY");
}

void enter_save(game_t *g, button_t *btn)
{
    play_sound(g);
    if (btn->id == 1)
        save1(g);
    if (btn->id == 4)
        save2(g);
    if (btn->id == 7)
        save3(g);
}

void menu_save(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->previous_scene = g->current_scene;
    fade_transition(g, SAVE, "PLAY", "SAVE");
}
