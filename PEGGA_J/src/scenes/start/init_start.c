/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/scenes/start/init_start
** File description:
** segmentation fault (core dumped)
*/

#include "rpg.h"

static fonc_par_t buttons_s_func[] = {
    {PLAY_BTN, {0, 0}, {0, 0}, 0, &play, 0},
    {SETTINGS_BTN, {0, 0}, {0, 0}, 0, &settings_f, 1},
    {CLOSE, {0, 0}, {0, 0}, 0, &my_close, 2}
};

static void init_logo(scene_start_t *s, game_t *g)
{
    s->texture_logo = sfTexture_createFromFile(LOGO, NULL);
    s->logo = sfSprite_create();
    sfSprite_setTexture(s->logo, s->texture_logo, sfFalse);
    sfSprite_setOrigin(s->logo, (sfVector2f){197.5, 66.5});
    sfSprite_setPosition(s->logo,
    ch_coor((sfVector2f){1920 / 2, 300}, g->w_size));
    sfSprite_setScale(s->logo, ch_coor((sfVector2f){1.5, 1.5}, g->w_size));
}

static void modif_start_btn(game_t *g)
{
    buttons_s_func[0].pos = ch_coor((sfVector2f){700, 600}, g->w_size);
    buttons_s_func[0].rect_size = ch_coor((sfVector2f){150, 100}, g->w_size);
    buttons_s_func[1].pos = ch_coor((sfVector2f){950, 600}, g->w_size);
    buttons_s_func[1].rect_size = ch_coor((sfVector2f){150, 100}, g->w_size);
    buttons_s_func[2].pos = ch_coor((sfVector2f){1200, 600}, g->w_size);
    buttons_s_func[2].rect_size = ch_coor((sfVector2f){150, 100}, g->w_size);
}

void init_start_scene(game_t *g)
{
    modif_start_btn(g);
    g->sc_st = malloc(sizeof(scene_start_t));
    init_rain(g);
    init_lore(g);
    g->sc_st->back_texture = sfTexture_createFromFile(BCK_MNU, NULL);
    g->sc_st->back_sprite = sfSprite_create();
    sfSprite_setTexture(g->sc_st->back_sprite, g->sc_st->back_texture, 0);
    sfSprite_setOrigin(g->sc_st->back_sprite,
    (sfVector2f){960, 540});
    sfSprite_setPosition(g->sc_st->back_sprite,
    (sfVector2f){g->w_size.x / 2, g->w_size.y / 2});
    g->sc_st->button = NULL;
    rect_btn(&g->sc_st->button, buttons_s_func[0]);
    rect_btn(&g->sc_st->button, buttons_s_func[1]);
    rect_btn(&g->sc_st->button, buttons_s_func[2]);
    init_logo(g->sc_st, g);
}
