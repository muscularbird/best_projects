/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** main_character
*/

#ifndef MAIN_CHAR_H
    #define MAIN_CHAR_H
    #define WARRIOR_MC "assets/warrior.png"
    #define SOUND_WALK "./assets/walk.wav"
    #define LIFEBAR "./assets/lifebar.png"
    #define BCK_LIFEBAR "./assets/bck_lifebar.png"
    #define ATTACK_DELAY 1.2f
    #include "pnj.h"

typedef struct main_char_s {
    sfVector2f pos;
    sfVector2f old_pos;
    float speed;
    sfBool firstpress;
    sfCircleShape *area;
    sfView *POV;
    animation_t *animation;
    char *top;
    char *bottom;
    char *left;
    char *right;
    char *fight;
    sfKeyCode topkey;
    sfKeyCode botkey;
    sfKeyCode leftkey;
    sfKeyCode rightkey;
    sfKeyCode fightkey;
    sfCircleShape *range;
    sfBool PREVIOUS_STATE;
    int anim;
    sfText *lvl;
    int lvl_nb;
    sfText *hp;
    int hp_nb;
    int AD;
    sfTexture *lifebat_texture;
    sfRectangleShape *lifebar;
    sfTexture *bck_lifebat_tx;
    sfRectangleShape *bck_lifebar;
    sfClock *attack;
    sfBool inv;
    sfSprite *inv_back;
    sfTexture *sword_text;
    sfRectangleShape **full_inv;
    sfRectangleShape **medal_tab;
} main_char_t;

void init_main_char(game_t *g);
void input_main_char(main_char_t *mc, pnj_t **p, game_t *g, float s);
void update_mainchar_infos(game_t *g);
float distance(sfVector2f a, sfVector2f b);
#endif /* !MAIN_CHAR_H */
