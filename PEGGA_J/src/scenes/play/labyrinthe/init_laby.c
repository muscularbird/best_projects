/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** init_laby
*/

#include "rpg.h"

static void init_laby2(laby_t *p, game_t *g)
{
    sfSprite_setTexture(p->map, p->map_txt, 0);
    sfSprite_setOrigin(p->map, (sfVector2f){1920 / 2, 1080 / 2});
    sfSprite_setPosition(p->map, g->mc->pos);
    p->x = sfTexture_getSize(p->map_txt).x / 2;
    p->y = sfTexture_getSize(p->map_txt).y / 2;
    p->txt_cp = sfText_create();
    p->cp = 0;
    sfText_setPosition(p->txt_cp,
    (sfVector2f){g->mc->pos.x - 900, g->mc->pos.y - 530});
    sfText_setScale(p->txt_cp, (sfVector2f){1.3, 1.3});
    sfText_setString(p->txt_cp, "0.00");
    sfText_setFillColor(p->txt_cp, sfBlack);
    sfText_setFont(p->txt_cp, g->font);
    p->my = (sfVector2f){g->mc->pos.y - p->y + 250, g->mc->pos.y + p->y - 250};
    p->mx = (sfVector2f){g->mc->pos.x - p->x + 250, g->mc->pos.x + p->x - 250};
    p->pos.y = rand() % (int)(p->my.y - p->my.x + 1) + p->my.x;
    p->pos.x = rand() % (int)(p->mx.y - p->mx.x + 1) + p->mx.x;
}

void init_laby(game_t *g)
{
    laby_t *p = malloc(sizeof(laby_t));

    p->map_txt = sfTexture_createFromFile(MAP_LABY, NULL);
    p->map = sfSprite_create();
    p->pov = sfView_create();
    p->a = create_animation(BAT);
    p->txt_timer = sfText_create();
    sfText_setPosition(p->txt_timer,
    (sfVector2f){g->mc->pos.x + 620, g->mc->pos.y - 530});
    sfText_setScale(p->txt_timer, (sfVector2f){1.3, 1.3});
    sfText_setString(p->txt_timer, "0.00");
    sfText_setFillColor(p->txt_timer, sfBlack);
    sfText_setFont(p->txt_timer, g->font);
    sfSprite_setScale(p->a->sprite, (sfVector2f){4, 4});
    sfView_setCenter(p->pov, g->mc->pos);
    sfView_setSize(p->pov, g->w_size);
    init_laby2(p, g);
    sfSprite_setPosition(p->a->sprite, p->pos);
    g->sc_play->laby = p;
}
