/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/save/create_save
** File description:
** try not to segfault, good luck :)
*/

#include "rpg.h"

static int create_save_pnj2(game_t *g)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int flags = O_WRONLY | O_CREAT | O_TRUNC;
    int fd = 0;

    if (g->which_save == 1)
        fd = open("./source_files/save1/.pnj.txt", flags, mode);
    if (g->which_save == 2)
        fd = open("./source_files/save2/.pnj.txt", flags, mode);
    if (g->which_save == 3)
        fd = open("./source_files/save3/.pnj.txt", flags, mode);
    return fd;
}

static void create_save_pnj(game_t *g)
{
    int fd = create_save_pnj2(g);
    pnj_t *tmp = g->pnj;

    if (fd <= 0) {
        printf("error, cannot create save file");
        return;
    }
    while (tmp) {
        dprintf(fd, "%f %f %f %f %f %s %d %d\n",
            tmp->cu_pos.x, tmp->cu_pos.y, tmp->speed, tmp->r, tmp->k,
            tmp->type, tmp->HP, tmp->alive);
        tmp = tmp->next;
    }
    close(fd);
}

static int create_save_objects2(game_t *g)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int flags = O_WRONLY | O_CREAT | O_TRUNC;
    int fd = 0;

    if (g->which_save == 1)
        fd = open("./source_files/save1/objects.txt", flags, mode);
    if (g->which_save == 2)
        fd = open("./source_files/save2/objects.txt", flags, mode);
    if (g->which_save == 3)
        fd = open("./source_files/save3/objects.txt", flags, mode);
    return fd;
}

static void create_save_objects(game_t *g)
{
    int fd = create_save_objects2(g);
    object_t *tmp = g->object;
    sfVector2f pos = {0, 0};

    if (fd <= 0) {
        printf("error, cannot create save file");
        return;
    }
    while (tmp) {
        pos = sfRectangleShape_getPosition(tmp->rect);
        dprintf(fd, "%f %f %s %d\n", pos.x, pos.y, tmp->type, tmp->visible);
        tmp = tmp->next;
    }
    close(fd);
}

static int create_save2(game_t *g)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int flags = O_WRONLY | O_CREAT | O_TRUNC;
    int fd = 0;

    if (g->which_save == 1)
        fd = open("./source_files/save1/.player", flags, mode);
    if (g->which_save == 2)
        fd = open("./source_files/save2/.player", flags, mode);
    if (g->which_save == 3)
        fd = open("./source_files/save3/.player", flags, mode);
    return fd;
}

void create_save(game_t *g)
{
    int fd = create_save2(g);

    if (fd <= 0) {
        printf("error, cannot create save file");
        return;
    }
    dprintf(fd, "spd:%f\npos:%f:%f\n",
        g->mc->speed, g->mc->pos.x, g->mc->pos.y);
    dprintf(fd, "keymap:%d:%d:%d:%d:%d\n", g->mc->leftkey, g->mc->topkey,
        g->mc->botkey, g->mc->rightkey, g->mc->fightkey);
    dprintf(fd, "quest:%d:%d\n", g->sc_play->current_quest, g->mc->lvl_nb);
    dprintf(fd, "atk:%d\n", g->mc->AD);
    dprintf(fd, "pv:%d", g->mc->hp_nb);
    close(fd);
    create_save_pnj(g);
    create_save_objects(g);
}
