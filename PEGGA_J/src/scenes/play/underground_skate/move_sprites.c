/*
** EPITECH PROJECT, 2024
** move_trains
** File description:
** fireplace 4k
*/

#include "rpg.h"

static void adding_train(game_t *g)
{
    float d = sfClock_getElapsedTime
        (g->sc_play->sk->spawn_rate).microseconds / MILION;

    if (d > SPAWN_DELAY) {
        sfClock_restart(g->sc_play->sk->spawn_rate);
        add_train(g);
    }
}

static void move_trains(game_t *g, float s)
{
    sfVector2f pos = {0, 0};
    chn_lst_t *lst = g->sc_play->sk->train;
    train_t *tr = (void *)0;

    for (; lst; lst = lst->next) {
        tr = (train_t *)lst->data;
        pos = sfRectangleShape_getPosition(tr->sp);
        pos.y = pos.y + tr->spd * s;
        if (pos.y > g->w_size.y + 30) {
            pos.y = -20;
            tr->spd += 5;
            tr->touched = 0;
            pos.x = (g->w_size.x / 2 - 400) + rand() % 800;
            g->sc_play->sk->high_max -= 100;
        }
        sfRectangleShape_setPosition(tr->sp, pos);
    }
    adding_train(g);
}

static void move_right(game_t *g, float s)
{
    if (colo(g->sc_play->sk->u_map, (unsigned int)(g->sc_play->sk->pos.x) + 16,
    (unsigned int)(g->sc_play->sk->pos.y) + 16, 0)) {
        g->sc_play->sk->pos.x += g->mc->speed * s;
        sfSprite_setScale(g->mc->animation->sprite, (sfVector2f){4.5, 4.5});
        g->mc->anim = 64;
    }
    sfSprite_setPosition(g->mc->animation->sprite, g->sc_play->sk->pos);
}

static void move_left(game_t *g, float s)
{
    if (colo(g->sc_play->sk->u_map, (unsigned int)(g->sc_play->sk->pos.x) - 16,
    (unsigned int)(g->sc_play->sk->pos.y) + 16, 0)) {
        g->sc_play->sk->pos.x -= g->mc->speed * s;
        sfSprite_setScale(g->mc->animation->sprite, (sfVector2f){-4.5, 4.5});
        g->mc->anim = 64;
    }
    sfSprite_setPosition(g->mc->animation->sprite, g->sc_play->sk->pos);
}

void move_sp(game_t *g)
{
    float s = sfClock_restart(g->clock).microseconds / MILION;

    if (colo(g->sc_play->sk->u_map, (unsigned int)(g->sc_play->sk->pos.x) + 16,
        (unsigned int)(g->sc_play->sk->pos.y) - 16, 0) &&
        g->sc_play->sk->pos.y > g->sc_play->sk->high_max)
        g->sc_play->sk->pos.y -= 10 * s;
    if (sfKeyboard_isKeyPressed(g->mc->rightkey))
        move_right(g, s);
    else if (sfKeyboard_isKeyPressed(g->mc->leftkey))
        move_left(g, s);
    else
        g->mc->anim = 32;
    move_trains(g, s);
}
