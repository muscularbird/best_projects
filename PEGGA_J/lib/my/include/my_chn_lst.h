/*
** EPITECH PROJECT, 2023
** chn_lst
** File description:
** chn_lst
*/

#ifndef MY_LST_CHN_H
    #define MY_LST_CHN_H
    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef struct chn_lst_s {
    void *data;
    struct chn_lst_s *next;
} chn_lst_t;

void my_add_node(chn_lst_t **begin, void *data);
void my_add_node_first(chn_lst_t **begin, void *data);
int my_delete_nodes(chn_lst_t **begin, void const *data_ref);
chn_lst_t *my_find_node(chn_lst_t *begin, void const *data_ref);
int my_list_size(chn_lst_t const *begin);
void my_show_list(chn_lst_t const *begin, int(*p)());
void my_free_list(chn_lst_t **begin);
#endif
