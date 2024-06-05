/*
** EPITECH PROJECT, 2024
** draw_skate
** File description:
** :wq
*/

#include "rpg.h"

static void draw_btn(game_t *g, button_t *btn)
{
    button_t *tmp = btn;

    for (; tmp; tmp = tmp->next)
        sfRenderWindow_drawRectangleShape(g->window, tmp->rect, sfFalse);
}

static void drawing_alive(game_t *g)
{
    chn_lst_t *tmp = g->sc_play->sk->train;
    train_t *tr = (void *)0;

    for (int i = 0; i < g->sc_play->sk->life; i++)
        sfRenderWindow_drawRectangleShape(g->window,
        g->sc_play->sk->life_tab[i], sfFalse);
    for (; tmp; tmp = tmp->next) {
        tr = (train_t *)tmp->data;
        sfRenderWindow_drawRectangleShape(g->window, tr->sp, sfFalse);
    }
}

void draw_skate(game_t *g)
{
    sfRenderWindow_clear(g->window, sfWhite);
    sfRenderWindow_drawRectangleShape(g->window, g->sc_play->sk->bg, 0);
    sfRenderWindow_drawSprite(g->window, g->mc->animation->sprite, NULL);
    sfRenderWindow_drawText(g->window, g->mc->lvl, NULL);
    if (g->sc_play->sk->alive)
        drawing_alive(g);
    if (!g->sc_play->sk->alive) {
        draw_btn(g, g->sc_play->sk->btn);
        sfRenderWindow_drawSprite(g->window, g->cursor, NULL);
    }
    sfRenderWindow_display(g->window);
}
