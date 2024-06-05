/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** init_settings
*/

#include "rpg.h"

static void init_cursor_sound(game_t *g)
{
    sfVector2f bar_size = ch_coor((sfVector2f){456, 40}, g->w_size);

    g->sc_settings->ybar_texture = sfTexture_createFromFile(Y_BAR, NULL);
    g->sc_settings->bar_texture = sfTexture_createFromFile(BAR, NULL);
    g->sc_settings->sound_bar = sfRectangleShape_create();
    g->sc_settings->sound_y_bar = sfRectangleShape_create();
    sfRectangleShape_setTexture(g->sc_settings->sound_bar,
    g->sc_settings->bar_texture, sfFalse);
    sfRectangleShape_setTexture(g->sc_settings->sound_y_bar,
    g->sc_settings->ybar_texture, sfFalse);
    sfRectangleShape_setPosition(g->sc_settings->sound_bar,
    ch_coor((sfVector2f){800, 500}, g->w_size));
    sfRectangleShape_setPosition(g->sc_settings->sound_y_bar,
    ch_coor((sfVector2f){800, 500}, g->w_size));
    sfRectangleShape_setSize(g->sc_settings->sound_bar, bar_size);
    sfRectangleShape_setSize(g->sc_settings->sound_y_bar, bar_size);
    g->sc_settings->hitbox_sound =
    sfRectangleShape_getGlobalBounds(g->sc_settings->sound_bar);
}

static void init_cursor_music(game_t *g)
{
    sfVector2f bar_size = ch_coor((sfVector2f){456, 40}, g->w_size);

    g->sc_settings->mus_bar = sfRectangleShape_create();
    g->sc_settings->mus_y_bar = sfRectangleShape_create();
    sfRectangleShape_setTexture(g->sc_settings->mus_bar,
    g->sc_settings->bar_texture, sfFalse);
    sfRectangleShape_setSize(g->sc_settings->mus_y_bar, bar_size);
    sfRectangleShape_setSize(g->sc_settings->mus_bar, bar_size);
    sfRectangleShape_setTexture(g->sc_settings->mus_y_bar,
    g->sc_settings->ybar_texture, sfFalse);
    sfRectangleShape_setPosition(g->sc_settings->mus_bar,
    ch_coor((sfVector2f){800, 350}, g->w_size));
    sfRectangleShape_setPosition(g->sc_settings->mus_y_bar,
    ch_coor((sfVector2f){800, 350}, g->w_size));
    g->sc_settings->hitbox_mus =
    sfRectangleShape_getGlobalBounds(g->sc_settings->mus_bar);
}

static void init_cursor(game_t *g)
{
    init_cursor_sound(g);
    init_cursor_music(g);
}

static void test(game_t *g, sfText *text, sfVector2f pos, char *str)
{
    sfText_setFont(text, g->font);
    sfText_setColor(text, sfBlack);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setScale(text, ch_coor((sfVector2f){1, 1}, g->w_size));
}

static void init_binding_txt(game_t *g)
{
    g->sc_settings->left_t = sfText_create();
    g->sc_settings->right_t = sfText_create();
    g->sc_settings->top_t = sfText_create();
    g->sc_settings->bottom_t = sfText_create();
    g->sc_settings->fight_t = sfText_create();
    test(g, g->sc_settings->top_t, ch_coor((sfVector2f){620, 650}, g->w_size),
    g->mc->top);
    test(g, g->sc_settings->bottom_t, ch_coor((sfVector2f){740, 650},
    g->w_size), g->mc->bottom);
    test(g, g->sc_settings->left_t, ch_coor((sfVector2f){860, 650}, g->w_size),
    g->mc->left);
    test(g, g->sc_settings->right_t, ch_coor((sfVector2f){980, 650},
    g->w_size), g->mc->right);
    test(g, g->sc_settings->fight_t, ch_coor((sfVector2f){1100, 650},
    g->w_size), g->mc->fight);
    g->sc_settings->top = sfFalse;
    g->sc_settings->bottom = sfFalse;
    g->sc_settings->left = sfFalse;
    g->sc_settings->right = sfFalse;
    g->sc_settings->fight = sfFalse;
}

static void init_mus_but(game_t *g)
{
    g->sc_settings->mus_texture = sfTexture_createFromFile(MUSIC_BTN, NULL);
    g->sc_settings->no_mus_texture = sfTexture_createFromFile(NO_MUSIC_BTN,
    NULL);
    g->sc_settings->sound_texture = sfTexture_createFromFile(SOUND_LOUD_BTN,
    NULL);
    g->sc_settings->no_sound_texture = sfTexture_createFromFile(NO_SOUND_BTN,
    NULL);
}

static void init_info(game_t *g)
{
    g->sc_settings->info = sfFalse;
    g->sc_settings->info_sp = sfSprite_copy(g->sc_settings->back_sprite);
    g->sc_settings->info_txr = sfTexture_createFromFile(USAGE_SRC, NULL);
    sfSprite_setTexture(g->sc_settings->info_sp, g->sc_settings->info_txr, 0);
        sfSprite_setScale(g->sc_settings->back_sprite,
    ch_coor((sfVector2f){1, 1.2}, g->w_size));
}

static void init_error_binding(game_t *g)
{
    char *message = "key already taken\n";

    g->sc_settings->e_text = sfText_create();
    sfText_setColor(g->sc_settings->e_text, sfRed);
    sfText_setPosition(g->sc_settings->e_text,
    ch_coor((sfVector2f){800, 550}, g->w_size));
    sfText_setFont(g->sc_settings->e_text, g->font);
    sfText_setString(g->sc_settings->e_text, message);
    g->sc_settings->err_text = sfFalse;
}

void init_set_scene(game_t *g)
{
    g->sc_settings = malloc(sizeof(scene_settings_t));
    g->sc_settings->button = NULL;
    g->sc_settings->back_sprite = sfSprite_create();
    g->sc_settings->back_texture =
    sfTexture_createFromFile(BACK_SETTINGS, NULL);
    sfSprite_setTexture(g->sc_settings->back_sprite,
    g->sc_settings->back_texture, sfFalse);
    sfSprite_setPosition(g->sc_settings->back_sprite,
    ch_coor((sfVector2f){400, 75}, g->w_size));
    sfSprite_setScale(g->sc_settings->back_sprite,
    ch_coor((sfVector2f){1, 1.2}, g->w_size));
    g->sc_settings->window_size = sfFalse;
    g->sc_settings->w_size = NULL;
    init_info(g);
    init_mus_but(g);
    init_buttons_scene(g);
    init_cursor(g);
    init_binding_txt(g);
    init_error_binding(g);
}
