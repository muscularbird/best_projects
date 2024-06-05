/*
** EPITECH PROJECT, 2024
** src/inits/init_pnj
** File description:
** well, real programmers use ed
*/

#include "rpg.h"

static void apply_parameters_to_pnj(pnj_t *node)
{
    if (node->alive)
        node->anims = 32;
    else
        node->anims = 128;
    node->current_frame = 0;
    sfSprite_setOrigin(node->anim->sprite, (sfVector2f){16, 16});
    sfSprite_setPosition(node->anim->sprite, node->beg_pos);
    sfSprite_setScale(node->anim->sprite, (sfVector2f){node->k, node->k});
    sfCircleShape_setPosition(node->area, node->beg_pos);
    sfCircleShape_setRadius(node->area, node->r);
    sfCircleShape_setOrigin(node->area, (sfVector2f){160, 160});
    sfCircleShape_setFillColor(node->area, sfTransparent);
}

static animation_t *what_spritesheet(char *index)
{
    if (strcmp("skeleton", index) == 0)
        return create_animation(SKELETON);
    if (strcmp("goblin", index) == 0)
        return create_animation(GOBLIN);
    if (strcmp("orc", index) == 0)
        return create_animation(ORC);
    if (!strcmp("slime", index))
        return create_animation(SLIME);
    return (void *)0;
}

static void add_pnj_life(pnj_t *mob, game_t *g)
{
    mob->mob_scale = sfSprite_getScale(mob->anim->sprite);
    mob->lifebat_texture = sfTexture_createFromFile(LIFEBAR, NULL);
    mob->bck_lifebat_tx = sfTexture_createFromFile(BCK_LIFEBAR, NULL);
    mob->lifebar = sfRectangleShape_create();
    sfRectangleShape_setTexture(mob->lifebar, mob->lifebat_texture, 0);
    sfRectangleShape_setSize(mob->lifebar,
    ch_coor((sfVector2f){30 * mob->mob_scale.x, 3 * mob->mob_scale.y},
    g->w_size));
    sfRectangleShape_setPosition(mob->lifebar,
    ch_coor((sfVector2f){mob->cu_pos.x, mob->cu_pos.y -
    (20 * mob->mob_scale.y)},
    g->w_size));
    sfRectangleShape_setOrigin(mob->lifebar,
    ch_coor((sfVector2f){sfRectangleShape_getSize(mob->lifebar).x / 2,
    sfRectangleShape_getSize(mob->lifebar).y / 2}, g->w_size));
    mob->bck_lifebar = sfRectangleShape_copy(mob->lifebar);
    sfRectangleShape_setTexture(mob->bck_lifebar, mob->bck_lifebat_tx, 0);
    mob->size_life_bar = 30 * mob->mob_scale.x;
    mob->start_life = mob->HP;
}

static void fill_node(pnj_t **node, char **tab)
{
    (*node)->beg_pos = (sfVector2f){atoi(tab[0]), atoi(tab[1])};
    (*node)->traj = (sfVector2f){0, 0};
    (*node)->speed = atof(tab[2]);
    (*node)->r = atof(tab[3]);
    (*node)->k = atof(tab[4]);
    (*node)->anim = what_spritesheet(tab[5]);
    (*node)->cu_pos = sfSprite_getPosition((*node)->anim->sprite);
    (*node)->norm = 0.0;
    (*node)->statement = sfFalse;
    (*node)->HP = atoi(tab[6]);
    (*node)->alive = (sfBool)atoi(tab[7]);
    (*node)->area = sfCircleShape_create();
    apply_parameters_to_pnj((*node));
    (*node)->type = strdup(tab[5]);
}

void add_pnj(pnj_t **lst, const char *buffer, game_t *g)
{
    char **tab = my_str_to_word_array(buffer, " ");
    pnj_t *node = malloc(sizeof(pnj_t));

    fill_node(&node, tab);
    apply_parameters_to_pnj(node);
    add_pnj_life(node, g);
    node->next = *lst;
    *lst = node;
    free_warr(tab);
}

void init_pnj(game_t *g)
{
    FILE *fd = NULL;
    char *buffer = NULL;
    size_t len = 0;

    g->pnj = NULL;
    fd = fopen("./source_files/.pnj.txt", "r");
    if (!fd) {
        printf("cannot open source_file \".pnj.txt\"\n");
        return;
    }
    while (getline(&buffer, &len, fd) != -1) {
        add_pnj(&g->pnj, buffer, g);
    }
    free(buffer);
    fclose(fd);
}
