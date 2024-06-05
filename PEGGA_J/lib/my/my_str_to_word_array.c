/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "include/my.h"
#include <stdlib.h>

static int is_not_lim(char cmp, char *lim)
{
    for (int i = 0; lim[i]; i++) {
        if (cmp == lim[i])
            return (0);
    }
    return (1);
}

static int count_words(char const *str, char *lim)
{
    int count = 1;

    for (int i = 1; str[i]; i++) {
        if (is_not_lim(str[i], lim) == 1 &&
            is_not_lim(str[i - 1], lim) != 1)
            count++;
    }
    return (count);
}

static int word_size(char const *str, char *lim)
{
    int i = 0;

    for (; str[i] && is_not_lim(str[i], lim); i++);
    return (i);
}

char **my_str_to_word_array(char const *str, char *lim)
{
    int nb_words = count_words(str, lim);
    int i = 0;
    int ind = 0;
    int wrds = 0;
    char **array = malloc((nb_words + 1) * sizeof(char *));

    while (i < my_strlen(str)) {
        if (is_not_lim(str[i], lim) == 1) {
            wrds = word_size(&str[i], lim);
            array[ind] = malloc(sizeof(char) * (wrds + 1));
            my_strncpy(array[ind], &(str[i]), wrds);
            array[ind][wrds] = '\0';
            i += wrds;
            ind++;
        } else
            i++;
    }
    array[ind] = NULL;
    return (array);
}
