/*
** EPITECH PROJECT, 2024
** free_skate
** File description:
** r/ProgrammerHumor
*/

#include "rpg.h"

void free_train(train_t *tr)
{
    if (!tr)
        return;
    sfRectangleShape_destroy(tr->sp);
    sfTexture_destroy(tr->text);
    free(tr);
}

void free_trains(game_t *g)
{
    chn_lst_t **l = &g->sc_play->sk->train;
    chn_lst_t *next = (void *)0;

    while (*l) {
        next = (*l)->next;
        free_train((train_t *)(*l)->data);
        free(*l);
        *l = next;
    }
}

void free_skate(game_t *g)
{
    free_trains(g);
    for (int i = 0; i < 3; i++)
        sfRectangleShape_destroy(g->sc_play->sk->life_tab[i]);
    free(g->sc_play->sk->life_tab);
    free_buttons(&g->sc_play->sk->btn);
    sfRectangleShape_destroy(g->sc_play->sk->bg);
    sfTexture_destroy(g->sc_play->sk->bg_t);
    sfClock_destroy(g->sc_play->sk->spawn_rate);
    sfImage_destroy(g->sc_play->sk->u_map);
    free(g->sc_play->sk);
}
