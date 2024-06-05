/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** update_play
*/

#include "rpg.h"

static void cond(game_t *g, laby_t *l, float d)
{
    if (l->cp >= 10) {
        g->sc_play->current_quest++;
        g->mc->lvl_nb++;
        g->sc_play->current_game = NORMAL;
    }
    if (d <= 0) {
        sfRenderWindow_setView(g->window, g->global_POV);
        g->next_scene = DEATH;
    }
}

void moov(game_t *g, laby_t *l)
{
    sfFloatRect rect;

    g->mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPositionRenderWindow(g->window), sfFalse);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        rect = sfSprite_getGlobalBounds(l->a->sprite);
        if (sfFloatRect_contains(&rect, g->mouse_pos.x, g->mouse_pos.y)) {
            sfSprite_setPosition(l->a->sprite,
            (sfVector2f){rand() % (int)(l->mx.y - l->mx.x + 1) + l->mx.x,
            rand() % (int)(l->my.y - l->my.x + 1) + l->my.x});
            l->cp++;
        }
    }
    sfSprite_setPosition(g->cursor, g->mouse_pos);
}

void update_laby(game_t *g)
{
    float d = 0.0;
    static float delta = 300.0;
    char str[32];
    char str2[32];

    sfRenderWindow_setView(g->window, g->sc_play->laby->pov);
    d = sfClock_getElapsedTime(g->sc_play->laby->a->clock).microseconds /
    MILION;
    delta -= d;
    update_anim(g->sc_play->laby->a, d, 224);
    moov(g, g->sc_play->laby);
    cond(g, g->sc_play->laby, delta);
    sprintf(str, "timer: %.2f", delta);
    sfText_setString(g->sc_play->laby->txt_timer, str);
    sprintf(str2, "score: %d", g->sc_play->laby->cp);
    sfText_setString(g->sc_play->laby->txt_cp, str2);
}
