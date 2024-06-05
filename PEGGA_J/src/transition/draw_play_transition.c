/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** draw_play_transition
*/

#include "rpg.h"

static void draw_ennemies2_tr(game_t *g, pnj_t *tmp)
{
    orientation(tmp->anim->sprite, tmp->cu_pos, g->mc->pos, tmp->k);
    sfRenderWindow_drawRectangleShape(g->window, tmp->bck_lifebar, 0);
    sfRenderWindow_drawRectangleShape(g->window, tmp->lifebar, NULL);
}

static void draw_obj_tr(game_t *g)
{
    object_t *obj = g->object;

    while (obj) {
        if (obj->visible)
            sfRenderWindow_drawRectangleShape(g->window, obj->rect, NULL);
        obj = obj->next;
    }
}

void draw_inv_tr(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->mc->inv_back, NULL);
    for (int i = 0; g->mc->full_inv[i]; i++) {
        sfRenderWindow_drawRectangleShape(g->window, g->mc->full_inv[i], NULL);
    }
}

static void draw_ennemies_tr(game_t *g)
{
    pnj_t *tmp = g->pnj;
    pnj_t *lst = g->sc_play->cimetierre;

    while (tmp) {
        sfRenderWindow_drawSprite(g->window, tmp->anim->sprite, NULL);
        if (tmp->alive)
            draw_ennemies2_tr(g, tmp);
        tmp = tmp->next;
    }
    while (lst) {
        sfRenderWindow_drawSprite(g->window, lst->anim->sprite, NULL);
        if (lst->alive)
            draw_ennemies2_tr(g, tmp);
        lst = lst->next;
    }
}

void draw_pressf_tr(game_t *g)
{
    if (g->sc_play->near_adm)
        sfRenderWindow_drawText(g->window, g->sc_play->txt, NULL);
}

static void draw_normal2_tr(game_t *g)
{
    ADM_t *a = g->adm;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->map_sp, sfFalse);
    sfRenderWindow_drawSprite(g->window, g->map_up, NULL);
    draw_ennemies_tr(g);
    while (a) {
        sfRenderWindow_drawSprite(g->window, a->a->sprite, sfFalse);
        a = a->next;
    }
    draw_obj_tr(g);
}

void draw_normal_tr(game_t *g)
{
    draw_normal2_tr(g);
    sfRenderWindow_drawSprite(g->window, g->mc->animation->sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->map_up, NULL);
    if (g->mc->inv)
        draw_inv_tr(g);
    draw_pressf_tr(g);
    sfRenderWindow_drawText(g->window, g->mc->lvl, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->mc->bck_lifebar, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->mc->lifebar, NULL);
    sfRenderWindow_drawText(g->window, g->mc->hp, NULL);
}
