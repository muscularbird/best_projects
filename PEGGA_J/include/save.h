/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/include/save
** File description:
** vim-epitech made by x4m3
*/

#ifndef SAVE_H
    #define SAVE_H

typedef struct saving_s {
    char *name;
    int (*func)(game_t *, char *);
} saving_t;

int mod_spd(game_t *g, char *buf);
int mod_quest(game_t *g, char *buf);
int mod_pos(game_t *g, char *buf);
int keymapping(game_t *g, char *buf);
void open_save(game_t *g);
void create_save(game_t *g);
void delete_save(game_t *g);
int mod_hp(game_t *g, char *buf);
int mod_atk(game_t *g, char *buf);
int mod_lvl(game_t *g, char *buf);
#endif /* !SAVE_H */
