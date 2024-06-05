/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** update_petanque
*/

#include "rpg.h"

static void update_pet2(game_t *g)
{
    if (g->sc_play->pet->count >= 160)
        g->sc_play->pet->dir = -1;
    if (g->sc_play->pet->count <= 0)
        g->sc_play->pet->dir = 1;
}

static int check_colide(game_t *g, bowl_t *bowl)
{
    mob_t *tmp = g->sc_play->pet->mob;
    mob_t *prev = g->sc_play->pet->mob;

    while (tmp) {
        if (collide(sfRectangleShape_getPosition(tmp->rect),
        sfRectangleShape_getPosition(bowl->bowl), 60)) {
            free_mob(g, tmp, prev);
            return 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return 0;
}

static void move_bowl(game_t *g, bowl_t *tmp)
{
    if (sfClock_getElapsedTime(g->clock).microseconds -
    tmp->time_save.microseconds > 1000) {
        tmp->time_save = sfClock_getElapsedTime(g->clock);
        sfRectangleShape_setPosition(tmp->bowl,
        (sfVector2f){sfRectangleShape_getPosition(tmp->bowl).x +
        2 * cos((tmp->angle * PI) / 180),
        sfRectangleShape_getPosition(tmp->bowl).y +
        2 * sin((tmp->angle * PI) / 180)});
    }
}

static void update_bowl(game_t *g)
{
    bowl_t *tmp = g->sc_play->pet->bowl;
    bowl_t *prev = g->sc_play->pet->bowl;
    sfVector2f pos = {0, 0};

    while (tmp) {
        pos = sfRectangleShape_getPosition(tmp->bowl);
        move_bowl(g, tmp);
        if (check_colide(g, tmp)) {
            free_bowl(g, tmp, prev);
            g->sc_play->pet->kill ++;
        }
        if (pos.x > g->w_size.x || pos.y > g->w_size.y || pos.y < 0)
            free_bowl(g, tmp, prev);
        prev = tmp;
        tmp = tmp->next;
    }
}

static void update_anim_mob(game_t *g, mob_t *animation)
{
    if (sfClock_getElapsedTime(g->clock).microseconds -
    animation->clock_anim.microseconds > 100000) {
        animation->clock_anim = sfClock_getElapsedTime(g->clock);
        animation->bounds.top = 64;
        animation->bounds.left += 32;
        if (animation->bounds.left >= 320) {
            animation->bounds.left = 0;
        }
        sfRectangleShape_setTextureRect(animation->rect, animation->bounds);
    }
}

static void update_mob(game_t *g)
{
    mob_t *tmp = g->sc_play->pet->mob;
    mob_t *prev = g->sc_play->pet->mob;

    while (tmp) {
        update_anim_mob(g, tmp);
        if (sfClock_getElapsedTime(g->clock).microseconds -
        tmp->time.microseconds > 20000) {
            tmp->time = sfClock_getElapsedTime(g->clock);
            sfRectangleShape_setPosition(tmp->rect,
            (sfVector2f){sfRectangleShape_getPosition(tmp->rect).x - 5,
            sfRectangleShape_getPosition(tmp->rect).y});
        }
        if (sfRectangleShape_getPosition(tmp->rect).x < 0) {
            sfRectangleShape_setPosition(tmp->rect, (sfVector2f){200, 200});
            free_mob(g, tmp, prev);
            g->sc_play->pet->life--;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

static void update_canon(game_t *g)
{
    if (sfClock_getElapsedTime(g->clock).microseconds -
    g->sc_play->pet->save.microseconds > 5000 &&
    g->sc_play->pet->move_dir) {
        g->sc_play->pet->save = sfClock_getElapsedTime(g->clock);
        sfRectangleShape_rotate(g->sc_play->pet->direction,
        g->sc_play->pet->dir * 0.5);
        g->sc_play->pet->count += g->sc_play->pet->dir;
    }
}

void update_petanque(game_t *g)
{
    sfRenderWindow_setView(g->window, g->sc_play->laby->pov);
    g->mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPositionRenderWindow(g->window), sfFalse);
    sfRenderWindow_setView(g->window, g->global_POV);
    sfSprite_setPosition(g->cursor, g->mouse_pos);
    if (g->sc_play->pet->life && g->sc_play->pet->kill < 5) {
        update_mob(g);
        update_pet2(g);
        update_canon(g);
        if (sfClock_getElapsedTime(g->clock).microseconds / MILION -
        g->sc_play->pet->mob_clock.microseconds / MILION > SPAWN_DELAY) {
            create_mob(g);
            g->sc_play->pet->mob_clock = sfClock_getElapsedTime(g->clock);
        }
    }
    update_bowl(g);
}
