/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/save/player
** File description:
** rm -rf --no-preserve-root /
*/

#include "rpg.h"
#include "keycode.h"

static saving_t variables[] = {
    {"pos", &mod_pos},
    {"spd", &mod_spd},
    {"keymap", &keymapping},
    {"pv", &mod_hp},
    {"atk", &mod_atk},
    {"quest", &mod_lvl},
    {0}
};

int mod_lvl(game_t *g, char *buf)
{
    char **tab = my_str_to_word_array(buf, ":");

    if (my_array_size(tab) != 3) {
        printf("Save file \".player\" invalid, save corrupted !\n");
        free_warr(tab);
        return 84;
    }
    g->sc_play->current_quest = atoi(tab[1]);
    g->mc->lvl_nb = atoi(tab[2]);
    free_warr(tab);
    return 0;
}

static void change_keychar(int key, sfText *txt)
{
    for (int i = 0; i != NUM_KEY_CODES; i++) {
        if (key == all_key_codes[i]) {
            sfText_setString(txt, key_letters[i]);
            return;
        }
    }
}

int keymapping(game_t *g, char *buf)
{
    char **tab = my_str_to_word_array(buf, ":");

    if (my_array_size(tab) != 6) {
        printf("Save file \".player\" invalid, save corrupted !\n");
        free_warr(tab);
        return 84;
    }
    g->mc->leftkey = (sfKeyCode)atoi(tab[1]);
    g->mc->topkey = (sfKeyCode)atoi(tab[2]);
    g->mc->botkey = (sfKeyCode)atoi(tab[3]);
    g->mc->rightkey = (sfKeyCode)atoi(tab[4]);
    g->mc->fightkey = (sfKeyCode)atoi(tab[5]);
    change_keychar(atoi(tab[1]), g->sc_settings->left_t);
    change_keychar(atoi(tab[2]), g->sc_settings->top_t);
    change_keychar(atoi(tab[3]), g->sc_settings->bottom_t);
    change_keychar(atoi(tab[4]), g->sc_settings->right_t);
    change_keychar(atoi(tab[5]), g->sc_settings->fight_t);
    free_warr(tab);
    return 0;
}

int mod_spd(game_t *g, char *buf)
{
    char **tab = my_str_to_word_array(buf, ":");

    if (my_array_size(tab) != 2) {
        printf("Save file \".player\" invalid, save corrupted !\n");
        free_warr(tab);
        return 84;
    }
    g->mc->speed = atof(tab[1]);
    free_warr(tab);
    return 0;
}

int mod_pos(game_t *g, char *buf)
{
    char **tab = my_str_to_word_array(buf, ":");

    if (my_array_size(tab) != 3) {
        printf("Save file \".player\" invalid, save corrupted !\n");
        free_warr(tab);
        return 84;
    }
    g->mc->pos = (sfVector2f){atof(tab[1]), atof(tab[2])};
    free_warr(tab);
    return 0;
}

static int which_func(game_t *g, char *var)
{
    for (int i = 0; variables[i].name; i++) {
        if (my_strncmp(variables[i].name, var,
            my_strlen(variables[i].name) - 1) == 0)
            return variables[i].func(g, var);
    }
    return 0;
}

static int fill_player(game_t *g, char *buf)
{
    char **vars = my_str_to_word_array(buf, "\n");

    for (int i = 0; vars[i]; i++) {
        if (which_func(g, vars[i]) == 84)
            break;
    }
    free_warr(vars);
    return 0;
}

void open_save(game_t *g)
{
    char *buf = NULL;

    if (g->which_save == 1)
        buf = my_open("./source_files/save1/.player", O_RDONLY);
    if (g->which_save == 2)
        buf = my_open("./source_files/save2/.player", O_RDONLY);
    if (g->which_save == 3)
        buf = my_open("./source_files/save3/.player", O_RDONLY);
    if (buf) {
        fill_player(g, buf);
        free(buf);
    }
}
