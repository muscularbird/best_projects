/*
** EPITECH PROJECT, 2024
** src/scenes/settings/draw_settings
** File description:
** :wq
*/

#include "rpg.h"

static void draw_text(game_t *g)
{
    if (g->sc_settings->err_text)
        sfRenderWindow_drawText(g->window, g->sc_settings->e_text, sfFalse);
    sfRenderWindow_drawText(g->window, g->sc_settings->left_t, sfFalse);
    sfRenderWindow_drawText(g->window, g->sc_settings->right_t, sfFalse);
    sfRenderWindow_drawText(g->window, g->sc_settings->top_t, sfFalse);
    sfRenderWindow_drawText(g->window, g->sc_settings->bottom_t, sfFalse);
    sfRenderWindow_drawText(g->window, g->sc_settings->fight_t, sfFalse);
}

static void draw_cursor(game_t *g)
{
    sfRenderWindow_drawRectangleShape(g->window,
    g->sc_settings->sound_y_bar, sfFalse);
    sfRenderWindow_drawRectangleShape(g->window,
    g->sc_settings->sound_bar, sfFalse);
    sfRenderWindow_drawRectangleShape(g->window,
    g->sc_settings->mus_y_bar, sfFalse);
    sfRenderWindow_drawRectangleShape(g->window,
    g->sc_settings->mus_bar, sfFalse);
}

void draw_set_scene(game_t *g)
{
    button_t *tmp = g->sc_settings->button;
    button_t *tmp_w = g->sc_settings->w_size;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->sc_st->back_sprite, sfFalse);
    sfRenderWindow_drawRectangleShape(g->window, g->opacity, sfFalse);
    sfRenderWindow_drawSprite(g->window,
    g->sc_settings->back_sprite, sfFalse);
    draw_cursor(g);
    draw_button(g, tmp);
    if (g->sc_settings->window_size)
        draw_button(g, tmp_w);
    draw_text(g);
    if (g->sc_settings->info)
        sfRenderWindow_drawSprite(g->window,
    g->sc_settings->info_sp, sfFalse);
    sfRenderWindow_drawSprite(g->window, g->cursor, sfFalse);
    sfRenderWindow_display(g->window);
}
