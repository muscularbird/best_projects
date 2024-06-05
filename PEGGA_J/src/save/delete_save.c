/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/save/delete_save
** File description:
** check your malloc!
*/

#include "rpg.h"

static int which_pnj_save(game_t *g)
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

static void delete_save_pnj(game_t *g)
{
    int fd = which_pnj_save(g);
    char *str = my_open("./source_files/.pnj.txt", O_RDONLY);

    if (fd <= 0) {
        printf("error, cannot create save file");
        return;
    }
    dprintf(fd, "%s", str);
    close(fd);
}

static int which_obj_save(game_t *g)
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

static void delete_save_objects(game_t *g)
{
    int fd = which_obj_save(g);
    char *str = my_open("./source_files/objects.txt", O_RDONLY);

    if (fd <= 0) {
        printf("error, cannot create save file");
        return;
    }
    dprintf(fd, "%s", str);
    close(fd);
}

static int which_file_player(game_t *g)
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

void delete_save(game_t *g)
{
    int fd = which_file_player(g);
    char *str = my_open("./source_files/.player", O_RDONLY);

    dprintf(fd, "%s", str);
    close(fd);
    delete_save_pnj(g);
    delete_save_objects(g);
}
