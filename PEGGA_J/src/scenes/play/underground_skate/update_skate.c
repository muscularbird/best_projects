/*
** EPITECH PROJECT, 2024
** update_skate
** File description:
** try not to segfault, good luck :)
*/

#include "rpg.h"

static void update_score(game_t *g)
{
    char str[24];

    g->sc_play->sk->score = (int)(g->w_size.y - g->sc_play->sk->pos.y - 50);
    sfText_setPosition(g->mc->lvl,
    (sfVector2f){250, g->w_size.y - 110});
    sprintf(str, "Score: %d", g->sc_play->sk->score);
    sfText_setString(g->mc->lvl, str);
}

static int train_crash(game_t *g, train_t *tr)
{
    sfVector2f tr_pos = sfRectangleShape_getPosition(tr->sp);
    sfVector2f mc_pos = g->sc_play->sk->pos;

    if (collide(tr_pos, mc_pos, 120))
        return 1;
    return 0;
}

static void dial_sk(game_t *g, sfVector2f pos1)
{
    sfVector2f pos2;
    float distance = 0.0;
    ADM_t *tmp = g->adm;

    while (tmp) {
        pos2 = tmp->pos;
        distance = sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
        if (distance < 30) {
            g->sc_play->near_adm = sfFalse;
            tmp->statement = sfTrue;
            tmp->display_complete = sfFalse;
            tmp->finish = sfFalse;
            tmp->index = 0;
            g->sc_play->current_game = DIALOGUES;
            draw_dialogue(tmp, g);
        }
        tmp = tmp->next;
    }
}

static void defeat(game_t *g)
{
    g->sc_play->sk->alive = 0;
    g->sc_play->dialogue_sk = 1;
    if (g->sc_play->sk->score >= 300) {
        dial_sk(g, (sfVector2f){-10000, -10000});
    } else {
        dial_sk(g, (sfVector2f){10000, 10000});
        disable_button(&g->sc_play->sk->btn, 1);
    }
}

static void collisions(game_t *g)
{
    train_t *tr = (void *)0;
    chn_lst_t *lst = g->sc_play->sk->train;
    int res = 0;

    for (; lst; lst = lst->next) {
        tr = (train_t *)lst->data;
        res = train_crash(g, tr);
        if (res && g->sc_play->sk->life <= 0)
            defeat(g);
        if (res && g->sc_play->sk->life > 0 && !tr->touched) {
            g->sc_play->sk->life--;
            tr->touched = 1;
        }
    }
}

void update_skate(game_t *g)
{
    static int setup = 0;

    g->mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPositionRenderWindow(g->window), sfFalse);
    sfSprite_setPosition(g->cursor, g->mouse_pos);
    sfSprite_setPosition(g->mc->animation->sprite, g->sc_play->sk->pos);
    if (!setup) {
        sfSprite_setScale(g->mc->animation->sprite, (sfVector2f){4.5, 4.5});
        sfClock_restart(g->sc_play->sk->spawn_rate);
        sfRenderWindow_setView(g->window, g->global_POV);
        setup = 1;
    }
    g->mc->animation->seconds = sfClock_getElapsedTime
        (g->mc->animation->clock).microseconds / MILION;
    update_anim(g->mc->animation, g->mc->animation->seconds, g->mc->anim);
    if (g->sc_play->sk->alive) {
        move_sp(g);
        update_score(g);
        collisions(g);
    }
}
