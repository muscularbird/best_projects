/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** func_settings2
*/

#include "rpg.h"

void event_cursor_music(game_t *g)
{
    sfVector2f b_pos = sfRectangleShape_getPosition(g->sc_settings->mus_bar);
    float dif = 0.0;
    float mus_pos = sfRectangleShape_getSize(g->sc_settings->mus_bar).y;

    g->music->music_volume = (sfRectangleShape_getSize(
    g->sc_settings->mus_bar).x * g->w_size.x / 1920) * 100 /
    ch_coor((sfVector2f){456, 0}, g->w_size).x;
    dif = g->mouse_pos.x - b_pos.x;
    if (g->sc_settings->pressed && sfFloatRect_contains
    (&g->sc_settings->hitbox_mus, g->mouse_pos.x, g->mouse_pos.y)) {
        sfRectangleShape_setSize(
        g->sc_settings->mus_bar, (sfVector2f){dif, mus_pos});
        g->music->prev_vol = g->music->music_volume;
        sfMusic_setVolume(g->music->main_music, g->music->music_volume);
    }
}

void update_set_scene(game_t *g)
{
    g->mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPositionRenderWindow(g->window), sfFalse);
    sfSprite_setPosition(g->cursor, g->mouse_pos);
}
