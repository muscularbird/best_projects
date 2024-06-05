/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** init_death
*/

#include "rpg.h"

static fonc_par_t buttons_func[] = {
    {RETRY, {0, 0}, {0, 0}, 0, &restart, 0},
    {CLOSE, {0, 0}, {0, 0}, 0, &my_close, 1}
};

static void modif_funcs_btn(game_t *g)
{
    buttons_func[0].pos = (sfVector2f){g->w_size.x / 2 - 100, g->w_size.y / 2};
    buttons_func[0].rect_size = ch_coor((sfVector2f){150, 150}, g->w_size);
    buttons_func[1].pos = (sfVector2f){g->w_size.x / 2 + 100, g->w_size.y / 2};
    buttons_func[1].rect_size = ch_coor((sfVector2f){150, 150}, g->w_size);
}

void init_death(game_t *g)
{
    char const *str = "YOU ARE DEAD";
    sfColor c = sfColor_fromRGBA(180, 0, 0, 200);

    g->dth_sc = malloc(sizeof(dth_sc_t));
    g->dth_sc->btn = NULL;
    g->dth_sc->text = sfText_create();
    sfText_setFont(g->dth_sc->text, g->font);
    sfText_setString(g->dth_sc->text, str);
    sfText_setColor(g->dth_sc->text, sfBlack);
    sfText_setScale(g->dth_sc->text, ch_coor((sfVector2f){4, 4}, g->w_size));
    sfText_setPosition(g->dth_sc->text,
    ch_coor((sfVector2f){460, 180}, g->w_size));
    g->dth_sc->opacity = sfRectangleShape_create();
    sfRectangleShape_setFillColor(g->dth_sc->opacity, c);
    sfRectangleShape_setSize(g->dth_sc->opacity, (sfVector2f){1920, 1080});
    sfRectangleShape_setPosition(g->dth_sc->opacity, (sfVector2f){0, 0});
    modif_funcs_btn(g);
    rect_btn(&g->dth_sc->btn, buttons_func[0]);
    rect_btn(&g->dth_sc->btn, buttons_func[1]);
}
