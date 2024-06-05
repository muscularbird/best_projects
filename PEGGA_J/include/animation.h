/*
** EPITECH PROJECT, 2024
** MY_game
** File description:
** draw.h
*/

#ifndef ANIMATION_H
    #define ANIMATION_H
    #include "my.h"

typedef struct game_s game_t;

void init_scene(game_t *game);
void events_scene(game_t *game);
void update_scene(game_t *game);
void draw_scene(game_t *game);
void free_scene(game_t *game);

typedef struct spri_s spri_t;

    #define NB_STATES sizeof(state_t)

typedef enum state_e {
    IDLE,
    GESTURE,
    WALK,
    ATTACK,
    DEAD
} state_t;

typedef struct animation_s {
    float seconds;
    int frame_size;
    sfClock *clock;
    sfIntRect bounds;
    sfTexture *texture;
    sfSprite *sprite;
} animation_t;

typedef struct anim_sp_s {
    spri_t *sprite;
    state_t state[NB_STATES];
} anim_sp_t;

void update_animation(animation_t *animation, float, int, float);
animation_t *create_animation(const char *texture_path);

#endif
