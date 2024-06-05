/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/scenes/play/draw_play
** File description:
** hello world?
*/

#include "rpg.h"

static void draw_medal(game_t *g)
{
    for (int i = 0; g->mc->medal_tab[i]; i++) {
        if (i < g->sc_play->current_quest) {
            sfRenderWindow_drawRectangleShape(g->window,
            g->mc->medal_tab[i], NULL);
        }
    }
}

static void draw_ennemies2(game_t *g, pnj_t **tmp)
{
    orientation((*tmp)->anim->sprite, (*tmp)->cu_pos, g->mc->pos, (*tmp)->k);
    sfRenderWindow_drawRectangleShape(g->window, (*tmp)->bck_lifebar, 0);
    sfRenderWindow_drawRectangleShape(g->window, (*tmp)->lifebar, NULL);
}

static void draw_obj(game_t *g)
{
    object_t *obj = g->object;

    while (obj) {
        if (obj->visible)
            sfRenderWindow_drawRectangleShape(g->window, obj->rect, NULL);
        obj = obj->next;
    }
}

void draw_inv(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->mc->inv_back, NULL);
    for (int i = 0; g->mc->full_inv[i]; i++) {
        sfRenderWindow_drawRectangleShape(g->window, g->mc->full_inv[i], NULL);
    }
}

static void draw_ennemies(game_t *g)
{
    pnj_t *tmp = g->pnj;
    pnj_t *lst = g->sc_play->cimetierre;

    while (lst) {
        sfRenderWindow_drawSprite(g->window, lst->anim->sprite, NULL);
        if (lst->alive) {
            draw_ennemies2(g, &lst);
        }
        lst = lst->next;
    }
    while (tmp) {
        sfRenderWindow_drawSprite(g->window, tmp->anim->sprite, NULL);
        if (tmp->alive)
            draw_ennemies3(g, tmp);
        tmp = tmp->next;
    }
}

void draw_pressf(game_t *g)
{
    if (g->sc_play->near_adm)
        sfRenderWindow_drawText(g->window, g->sc_play->txt, NULL);
}

static void draw_normal2(game_t *g)
{
    ADM_t *a = g->adm;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->map_sp, sfFalse);
    sfRenderWindow_drawSprite(g->window, g->map_up, NULL);
    draw_ennemies(g);
    while (a) {
        sfRenderWindow_drawSprite(g->window, a->a->sprite, sfFalse);
        a = a->next;
    }
    if (g->sc_play->current_quest == 5)
        draw_obj(g);
}

void draw_normal(game_t *g)
{
    draw_normal2(g);
    sfRenderWindow_drawSprite(g->window, g->mc->animation->sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->map_up, NULL);
    if (g->mc->inv)
        draw_inv(g);
    draw_medal(g);
    draw_pressf(g);
    sfRenderWindow_drawText(g->window, g->mc->lvl, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->mc->bck_lifebar, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->mc->lifebar, NULL);
    sfRenderWindow_drawText(g->window, g->mc->hp, NULL);
    sfRenderWindow_display(g->window);
}

void draw_dialogues(game_t *g)
{
    ADM_t *a = g->adm;

    while (a) {
        sfRenderWindow_drawSprite(g->window, a->a->sprite, sfFalse);
        if (a->statement)
            draw_dialogue(a, g);
        a = a->next;
    }
}

void draw_play_scene(game_t *g)
{
    g->sc_play->game_menus[g->sc_play->current_game].draw(g);
}
