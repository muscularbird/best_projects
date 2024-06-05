/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** button_pointed_function3
*/

#include "rpg.h"

void window_size(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->sc_settings->window_size = !g->sc_settings->window_size;
}

void full_screen(game_t *g, button_t *btn)
{
    sfVideoMode m = sfVideoMode_getDesktopMode();

    UNUSED(btn);
    play_sound(g);
    sfRenderWindow_close(g->window);
    g->w_size = (sfVector2f){m.width, m.height};
    g->window = sfRenderWindow_create(m, "PEGGA_J",
    sfFullscreen, NULL);
    sfRenderWindow_setMouseCursorVisible(g->window, sfFalse);
    sfRenderWindow_setFramerateLimit(g->window, 240);
    sfRectangleShape_setSize(g->opacity, g->w_size);
    sfView_setCenter(g->global_POV, (sfVector2f){m.width / 2, m.height / 2});
    sfView_setSize(g->global_POV, g->w_size);
    g->sc_pau->cp = 0;
    init_set_scene(g);
    init_pause_scene(g);
    init_start_scene(g);
    init_save_scene(g);
    init_death(g);
    g->sc_settings->window_size = sfFalse;
}

void medium_window(game_t *g, button_t *btn)
{
    sfVideoMode mode = {1280, 720, 32};

    UNUSED(btn);
    play_sound(g);
    g->w_size = (sfVector2f){1280, 720};
    sfRenderWindow_close(g->window);
    g->window = sfRenderWindow_create(mode, "PEGGA_J",
    sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(g->window, sfFalse);
    sfRenderWindow_setFramerateLimit(g->window, 240);
    sfRectangleShape_setSize(g->opacity, g->w_size);
    sfView_setCenter(g->global_POV, (sfVector2f){1280 / 2, 720 / 2});
    sfView_setSize(g->global_POV, g->w_size);
    g->sc_pau->cp = 0;
    init_set_scene(g);
    init_pause_scene(g);
    init_start_scene(g);
    init_save_scene(g);
    init_death(g);
    g->sc_settings->window_size = sfFalse;
}

void big_window(game_t *g, button_t *btn)
{
    sfVideoMode mode = {1920, 1080, 32};

    UNUSED(btn);
    play_sound(g);
    g->w_size = (sfVector2f){1920, 1080};
    sfRenderWindow_close(g->window);
    g->window = sfRenderWindow_create(mode, "PEGGA_J",
    sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(g->window, sfFalse);
    sfRenderWindow_setFramerateLimit(g->window, 240);
    sfRectangleShape_setSize(g->opacity, g->w_size);
    sfView_setCenter(g->global_POV, (sfVector2f){1920 / 2, 1080 / 2});
    sfView_setSize(g->global_POV, g->w_size);
    g->sc_pau->cp = 0;
    init_set_scene(g);
    init_pause_scene(g);
    init_start_scene(g);
    init_save_scene(g);
    init_death(g);
    g->sc_settings->window_size = sfFalse;
}
