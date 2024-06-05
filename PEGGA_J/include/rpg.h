/*
** EPITECH PROJECT, 2024
** include/erhpehgeh.h
** File description:
** no, real programmers use cat
*/

#ifndef MY_RPG_H
    #define MY_RPG_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>
    #include "animation.h"
    #include "func_scene.h"
    #include "my.h"
    #include "play.h"
    #include "main_character.h"
    #include "pnj.h"
    #include "save.h"
    #include "boss.h"
    #include <string.h>
    #include <stdbool.h>

int error_message(char *message);
void my_puterror(char c);

////////////////sprite////////////////
    #define NB_ANIMATIONS 5

////////////////music////////////////
    #define MUSIC "./assets/the-white-lion-10379.ogg"
    #define MUSIC2 "./assets/Handsome_Pose_Collection.ogg"
    #define SOUND_BTN "./assets/click.ogg"

void event_sound(game_t *g);
void play_sound(game_t *g);

typedef struct music_s {
    sfMusic *main_music;
    sfMusic *main_music2;
    sfMusic *sound;
    sfTime start_time;
    float music_volume;
    float sound_volume;
    float prev_vol;
    float prev_sound_vol;
} music_t;

typedef struct spri_s {
    animation_t *animations[NB_ANIMATIONS];
    unsigned int current_animation;
} spri_t;

////////////////menus////////////////
typedef enum menu_e {
    START,
    DEATH,
    SETTINGS,
    PAUSE,
    PLAY,
    SAVE,
    BOSS,
    START_LORE,
    SCENE_COUNT
} menu_t;

    #define NB_MENUS SCENE_COUNT

////////////////game////////////////

typedef struct game_s game_t;

typedef struct func_menu_s {
    void (*init)(game_t *game);
    void (*event)(game_t *game);
    void (*update)(game_t *game);
    void (*draw)(game_t *game);
    void (*destroy)(game_t *game);
} func_menu_t;

typedef struct game_s {
    sfRenderWindow *window;
    func_menu_t menus[NB_MENUS];
    sfEvent event;
    sfVector2f w_size;
    animation_t *animation;
    main_char_t *mc;
    pnj_t *pnj;
    menu_t current_scene;
    menu_t previous_scene;
    menu_t next_scene;
    scene_start_t *sc_st;
    scene_pause_t *sc_pau;
    scene_save_t *sc_save;
    scene_play_t *sc_play;
    boss_sc_t *sc_boss;
    scene_settings_t *sc_settings;
    lore_t *sc_lore;
    sfVector2f mouse_pos;
    sfImage *back_map;
    sfTexture *map_text;
    sfSprite *map_sp;
    music_t *music;
    sfRectangleShape *opacity;
    sfFont *font;
    sfClock *clock;
    sfBool click;
    sfView *global_POV;
    dth_sc_t *dth_sc;
    sfTime save;
    sfTexture *cursor_txt;
    sfSprite *cursor;
    sfTexture *txt_map_up;
    sfSprite *map_up;
    sfImage *icon;
    ADM_t *adm;
    object_t *object;
    int which_save;
    int debug;
} game_t;

void fade_transition(game_t *g, menu_t m, char *i1, char *i2);
#endif
