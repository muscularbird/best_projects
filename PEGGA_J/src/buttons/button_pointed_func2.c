/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** button_pointer_func
*/

#include "rpg.h"

void close_pet(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->sc_play->current_quest++;
    g->mc->lvl_nb++;
    g->sc_play->current_game = NORMAL;
}

void restart_pet(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    g->sc_play->pet->life = 3;
}

void close_sk(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    free_trains(g);
    sfSprite_setScale(g->mc->animation->sprite, (sfVector2f){0.7, 0.7});
    g->sc_play->dialogue_sk = 0;
    g->sc_play->current_game = NORMAL;
    g->sc_play->current_quest++;
    g->mc->lvl_nb++;
}

void restart_sk(game_t *g, button_t *btn)
{
    UNUSED(btn);
    play_sound(g);
    free_trains(g);
    g->sc_play->sk->score = 0;
    g->sc_play->sk->alive = 1;
    g->sc_play->sk->life = 3;
    g->sc_play->sk->pos = (sfVector2f){g->w_size.x / 2, g->w_size.y};
}

void restart(game_t *g, button_t *btn)
{
    g->current_scene = START;
    UNUSED(btn);
    UNUSED(g);
    return;
}
