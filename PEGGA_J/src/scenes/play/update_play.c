/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** func_play_scene
*/

#include "rpg.h"

int collide(sfVector2f pos1, sfVector2f pos2, float range)
{
    if (sqrtl((pos1.x - pos2.x) * (pos1.x - pos2.x) +
    (pos1.y - pos2.y) * (pos1.y - pos2.y)) < range)
        return 1;
    return 0;
}

static void update_obj(game_t *g)
{
    object_t *obj = g->object;
    int height = 0;
    float width = 0;

    while (obj) {
        if (collide(g->mc->pos, sfRectangleShape_getPosition(obj->rect), 20.0)
        && obj->visible)
            obj->fonc(g, obj);
        obj = obj->next;
    }
    for (int i = 0; g->mc->full_inv[i]; i++) {
        if (i > 3)
            height = 35;
        if (i == 4)
            width = 0;
        sfRectangleShape_setPosition(g->mc->full_inv[i],
        (sfVector2f){g->mc->pos.x + 18 + width, g->mc->pos.y + 28 + height});
        width += 28.5;
    }
}

void update_anim(animation_t *animation, float delta_time, int beg_height)
{
    if (delta_time > 0.1) {
        animation->bounds.top = beg_height;
        animation->bounds.left += 32;
        if (animation->bounds.left >= 320) {
            animation->bounds.left = 0;
        }
        sfClock_restart(animation->clock);
        sfSprite_setTextureRect(animation->sprite, animation->bounds);
    }
}

static void set_pos_medal(game_t *g)
{
    int padding = 0;

    for (int i = 0; g->mc->medal_tab[i]; i++) {
        if (i < g->sc_play->current_quest) {
            sfRectangleShape_setPosition(g->mc->medal_tab[i],
            (sfVector2f){g->mc->pos.x + 80 + padding, g->mc->pos.y - 100});
            padding += 15;
        }
    }
}

static void is_near_adm(game_t *g)
{
    ADM_t *tmp = g->adm;
    float norm;

    while (tmp) {
        norm = sqrt(pow(g->mc->pos.x - tmp->pos.x, 2) +
        pow(g->mc->pos.y - tmp->pos.y, 2));
        if (norm < 30 && !tmp->finish) {
            sfText_setPosition(g->sc_play->txt,
            (sfVector2f){tmp->pos.x - 10, tmp->pos.y - 25});
            g->sc_play->near_adm = sfTrue;
        }
        tmp = tmp->next;
    }
}

static void update_normal_animations(game_t *g, float delta, float d)
{
    update_anim(g->mc->animation, g->mc->animation->seconds, g->mc->anim);
    update_pnj_anim(&g->pnj, d);
    update_pnj_anim(&g->sc_play->cimetierre, d);
    update_adm_anim(g, d);
    input_main_char(g->mc, &g->pnj, g, delta);
}

void update_normal(game_t *g)
{
    float d = sfClock_getElapsedTime
        (g->mc->animation->clock).microseconds / MILION;
    float delta = sfClock_restart(g->clock).microseconds / MILION;

    set_pos_medal(g);
    update_mainchar_infos(g);
    g->mc->animation->seconds = d;
    is_near_adm(g);
    update_normal_animations(g, delta, d);
    collide_into_pnj_and_mc(&g->pnj, g);
    collide_into_pnj_and_mc(&g->sc_play->cimetierre, g);
    update_pnj_statement(&g->pnj, g);
    update_pnj_statement(&g->sc_play->cimetierre, g);
    sfSprite_setOrigin(g->mc->inv_back,
    ch_coor((sfVector2f){(1318 * 0.1) / 2, (993 * 0.1) / 2}, g->w_size));
    sfSprite_setPosition(g->mc->inv_back, g->mc->pos);
    if (g->sc_play->current_quest == 5)
        update_obj(g);
    update_archi_quest(g);
}

void update_dialogues(game_t *g)
{
    UNUSED(g);
    return;
}

void update_play_scene(game_t *g)
{
    g->sc_play->game_menus[g->sc_play->current_game].update(g);
}
