/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** button_pointed_function2
*/

#include "rpg.h"

void close_settings(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    if (g->sc_settings->info) {
        g->sc_settings->info = !g->sc_settings->info;
        return;
    }
    g->current_scene = g->previous_scene;
    if (g->previous_scene == START)
        g->next_scene = START;
    else
        g->next_scene = PAUSE;
}

static void no_music_f2(game_t *g, button_t *btn)
{
    play_sound(g);
    sfRectangleShape_setTexture(btn->rect,
    g->sc_settings->no_mus_texture, sfFalse);
    g->music->music_volume = g->music->prev_vol;
    sfMusic_setVolume(g->music->main_music, g->music->music_volume);
    sfRectangleShape_setSize(g->sc_settings->mus_bar,
    (sfVector2f){((456 * g->w_size.x / 1920) * g->music->prev_vol) /
    100, (40 * g->w_size.y / 1080)});
}

void no_music_f(game_t *g, button_t *btn)
{
    float tmp = 0.0;

    if (g->music->music_volume != 0.0) {
        play_sound(g);
        sfRectangleShape_setTexture(btn->rect,
        g->sc_settings->mus_texture, sfFalse);
        tmp = g->music->music_volume;
        g->music->prev_vol = tmp;
        g->music->music_volume = 0.0;
        sfMusic_setVolume(g->music->main_music, g->music->music_volume);
        sfRectangleShape_setSize(g->sc_settings->mus_bar,
        (sfVector2f){0, 40});
    } else {
        no_music_f2(g, btn);
    }
}

void no_sound_f(game_t *g, button_t *btn)
{
    float tmp = 0.0;

    if (g->music->sound_volume != 0.0) {
        sfRectangleShape_setTexture(btn->rect,
        g->sc_settings->sound_texture, sfFalse);
        tmp = g->music->sound_volume;
        g->music->prev_sound_vol = tmp;
        g->music->sound_volume = 0.0;
        sfMusic_setVolume(g->music->sound, g->music->sound_volume);
        sfRectangleShape_setSize(g->sc_settings->sound_bar,
        (sfVector2f){0, 40});
    } else {
        sfRectangleShape_setTexture(btn->rect,
        g->sc_settings->no_sound_texture, sfFalse);
        g->music->sound_volume = g->music->prev_sound_vol;
        sfMusic_setVolume(g->music->sound, g->music->sound_volume);
        sfRectangleShape_setSize(g->sc_settings->sound_bar,
        (sfVector2f){((456 * g->w_size.x / 1920) * g->music->prev_sound_vol) /
        100, (40 * g->w_size.y / 1080)});
    }
}

void info_f(game_t *g, button_t *btn)
{
    UNUSED(btn);
    g->sc_settings->info = sfTrue;
    return;
}
