/*
** EPITECH PROJECT, 2024
** src/scenes/settings/init_buttons_settings
** File description:
** epitech > epita
*/

#include "rpg.h"

static fonc_par_t buttons_func[] = {
    {WDW_SIZE, {0, 0}, {0, 0}, 0, &window_size, 0},
    {FULLSCREEN, {0, 0}, {0, 0}, 0, &full_screen, 1},
    {MEDIUM_WDW, {0, 0}, {0, 0}, 0, &medium_window, 2},
    {BIG_WDW, {0, 0}, {0, 0}, 0, &big_window, 3},
    {TOP, {0, 0}, {0, 0}, 0, &binding_top, 4},
    {BOTTOM, {0, 0}, {0, 0}, 0, &binding_bottom, 5},
    {LEFT, {0, 0}, {0, 0}, 0, &binding_left, 6},
    {RIGHT, {0, 0}, {0, 0}, 0, &binding_right, 7},
    {FIGHT_IMG, {0, 0}, {0, 0}, 0, &binding_fight, 8},
    {CLOSE, {0, 0}, {0, 0}, 0, &close_settings, 9},
    {INFO_BTN, {0, 0}, {0, 0}, 0, &info_f, 10},
    {NO_MUSIC_BTN, {0, 0}, {0, 0}, 0, &no_music_f, 11},
    {SOUND_LOUD_BTN, {0, 0}, {0, 0}, 0, &no_sound_f, 12},
    {SAVE_BTN, {0, 0}, {0, 0}, 0, &menu_save, 13}
};

static void modif_funcs_btn2(game_t *g)
{
    buttons_func[7].pos = ch_coor((sfVector2f){1010, 650}, g->w_size);
    buttons_func[7].rect_size = ch_coor((sfVector2f){100, 100}, g->w_size);
    buttons_func[8].pos = ch_coor((sfVector2f){1130, 650}, g->w_size);
    buttons_func[8].rect_size = ch_coor((sfVector2f){100, 100}, g->w_size);
    buttons_func[9].pos = ch_coor((sfVector2f){1410, 140}, g->w_size);
    buttons_func[9].rect_size = ch_coor((sfVector2f){150, 140}, g->w_size);
    buttons_func[10].pos = ch_coor((sfVector2f){575, 800}, g->w_size);
    buttons_func[10].rect_size = ch_coor((sfVector2f){100, 75}, g->w_size);
    buttons_func[11].pos = ch_coor((sfVector2f){600, 350}, g->w_size);
    buttons_func[11].rect_size = ch_coor((sfVector2f){150, 100}, g->w_size);
    buttons_func[12].pos = ch_coor((sfVector2f){600, 500}, g->w_size);
    buttons_func[12].rect_size = ch_coor((sfVector2f){150, 100}, g->w_size);
}

static void modif_funcs_btn(game_t *g)
{
    buttons_func[0].pos = ch_coor((sfVector2f){850, 775}, g->w_size);
    buttons_func[0].rect_size = ch_coor((sfVector2f){200, 75}, g->w_size);
    buttons_func[1].pos = ch_coor((sfVector2f){750, 850}, g->w_size);
    buttons_func[1].rect_size = ch_coor((sfVector2f){150, 75}, g->w_size);
    buttons_func[2].pos = ch_coor((sfVector2f){910, 850}, g->w_size);
    buttons_func[2].rect_size = ch_coor((sfVector2f){150, 75}, g->w_size);
    buttons_func[3].pos = ch_coor((sfVector2f){1070, 850}, g->w_size);
    buttons_func[3].rect_size = ch_coor((sfVector2f){150, 75}, g->w_size);
    buttons_func[4].pos = ch_coor((sfVector2f){650, 650}, g->w_size);
    buttons_func[4].rect_size = ch_coor((sfVector2f){100, 100}, g->w_size);
    buttons_func[5].pos = ch_coor((sfVector2f){770, 650}, g->w_size);
    buttons_func[5].rect_size = ch_coor((sfVector2f){100, 100}, g->w_size);
    buttons_func[6].pos = ch_coor((sfVector2f){890, 650}, g->w_size);
    buttons_func[6].rect_size = ch_coor((sfVector2f){100, 100}, g->w_size);
    modif_funcs_btn2(g);
}

void init_buttons_scene(game_t *g)
{
    modif_funcs_btn(g);
    rect_btn(&g->sc_settings->button, buttons_func[0]);
    rect_btn(&g->sc_settings->w_size, buttons_func[1]);
    rect_btn(&g->sc_settings->w_size, buttons_func[2]);
    rect_btn(&g->sc_settings->w_size, buttons_func[3]);
    rect_btn(&g->sc_settings->button, buttons_func[4]);
    rect_btn(&g->sc_settings->button, buttons_func[5]);
    rect_btn(&g->sc_settings->button, buttons_func[6]);
    rect_btn(&g->sc_settings->button, buttons_func[7]);
    rect_btn(&g->sc_settings->button, buttons_func[8]);
    rect_btn(&g->sc_settings->button, buttons_func[9]);
    rect_btn(&g->sc_settings->button, buttons_func[10]);
    rect_btn(&g->sc_settings->button, buttons_func[11]);
    rect_btn(&g->sc_settings->button, buttons_func[12]);
}
