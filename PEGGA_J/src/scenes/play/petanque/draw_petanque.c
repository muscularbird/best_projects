/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** draw_petanque
*/

#include "rpg.h"

static void draw_btn(game_t *g, button_t *btn)
{
    button_t *tmp = btn;

    while (tmp) {
        sfRenderWindow_drawRectangleShape(g->window, tmp->rect, sfFalse);
        tmp = tmp->next;
    }
}

static void draw_win(game_t *g)
{
    sfRenderWindow_drawText(g->window, g->sc_play->pet->text, sfFalse);
    draw_btn(g, g->sc_play->pet->btn);
}

static void draw_mob(game_t *g)
{
    mob_t *tmp_m = g->sc_play->pet->mob;

    while (tmp_m) {
        sfRenderWindow_drawRectangleShape(g->window, tmp_m->rect, sfFalse);
        tmp_m = tmp_m->next;
    }
}

static void draw_bowl(game_t *g)
{
    bowl_t *tmp = g->sc_play->pet->bowl;

    while (tmp) {
        sfRenderWindow_drawRectangleShape(g->window, tmp->bowl, sfFalse);
        tmp = tmp->next;
    }
}

void draw_petanque(game_t *g)
{
    sfRenderWindow_clear(g->window, sfWhite);
    sfRenderWindow_drawRectangleShape(g->window,
    g->sc_play->pet->background, 0);
    draw_bowl(g);
    sfRenderWindow_drawRectangleShape(g->window,
    g->sc_play->pet->direction, 0);
    draw_mob(g);
    for (int i = 0; i < g->sc_play->pet->life; i++)
        sfRenderWindow_drawRectangleShape(g->window,
        g->sc_play->pet->life_tab[i], sfFalse);
    if (g->sc_play->pet->life == 0) {
        draw_btn(g, g->sc_play->pet->btn);
        disable_button(&g->sc_play->pet->btn, 1);
    } else if (g->sc_play->pet->kill >= 5)
        draw_win(g);
    sfRenderWindow_drawSprite(g->window, g->cursor, NULL);
    sfRenderWindow_display(g->window);
}
