/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** main_char
*/

#include "rpg.h"

static void check_fight(pnj_t **p, main_char_t *m, game_t *g, float d)
{
    UNUSED(g);
    if ((*p)->HP <= 0) {
        (*p)->anims = 128;
        (*p)->alive = sfFalse;
    }
    if (d <= 25 && (*p)->alive) {
        (*p)->anims = 96;
        m->hp_nb -= 30;
    }
}

void fight(main_char_t *m, pnj_t **p, game_t *g)
{
    pnj_t *tmp = *p;
    float d = 0.0;

    while (tmp) {
        d = distance(m->pos, tmp->cu_pos);
        if (d <= 50 && tmp->statement && tmp->alive) {
            tmp->HP -= m->AD;
            check_fight(&tmp, m, g, d);
        }
        tmp = tmp->next;
    }
}

static void input_main_char_3(main_char_t *mc, sfBool vf, pnj_t **p, game_t *g)
{
    sfTime t;

    if (sfKeyboard_isKeyPressed(mc->fightkey)) {
        t = sfClock_getElapsedTime(mc->attack);
        mc->anim = 96;
        if (sfTime_asSeconds(t) >= ATTACK_DELAY) {
            fight(mc, p, g);
            fight(mc, &g->sc_play->cimetierre, g);
            sfClock_restart(mc->attack);
        }
        vf = sfTrue;
    }
    if (!vf)
        mc->anim = 32;
    sfSprite_setPosition(mc->animation->sprite, mc->pos);
    sfCircleShape_setPosition(mc->area, mc->pos);
    sfCircleShape_setPosition(mc->range, mc->pos);
}

static void input_main_char2(pnj_t **p, sfBool verf, game_t *g, float s)
{
    if (sfKeyboard_isKeyPressed(g->mc->rightkey) &&
    colo(g->back_map, (unsigned int)(g->mc->pos.x) + 16,
    (unsigned int)(g->mc->pos.y) + 16, g->sc_play)) {
        g->mc->pos.x += g->mc->speed * s;
        sfSprite_setScale(g->mc->animation->sprite, (sfVector2f){0.7, 0.7});
        g->mc->anim = 64;
        verf = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(g->mc->leftkey) &&
    colo(g->back_map, (unsigned int)(g->mc->pos.x) - 16,
    (unsigned int)(g->mc->pos.y) + 16, g->sc_play)) {
        g->mc->pos.x -= g->mc->speed * s;
        sfSprite_setScale(g->mc->animation->sprite, (sfVector2f){-0.7, 0.7});
        g->mc->anim = 64;
        verf = sfTrue;
    }
    input_main_char_3(g->mc, verf, p, g);
}

void input_main_char(main_char_t *mc, pnj_t **p, game_t *g, float s)
{
    sfBool verif = sfFalse;

    if (sfKeyboard_isKeyPressed(mc->topkey) &&
    colo(g->back_map, (unsigned int)(mc->pos.x),
        (unsigned int)(mc->pos.y) + 12, g->sc_play)) {
        mc->pos.y -= mc->speed * s;
        mc->anim = 64;
        verif = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(mc->botkey) &&
    colo(g->back_map, (unsigned int)(mc->pos.x),
        (unsigned int)(mc->pos.y) + 18, g->sc_play)) {
        mc->pos.y += mc->speed * s;
        mc->anim = 64;
        verif = sfTrue;
    }
    input_main_char2(p, verif, g, s);
}
