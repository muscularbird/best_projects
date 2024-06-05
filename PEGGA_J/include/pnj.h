/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** pnj
*/

#ifndef PNJ_H_
    #define PNJ_H_
    #include "rpg.h"
    #include "main_character.h"
    #include "func_scene.h"
    #include "play.h"
    #include <stdbool.h>

    #define SLIME "./assets/slime.png"
    #define GOBLIN "./assets/goblin.png"
    #define SKELETON "./assets/skeleton.png"
    #define ORC "./assets/orc.png"
    #define DELAY_DIALOGUE 0.01f
    #define BULLE "./assets/dialogue_barree.png"


typedef struct pnj_s {
    sfVector2f beg_pos;
    sfVector2f cu_pos;
    sfVector2f traj;
    float speed;
    float r;
    float k;
    float norm;
    float time;
    sfCircleShape *area;
    sfBool statement;
    sfBool alive;
    int HP;
    int anims;
    int current_frame;
    animation_t *anim;
    sfTexture *lifebat_texture;
    sfRectangleShape *lifebar;
    sfTexture *bck_lifebat_tx;
    sfRectangleShape *bck_lifebar;
    float size_life_bar;
    float start_life;
    sfVector2f mob_scale;
    char *type;
    struct pnj_s *next;
} pnj_t;

typedef enum menu_play_e menu_play_t;

typedef struct ADM_s {
    sfVector2f pos;
    sfBool statement;
    char *name;
    sfText* text;
    sfTexture *texture_back;
    sfSprite *back_text;
    char **dialogue;
    animation_t *a;
    int index;
    int len;
    sfBool display_complete;
    sfBool finish;
    sfTexture *image_pp;
    sfSprite *pp;
    int index_quest;
    menu_play_t mj;
    struct ADM_s *next;
} ADM_t;

void init_pnj(game_t *g);
void update_pnj_anim(pnj_t **lst, float delta);
void update_pnj_statement(pnj_t **lst, game_t *g);
sfVector2f vector_sub(sfVector2f a, sfVector2f b);
void collide_into_pnj_and_mc(pnj_t **lst, game_t *g);
void orientation(sfSprite *sp, sfVector2f, sfVector2f, float);
int calc_len_dialogue(char **tab);
void init_adm(game_t *g);
void free_pnj(pnj_t **now);
void isnear(game_t *g, sfVector2f pos, int quest);
void draw_dialogue(ADM_t *adm, game_t *g);
void display_dialogue(game_t *g);
const char *substring(const char *str, int start, int end);
void update_adm_anim(game_t *g, float delta);
bool is_pnj_walk(sfImage *image, sfVector2f pos);
void add_pnj(pnj_t **lst, const char *buffer, game_t *g);
void draw_ennemies3(game_t *g, pnj_t *tmp);
#endif /* !PNJ_H_ */
