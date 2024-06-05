/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** adm
*/

#include "rpg.h"

char **create_dialogue(char **tab, ADM_t *a)
{
    int j = 7;
    int len = calc_len_dialogue(tab);
    char **dialogue = malloc(sizeof(char *) * (len + 1));

    a->len = len;
    for (int i = 0; i != len; i++) {
        dialogue[i] = strdup(tab[j]);
        j++;
    }
    dialogue[len] = NULL;
    return dialogue;
}

static menu_play_t which_enum(char const *str)
{
    if (!strcmp("NOTHING", str))
        return NORMAL;
    if (!strcmp("PETANQUE", str))
        return PETANQUE;
    if (!strcmp("JONA_MJ", str))
        return JONA_MJ;
    if (!strcmp("SKATE", str))
        return SKATER;
    return NORMAL;
}

static void add_adm2(game_t *g, ADM_t *node, char **tab)
{
    node->pp = sfSprite_create();
    node->image_pp = sfTexture_createFromFile(tab[5], NULL);
    sfSprite_setTexture(node->pp, node->image_pp, sfFalse);
    sfSprite_setScale(node->pp, (sfVector2f){0.08, 0.08});
    sfSprite_setOrigin(node->pp, (sfVector2f){225, 225});
    sfSprite_setPosition(node->pp,
    (sfVector2f){node->pos.x + 140, node->pos.y + 70});
    sfSprite_setScale(node->a->sprite,
    (sfVector2f){atof(tab[3]), atof(tab[3])});
    sfSprite_setOrigin(node->a->sprite, (sfVector2f){16, 16});
    node->statement = sfFalse;
    node->finish = sfFalse;
    node->index = 0;
    node->mj = which_enum(tab[6]);
    sfSprite_setPosition(node->a->sprite, node->pos);
    node->next = g->adm;
    g->adm = node;
    free_warr(tab);
}

static void add_adm(game_t *g, char *buffer, int nb)
{
    char **tab = my_str_to_word_array(buffer, ":");
    ADM_t *node = malloc(sizeof(ADM_t));

    if (my_array_size(tab) <= 1)
        return;
    node->pos = (sfVector2f){atoi(tab[1]), atoi(tab[2])};
    node->index_quest = nb;
    node->text = sfText_create();
    node->a = create_animation(tab[4]);
    node->dialogue = create_dialogue(tab, node);
    node->texture_back = sfTexture_createFromFile(BULLE, NULL);
    node->back_text = sfSprite_create();
    node->name = strdup(tab[0]);
    sfSprite_setTexture(node->back_text, node->texture_back, sfFalse);
    sfSprite_setScale(node->back_text, (sfVector2f){1.20, 0.25});
    sfSprite_setOrigin(node->back_text, (sfVector2f){373.5, 100});
    sfSprite_setPosition(node->back_text,
    (sfVector2f){node->pos.x, node->pos.y + 70});
    node->display_complete = sfFalse;
    add_adm2(g, node, tab);
}

void init_adm(game_t *g)
{
    FILE *fd = NULL;
    char *buffer = NULL;
    size_t len = 0;
    static int cp = 0;

    g->adm = NULL;
    fd = fopen("./source_files/adm.txt", "r");
    if (!fd) {
        printf("cannot open source_file \"adm.txt\"\n");
        return;
    }
    while (getline(&buffer, &len, fd) != -1) {
        if (strcmp("null\n", buffer) != 0) {
            add_adm(g, buffer, cp);
            cp++;
        }
    }
    free(buffer);
    fclose(fd);
}

void update_variable_2(game_t *g, ADM_t *a)
{
    if (a->index_quest == 0 || a->index_quest == 8) {
        g->sc_play->current_quest++;
        g->mc->lvl_nb++;
    }
}

void update_variables(ADM_t *adm, game_t *g)
{
    ADM_t *a = adm;

    while (a) {
        if (a->statement && !a->finish && a->display_complete) {
            a->index = (a->index + 1) % a->len;
            a->display_complete = sfFalse;
        }
        if (a->index == a->len - 1 && a->finish) {
            a->index++;
            update_variable_2(g, a);
            g->sc_play->current_game = a->mj;
        }
        a = a->next;
    }
}
