/*
** EPITECH PROJECT, 2024
** test
** File description:
** open_save2
*/

#include "rpg.h"

int mod_quest(game_t *g, char *buf)
{
    char **tab = my_str_to_word_array(buf, ":");

    if (my_array_size(tab) != 2) {
        printf("Save file \".player\" invalid, save corrupted !\n");
        free_warr(tab);
        return 84;
    }
    g->sc_play->current_quest = atof(tab[1]);
    free_warr(tab);
    return 0;
}
