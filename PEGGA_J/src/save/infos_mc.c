/*
** EPITECH PROJECT, 2024
** src/save/infos_mc
** File description:
** vim > emacs
*/

#include "rpg.h"

int mod_hp(game_t *g, char *buf)
{
    char **tab = my_str_to_word_array(buf, ":");

    if (my_array_size(tab) != 2) {
        printf("Save file \".player\" invalid, save corrupted !\n");
        free_warr(tab);
        return 84;
    }
    g->mc->hp_nb = atoi(tab[1]);
    free_warr(tab);
    return 0;
}

int mod_atk(game_t *g, char *buf)
{
    char **tab = my_str_to_word_array(buf, ":");

    if (my_array_size(tab) != 2) {
        printf("Save file \".player\" invalid, save corrupted !\n");
        free_warr(tab);
        return 84;
    }
    g->mc->AD = atoi(tab[1]);
    free_warr(tab);
    return 0;
}
