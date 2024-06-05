/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** button_pointed_funciton
*/

#include "rpg.h"

void play(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->previous_scene = g->current_scene;
    if (g->previous_scene == START) {
        fade_transition(g, SAVE, "START", "SAVE");
    } else {
        sfSprite_setScale(g->mc->inv_back,
        ch_coor((sfVector2f){0.1, 0.1}, g->w_size));
        for (int i = 0; g->mc->full_inv[i]; i++)
            sfRectangleShape_setScale(g->mc->full_inv[i], (sfVector2f){1, 1});
        g->next_scene = PLAY;
    }
}

void pause_af(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->previous_scene = g->current_scene;
    g->next_scene = PAUSE;
}

void my_close(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    sfRenderWindow_close(g->window);
}

void settings_f(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->previous_scene = g->current_scene;
    g->next_scene = SETTINGS;
}
