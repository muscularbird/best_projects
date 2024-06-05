/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_open
*/

#include "./include/my.h"

char *my_open(char *file, int flag)
{
    int fd = open(file, flag);
    struct stat t;
    char *res;

    if (fd <= 0)
        return (void *)0;
    if (stat(file, &t) == -1) {
        close(fd);
        return (void *)0;
    }
    res = malloc(sizeof(char) * (t.st_size + 1));
    if (!res)
        return (void *)0;
    if (read(fd, res, t.st_size) < 0) {
        free(res);
        return (void *)0;
    }
    res[t.st_size] = '\0';
    close(fd);
    return (res);
}
