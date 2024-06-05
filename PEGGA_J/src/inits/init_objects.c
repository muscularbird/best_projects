/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** init_objects
*/

#include "rpg.h"

void shield(game_t *g, object_t *obj)
{
    if (obj->visible)
        add_to_tab(g, obj->rect);
    g->mc->hp_nb += 20;
    obj->visible = sfFalse;
}

void sword(game_t *g, object_t *obj)
{
    if (obj->visible)
        add_to_tab(g, obj->rect);
    g->mc->AD += 20;
    obj->visible = sfFalse;
}

static int verif_type(object_t *obj, char **tab)
{
    obj->type = strdup(tab[2]);
    if (strncmp(tab[2], "shield", 6) == 0) {
        obj->text = sfTexture_createFromFile("./assets/shield.png", NULL);
        sfRectangleShape_setTexture(obj->rect, obj->text, 0);
        obj->fonc = &shield;
    } else if (strncmp(tab[2], "sword", 5) == 0) {
        obj->text = sfTexture_createFromFile("./assets/sword.png", NULL);
        sfRectangleShape_setTexture(obj->rect, obj->text, 0);
        obj->fonc = &sword;
    } else
        return 84;
    return 0;
}

static void add_object(game_t *g, char *buff)
{
    char **tab = my_str_to_word_array(buff, " ");
    object_t *node = NULL;

    if (my_array_size(tab) != 4) {
        free_warr(tab);
        return;
    }
    node = malloc(sizeof(object_t));
    node->rect = sfRectangleShape_create();
    node->visible = (sfBool)(atoi(tab[3]));
    sfRectangleShape_setOrigin(node->rect, (sfVector2f){8, 8});
    sfRectangleShape_setPosition(node->rect,
    (sfVector2f){atof(tab[0]), atof(tab[1])});
    sfRectangleShape_setSize(node->rect,
    ch_coor((sfVector2f){50, 50}, g->w_size));
    if (verif_type(node, tab) == 84)
        return;
    node->next = g->object;
    g->object = node;
    free_warr(tab);
}

static void set_in_inv(game_t *g)
{
    object_t *tmp = g->object;

    while (tmp) {
        if (!(tmp->visible))
            add_to_tab(g, tmp->rect);
        tmp = tmp->next;
    }
}

void init_objects(game_t *g)
{
    FILE *fd = NULL;
    char *buffer = NULL;
    size_t len = 0;

    g->mc->full_inv = malloc(sizeof(sfRectangleShape *) * 8);
    for (int i = 0; i < 8; i++)
        g->mc->full_inv[i] = NULL;
    g->object = NULL;
    fd = fopen("./source_files/objects.txt", "r");
    if (!fd) {
        printf("cannot open source_file \"objects.txt\"\n");
        return;
    }
    while (getline(&buffer, &len, fd) != -1) {
        add_object(g, buffer);
    }
    set_in_inv(g);
    free(buffer);
    fclose(fd);
}
