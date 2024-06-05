/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** init_boss
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

void init_boss(game_t *g)
{
    char const *str = "CONGRATULATIONS ! YOU ESCAPED";
    sfColor c = sfColor_fromRGBA(0, 0, 60, 200);

    g->sc_boss = malloc(sizeof(boss_sc_t));
    g->sc_boss->btn = NULL;
    g->sc_boss->text = sfText_create();
    sfText_setFont(g->sc_boss->text, g->font);
    sfText_setString(g->sc_boss->text, str);
    sfText_setColor(g->sc_boss->text, sfBlack);
    sfText_setScale(g->sc_boss->text, ch_coor((sfVector2f){2, 2}, g->w_size));
    sfText_setPosition(g->sc_boss->text,
    ch_coor((sfVector2f){330, 180}, g->w_size));
    g->sc_boss->opacity = sfRectangleShape_create();
    sfRectangleShape_setFillColor(g->sc_boss->opacity, c);
    sfRectangleShape_setSize(g->sc_boss->opacity, (sfVector2f){1920, 1080});
    sfRectangleShape_setPosition(g->sc_boss->opacity, (sfVector2f){0, 0});
    modif_funcs_btn(g);
    rect_btn(&g->sc_boss->btn, buttons_func[0]);
    rect_btn(&g->sc_boss->btn, buttons_func[1]);
}
