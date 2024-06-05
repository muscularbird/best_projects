/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** boss
*/

#ifndef BOSS_H
    #define BOSS_H
    #include "rpg.h"
    #define VEC sfVector2f
////////////boss scene///////

void init_boss(game_t *g);
void events_boss(game_t *g);
void draw_boss(game_t *g);
void free_death(game_t *g);
void update_boss(game_t *g);

void fight_boss(main_char_t *m, game_t *g);
void input_main_char_boss(game_t *g, float d);
void update_boss_statement(game_t *g);
void collide_into_boss_and_mc(game_t *g);
void init_main_char_boss(game_t *g);

enum state_boss {
    IDLE_BOSS = 0,
    RUN_BOSS = 60,
    ATTACK1_BOSS = 120,
    ATTACK2_BOSS = 180,
    HIT_BOSS = 384,
    DEATH_BOSS = 448
};

typedef struct boss_sc_s {
    button_t *btn;
    sfRectangleShape *opacity;
    sfText *text;
} boss_sc_t;

#endif
