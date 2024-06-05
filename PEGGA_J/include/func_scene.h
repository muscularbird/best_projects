/*
** EPITECH PROJECT, 2024
** MY_game
** File description:
** draw.h
*/

#ifndef SCENE_H
    #define SCENE_H
    #include "rpg.h"

typedef struct game_s game_t;

//////boutons////////

    #define START_MENU "./assets/background_menu.png"
    #define PLAY_BTN "./assets/play.png"
    #define SETTINGS_BTN "./assets/settings.png"
    #define CLOSE "./assets/close.png"
    #define PAUSE_BTN "./assets/pause.png"
    #define BACK_SETTINGS "./assets/background_menu_settings.png"
    #define NO_MUSIC_BTN "./assets/no_music.png"
    #define MUSIC_BTN "./assets/music.png"
    #define SOUND_LOUD_BTN "./assets/sound_loud.png"
    #define SOUND_LOW_BTN "./assets/sound_low.png"
    #define NO_SOUND_BTN "./assets/no_sound.png"
    #define BAR "./assets/bar.png"
    #define Y_BAR "./assets/bar_yellow.png"
    #define INFO_BTN "./assets/info_button.png"
    #define LEFT "./assets/left-row.png"
    #define BOTTOM "./assets/bottom-row.png"
    #define TOP "./assets/top-row.png"
    #define RIGHT "./assets/right-row.png"
    #define FIGHT_IMG "./assets/fight2.png"
    #define FONT "./assets/DalelandsUncialItalic-vG2L.ttf"
    #define WDW_SIZE "./assets/window_size.png"
    #define FULLSCREEN "./assets/full_screen.png"
    #define MEDIUM_WDW "./assets/1280x720.png"
    #define BIG_WDW "./assets/1920x1080.png"
    #define BCK_MNU "./assets/background_menu.png"
    #define COLL_MAP "./assets/collision_map.png"
    #define LOGO "./assets/logo.png"
    #define CURSOR "./assets/cursor.png"
    #define MAP_UP "./assets/map_up.png"
    #define NB_OF_RAINS_DROPS 500
    #define MILION 1000000.0f
    #define PI 3.1415926535897932384626433832795028841971693993751058209749445
    #define TARGET_PNG "./assets/target.png"
    #define PET_BACK "./assets/petanque_back.jpeg"
    #define LIFE_HEART "./assets/corazon.png"
    #define TOWER_SRC "./assets/tower.png"
    #define SAVE_BTN "./assets/save.png"
    #define RETRY "./assets/retry.png"
    #define BEIGE "./assets/beige.png"
    #define BRUN "./assets/brun.jpg"
    #define BOSS_MAP "./assets/Map_boss.jpg"
    #define ANIM_BOSS "./assets/boss.png"
    #define BACK_BOSS "./assets/boss_colmap.png"
    #define USAGE_SRC "./assets/usage.png"
    #define DEL_SAVE "./assets/del_save.png"
    #define CHANGE_SAVE "./assets/change_save.png"
    #define ENTER_SAVE "./assets/enter_save.png"

void init_game(game_t *g);
void init_music(game_t *g);

typedef enum button_state {
    DESACTIVATE = 0,
    NONE,
    PRESSED,
    HOVER
} button_state_t;

typedef struct loop_s {
    sfTexture *text;
    sfEvent event;
} loop_t;

typedef struct button_s {
    sfCircleShape *circle;
    sfRectangleShape *rect;
    float circle_size;
    sfVector2f rect_size;
    sfFloatRect hitb;
    button_state_t state;
    int id;
    sfText *text;
    sfTexture *texture;
    sfColor color;
    void (*button_fonc)(game_t *g, struct button_s *btn);
    struct button_s *next;
} button_t;

void add_node(button_t *new_node, button_t **button);

typedef struct fonc_par_s {
    char *src;
    sfVector2f pos;
    sfVector2f rect_size;
    float circle_size;
    void (*fonc)(game_t *g, button_t *btn);
    int id;
} fonc_par_t;

void disable_button(button_t **btn, int id);
void enable_button(button_t **btn, int id);

void menu_save(game_t *g, button_t *btn);
void enter_save(game_t *g, button_t *btn);
void register_save(game_t *g, button_t *btn);
void del_save(game_t *g, button_t *btn);
void circle_btn(button_t **button, fonc_par_t par);
void rect_btn(button_t **button, fonc_par_t par);
void draw_button(game_t *g, button_t *btn);
void play(game_t *g, button_t *btn);
void init_inv_scene(game_t *g);
void pause_af(game_t *g, button_t *btn);
void my_close(game_t *g, button_t *btn);
void close_settings(game_t *g, button_t *btn);
void settings_f(game_t *g, button_t *btn);
void set_button_state(sfEvent event, game_t *g, button_t *tmp);
void event_button(button_t *btn, game_t *g);
void no_music_f(game_t *g, button_t *btn);
void no_sound_f(game_t *g, button_t *btn);
void sound_f(game_t *g, button_t *btn);
void music_f(game_t *g, button_t *btn);
void eevent_button(game_t *g, button_t *btn, sfEvent event);
void info_f(game_t *g, button_t *btn);
void binding_top(game_t *g, button_t *btn);
void binding_bottom(game_t *g, button_t *btn);
void binding_left(game_t *g, button_t *btn);
void binding_right(game_t *g, button_t *btn);
void binding_fight(game_t *g, button_t *btn);
void window_size(game_t *g, button_t *btn);
void full_screen(game_t *g, button_t *btn);
void medium_window(game_t *g, button_t *btn);
void big_window(game_t *g, button_t *btn);
sfVector2f ch_coor(sfVector2f coor, sfVector2f w_size);
void restart_pet(game_t *g, button_t *btn);
void close_pet(game_t *g, button_t *btn);
void restart(game_t *g, button_t *btn);
void close_sk(game_t *g, button_t *btn);
void restart_sk(game_t *g, button_t *btn);
void draw_normal_tr(game_t *g);
void draw_save_scene_tr(game_t *g);
void draw_death_tr(game_t *g);
void draw_start_scene_tr(game_t *g);
void draw_lore_tr(game_t *g);

