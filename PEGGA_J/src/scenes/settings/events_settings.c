/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** func_settings_scene
*/

#include "rpg.h"
#include "keycode.h"

static void which_keychar(sfEvent event, game_t *g, sfText *txt)
{
    UNUSED(g);
    for (int i = 0; i != NUM_KEY_CODES; i++) {
        if (event.key.code == all_key_codes[i]) {
            sfText_setString(txt, key_letters[i]);
            return;
        }
    }
}

static void event_key(game_t *g)
{
    if (g->event.key.code == sfKeyEscape)
        g->next_scene = PAUSE;
}

static void event_cursor(game_t *g, sfEvent event)
{
    sfVector2f s_pos = sfRectangleShape_getPosition(g->sc_settings->sound_bar);
    float dif_so = 0.0;
    float sound_pos = sfRectangleShape_getSize(g->sc_settings->sound_bar).y;

    UNUSED(event);
    g->music->sound_volume = sfRectangleShape_getSize(
    g->sc_settings->sound_bar).x * 100 /
    ch_coor((sfVector2f){456, 0}, g->w_size).x;
    event_cursor_music(g);
    dif_so = g->mouse_pos.x - s_pos.x;
    if (g->sc_settings->pressed && sfFloatRect_contains
    (&g->sc_settings->hitbox_sound, g->mouse_pos.x, g->mouse_pos.y)) {
        sfRectangleShape_setSize(
        g->sc_settings->sound_bar, (sfVector2f){dif_so, sound_pos});
        g->music->prev_sound_vol = g->music->sound_volume;
        sfMusic_setVolume(g->music->sound, g->music->sound_volume);
    }
}

static int ch_bind(sfEvent event, game_t *g)
{
    if (event.key.code != g->mc->topkey && event.key.code != g->mc->botkey
    && event.key.code != g->mc->leftkey && event.key.code != g->mc->rightkey
    && event.key.code != g->mc->fightkey) {
        g->sc_settings->err_text = sfFalse;
        return 1;
    }
    g->sc_settings->err_text = sfTrue;
    return 0;
}

static void event_binding2(game_t *g, sfEvent event, char c)
{
    UNUSED(c);
    if (g->sc_settings->top && ch_bind(event, g)) {
        g->mc->topkey = event.key.code;
        which_keychar(event, g, g->sc_settings->top_t);
        g->sc_settings->top = sfFalse;
    }
    if (g->sc_settings->bottom && ch_bind(event, g)) {
        g->mc->botkey = event.key.code;
        which_keychar(event, g, g->sc_settings->bottom_t);
        g->sc_settings->bottom = sfFalse;
    }
    if (g->sc_settings->fight && ch_bind(event, g)) {
        g->mc->fightkey = event.key.code;
        which_keychar(event, g, g->sc_settings->fight_t);
        g->sc_settings->fight = sfFalse;
    }
}

static void event_binding(game_t *g, sfEvent event)
{
    char c = 0;

    if (event.type == sfEvtKeyPressed) {
        if (g->sc_settings->left && ch_bind(event, g)) {
            g->mc->leftkey = event.key.code;
            which_keychar(event, g, g->sc_settings->left_t);
            g->sc_settings->left = sfFalse;
        }
        if (g->sc_settings->right && ch_bind(event, g)) {
            g->mc->rightkey = event.key.code;
            which_keychar(event, g, g->sc_settings->right_t);
            g->sc_settings->right = sfFalse;
        }
        event_binding2(g, event, c);
    }
    event_sound(g);
}

void events_set_scene(game_t *g)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (event.type == sfEvtKeyPressed)
            event_key(g);
        eevent_button(g, g->sc_settings->button, event);
        eevent_button(g, g->sc_settings->w_size, event);
        if (event.type == sfEvtMouseButtonPressed) {
            g->sc_settings->pressed = sfTrue;
            g->sc_settings->released = sfFalse;
        }
        if (event.type == sfEvtMouseButtonReleased) {
            g->sc_settings->pressed = sfFalse;
            g->sc_settings->released = sfTrue;
        }
        event_binding(g, event);
        event_cursor(g, event);
    }
}
