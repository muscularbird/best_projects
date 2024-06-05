/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** pnj
*/

#include "rpg.h"

static void where_go(pnj_t *p, game_t *g, sfVector2f pos)
{
    UNUSED(pos);
    if (is_pnj_walk(g->back_map,
    (sfVector2f){p->cu_pos.x + (p->traj.x > 0 ? 16 : -16),
    p->cu_pos.y + (p->traj.y > 0 ? 16 : 0)})) {
        sfSprite_move(p->anim->sprite, p->traj);
    }
}

static void update_life(pnj_t **mob, game_t *g)
{
    UNUSED(g);
    (*mob)->cu_pos = sfSprite_getPosition((*mob)->anim->sprite);
    sfRectangleShape_setSize((*mob)->lifebar,
    (sfVector2f){(*mob)->HP *
    ((*mob)->size_life_bar / (*mob)->start_life), 3 * (*mob)->mob_scale.y});
    sfRectangleShape_setPosition((*mob)->lifebar,
    (sfVector2f){(*mob)->cu_pos.x, (*mob)->cu_pos.y -
    (20 * (*mob)->mob_scale.y)});
    sfRectangleShape_setPosition((*mob)->bck_lifebar,
    (sfVector2f){(*mob)->cu_pos.x, (*mob)->cu_pos.y -
    (20 * (*mob)->mob_scale.y)});
}

void update_pnj_statement(pnj_t **lst, game_t *g)
{
    pnj_t *tmp = *lst;
    sfVector2f dir;
    sfVector2f next_pos;

    while (tmp) {
        update_life(&tmp, g);
        sfCircleShape_setPosition(tmp->area, tmp->cu_pos);
        dir = vector_sub(g->mc->pos, tmp->cu_pos);
        tmp->norm = sqrtf(pow(dir.x, 2) + pow(dir.y, 2));
        if (tmp->norm > 0 && tmp->statement && tmp->alive) {
            tmp->traj.x = (dir.x / tmp->norm) * tmp->speed;
            tmp->traj.y = (dir.y / tmp->norm) * tmp->speed;
            next_pos = (sfVector2f) {
                tmp->cu_pos.x + tmp->traj.x + (tmp->traj.x > 0 ? 16 : -16),
                tmp->cu_pos.y + tmp->traj.y + (tmp->traj.y > 0 ? 16 : -16)
            };
            where_go(tmp, g, next_pos);
        }
        tmp = tmp->next;
    }
}

void update_pnj_anim(pnj_t **lst, float delta)
{
    pnj_t *tmp = *lst;
    sfIntRect r = {9 * 32, 128, 32, 32};

    while (tmp) {
        tmp->anim->seconds = delta;
        if (tmp->anims == 128)
            sfSprite_setTextureRect(tmp->anim->sprite, r);
        else
            update_animation(tmp->anim, tmp->anim->seconds, tmp->anims, 10);
        tmp = tmp->next;
    }
}

void collide_into_pnj_and_mc(pnj_t **lst, game_t *g)
{
    pnj_t *tmp = *lst;
    float dx = 0.0;
    float dy = 0.0;
    float norm = 0.0;

    while (tmp) {
        dx = tmp->cu_pos.x - g->mc->pos.x;
        dy = tmp->cu_pos.y - g->mc->pos.y;
        norm = sqrtf(pow(dx, 2) + pow(dy, 2));
        if (!tmp->statement && norm < 160 * g->w_size.x / 1920 && tmp->alive) {
            tmp->statement = sfTrue;
            tmp->anims = 64;
            sfCircleShape_setRadius(tmp->area, 40.0);
        }
        tmp = tmp->next;
    }
}