///////start scene/////////////

void init_start_scene(game_t *game);
void events_start_scene(game_t *game);
void update_start_scene(game_t *game);
void draw_start_scene(game_t *game);
void free_start_scene(game_t *game);

typedef struct spri_s spri_t;

typedef struct rain_s {
    sfVertex line[2];
    float speed;
} rain_t;

typedef struct scene_start_s {
    sfEvent event;
    button_t *button;
    sfTexture *texture_logo;
    sfSprite *logo;
    sfTexture *back_texture;
    sfSprite *back_sprite;
    sfTexture *menu_texture;
    sfSprite *menu_sprite;
    sfVector2f pos;
    rain_t rain[NB_OF_RAINS_DROPS];
} scene_start_t;

///////pause scene/////////////

void init_pause_scene(game_t *game);
void events_pause_scene(game_t *game);
void update_pause_scene(game_t *game);
void draw_pause_scene(game_t *game);
void free_pause_scene(game_t *game);

typedef struct scene_pause_s {
    sfEvent event;
    button_t *button;
    sfTexture *back_texture;
    sfSprite *back_sprite;
    sfTexture *menu_texture;
    sfSprite *menu_sprite;
    sfVector2f pos;
    sfBool is_pause;
    sfText *stat;
    sfText *quest;
    sfSprite *bck_inv;
    sfSprite *bck_stat;
    sfTexture *beige_txt;
    sfTexture *brown_txt;
    sfText **quests;
    sfText **stats;
    sfSprite *mc;
    sfText *name;
    sfRectangleShape *outline_name;
    int cp;
} scene_pause_t;

///////save scene/////////////

void init_save_scene(game_t *game);
void events_save_scene(game_t *game);
void update_save_scene(game_t *game);
void draw_save_scene(game_t *game);
void free_save_scene(game_t *game);

typedef struct saves_text_s {
    sfRectangleShape *sqa;
    sfTexture *texture;
    sfText *text;
} saves_text_t;

typedef struct scene_save_s {
    button_t *button;
    sfTexture *texture_logo;
    sfTexture *back_texture;
    sfTexture *menu_texture;
    sfSprite *logo;
    sfSprite *back_sprite;
    sfSprite *menu_sprite;
    sfVector2f pos;
    saves_text_t *saves[3];
} scene_save_t;

///////settings scene/////////////

void init_set_scene(game_t *game);
void events_set_scene(game_t *game);
void update_set_scene(game_t *game);
void draw_set_scene(game_t *game);
void free_set_scene(game_t *game);
void event_cursor_music(game_t *g);
void init_buttons_scene(game_t *g);

typedef struct scene_settings_s {
    sfEvent event;
    button_t *button;
    button_t *mus_button;
    button_t *sound_button;
    sfTexture *back_texture;
    sfSprite *back_sprite;
    sfTexture *menu_texture;
    sfSprite *menu_sprite;
    sfVector2f pos;
    sfTexture *mus_texture;
    sfTexture *no_mus_texture;
    sfTexture *sound_texture;
    sfTexture *no_sound_texture;
    sfRectangleShape *sound_bar;
    sfRectangleShape *sound_y_bar;
    sfRectangleShape *mus_bar;
    sfRectangleShape *mus_y_bar;
    sfTexture *bar_texture;
    sfTexture *ybar_texture;
    sfBool pressed;
    sfBool released;
    sfFloatRect hitbox_mus;
    sfFloatRect hitbox_sound;
    sfText *left_t;
    sfText *right_t;
    sfText *top_t;
    sfText *bottom_t;
    sfText *fight_t;
    sfBool top;
    sfBool bottom;
    sfBool right;
    sfBool left;
    sfBool fight;
    button_t *w_size;
    sfBool window_size;
    sfBool info;
    sfSprite *info_sp;
    sfTexture *info_txr;
    sfText *e_text;
    sfBool err_text;
} scene_settings_t;

///////////death scene///////

void init_death(game_t *g);
void event_death(game_t *g);
void update_death(game_t *g);
void draw_death(game_t *g);
void free_death(game_t *g);

typedef struct dth_sc_s {
    button_t *btn;
    sfRectangleShape *opacity;
    sfText *text;
} dth_sc_t;

//////////start lore////////

void init_lore(game_t *g);
void draw_lore(game_t *g);
void events_lore(game_t *g);
void update_lore(game_t *g);
sfText *create_txt_lore(char const *str, game_t *g);

typedef struct lore_s {
    sfText **lore;
} lore_t;

///////////DESTROYS//////////

typedef struct pnj_s pnj_t;

void destroy_game(game_t *g);
void free_buttons(button_t **now);
void free_pnj(pnj_t **now);
void free_mc(game_t *g);
void init_rain(game_t *g);
void update_rain(game_t *g);
#endif
