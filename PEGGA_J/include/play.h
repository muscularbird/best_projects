/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/include/play
** File description:
** r/ProgrammerHumor
*/

#ifndef PLAY_SCENE_H
    #define PLAY_SCENE_H
    #define MAP_LABY "./assets/labyrinthe.png"
    #define BAT "./assets/rat and bat.png"
    #define SH "./source_files/fog.frag"
    #define INVENTORY "./assets/inventaire.png"
    #define TRAIN "./assets/elliot.png"
    #define SKATE_BG "./assets/stairway_to_heaven.png"
    #define UNDER_BG "./assets/back_heaven.png"
    #define SPAWN_DELAY 5.0f
    #define ZO NULL
    #include "my.h"

typedef struct game_s game_t;

    #define INV "./assets/inventaire.png"

////////////////menus play////////////////
    #define NB_PLAYS COUNTER

typedef enum menu_play_e {
    NOTHING,
    JONA_MJ,
    NORMAL,
    DIALOGUES,
    PETANQUE,
    SKATER,
    COUNTER
} menu_play_t;

    #include "pnj.h"

typedef struct func_play_s {
    void (*event)(game_t *game);
    void (*update)(game_t *game);
    void (*draw)(game_t *game);
    void (*free)(game_t *game);
} func_play_t;

//////////PETANQUE///////////

typedef struct bowl_s {
    sfRectangleShape *bowl;
    sfVector2f position;
    float coef;
    float angle;
    sfTime time_save;
    struct bowl_s *next;
} bowl_t;

typedef struct mob_s {
    sfRectangleShape *rect;
    sfTexture *text;
    sfTime time;
    sfTime clock_anim;
    sfIntRect bounds;
    struct mob_s *next;
} mob_t;

typedef struct petanque_s {
    sfRectangleShape **life_tab;
    sfRectangleShape *direction;
    sfRectangleShape *background;
    sfTexture *back_text;
    sfTexture *tower_text;
    sfVector2f bar_pos;
    mob_t *mob;
    bowl_t *bowl;
    sfTime save;
    sfTime time_ball;
    sfTime mob_clock;
    button_t *btn;
    sfText *text;
    sfBool move_dir;
    sfBool moving_bowl;
    int count;
    int dir;
    int life;
    int kill;
    float angle;
    float direction_value;
} petanque_t;

void init_petanque(game_t *g);
void draw_petanque(game_t *g);
void update_petanque(game_t *g);
void events_petanque(game_t *g);
void free_petanque(game_t *g);

void create_mob(game_t *g);
void add_bowl(game_t *g, float coef, float angle);
void free_mob(game_t *g, mob_t *tmp, mob_t *prev);
void free_bowl(game_t *g, bowl_t *bowl, bowl_t *prev);
sfRectangleShape *create_life(int pos);
void free_all_bullet(game_t *g);
void free_all_mob(game_t *g);

//////////////////labyrinthe//////////////////////

typedef struct laby_s {
    sfTexture *map_txt;
    sfSprite *map;
    sfView *pov;
    animation_t *a;
    sfVector2f mx;
    sfVector2f my;
    sfVector2f pos;
    unsigned int x;
    unsigned int y;
    sfText *txt_timer;
    sfText *txt_cp;
    int cp;
} laby_t;

void draw_laby(game_t *g);
void update_laby(game_t *g);
void event_laby(game_t *g);
void init_laby(game_t *g);
void free_laby(game_t *g);
void update_anim(animation_t *animation, float delta_time, int beg_height);

//////////UNDERGROUND_SKATE///////////

typedef struct train_s {
    sfRectangleShape *sp;
    sfTexture *text;
    sfVector2f pos;
    int spd;
    int touched;
} train_t;

typedef struct skate {
    chn_lst_t *train;
    sfTexture *bg_t;
    sfRectangleShape *bg;
    sfRectangleShape **life_tab;
    sfImage *u_map;
    sfVector2f pos;
    sfTime time;
    sfClock *spawn_rate;
    button_t *btn;
    int score;
    int high_max;
    int life;
    int alive;
} skate_t;

void init_skate(game_t *g);
void events_skate(game_t *g);
void draw_skate(game_t *g);
void update_skate(game_t *g);
void free_skate(game_t *g);
void free_trains(game_t *g);
void free_train(train_t *tr);
void add_train(game_t *g);
void move_sp(game_t *g);

//////////////// Main Play Struct///////////////

typedef struct scene_play_s {
    laby_t *laby;
    sfText *txt;
    sfBool near_adm;
    func_play_t game_menus[NB_PLAYS];
    menu_play_t current_game;
    pnj_t *cimetierre;
    petanque_t *pet;
    skate_t *sk;
    sfBool final_boss;
    int current_quest;
    int dialogue_sk;
    sfBool FINAL;
    sfBool cimetierre_end;
} scene_play_t;

void draw_pressf(game_t *g);
void events_normal(game_t *game);
void update_normal(game_t *game);
void draw_normal(game_t *game);
void events_dialogues(game_t *game);
void update_dialogues(game_t *game);
void draw_dialogues(game_t *game);
void init_play_scene(game_t *game);
void events_play_scene(game_t *game);
void update_play_scene(game_t *game);
void draw_play_scene(game_t *game);
void free_play_scene(game_t *game);
void update_variables(ADM_t *adm, game_t *g);
void don_t_free(game_t *game);
int colo(sfImage *img, unsigned int x, unsigned int y, scene_play_t *p);
void init_sai3(game_t *g);
void draw_inv(game_t *g);
void update_archi_quest(game_t *g);

////////////////////object///////////////////////

typedef struct object_s object_t;

typedef struct object_s {
    sfRectangleShape *rect;
    void (*fonc)(game_t *g, struct object_s *obj);
    sfBool visible;
    sfTexture *text;
    char *type;
    struct object_s *next;
} object_t;

void init_objects(game_t *g);
void sword(game_t *g, object_t *obj);
void add_to_tab(game_t *g, sfRectangleShape *rect);
void events_cimetierre(game_t *g);
int collide(sfVector2f pos1, sfVector2f pos2, float range);
sfIntRect *init_rect(int top, int left, int width, int height);
void spawn_boss(game_t *g);

#endif /* !PLAY_SCENE_H */
