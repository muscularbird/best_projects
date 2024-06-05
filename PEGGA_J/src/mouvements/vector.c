/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** vector
*/

#include "rpg.h"

float distance(sfVector2f a, sfVector2f b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

void isnear(game_t *g, sfVector2f pos1, int quest)
{
    sfVector2f pos2;
    float distance = 0.0;
    ADM_t *tmp = g->adm;

    while (tmp) {
        pos2 = tmp->pos;
        distance = sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
        if (distance < 30 && !tmp->finish && quest == tmp->index_quest) {
            g->sc_play->near_adm = sfFalse;
            tmp->statement = sfTrue;
            g->sc_play->current_game = DIALOGUES;
            tmp->display_complete = sfFalse;
        }
        tmp = tmp->next;
    }
}

int calc_len_dialogue(char **tab)
{
    int j = 0;

    for (int i = 7; tab[i]; i++)
        j++;
    return j;
}

sfVector2f vector_sub(sfVector2f a, sfVector2f b)
{
    sfVector2f result;

    result.x = (a.x - b.x);
    result.y = (a.y - b.y);
    if (result.x <= 0)
        result.x += 16;
    else
        result.x -= 16;
    return result;
}

void orientation(sfSprite *sp, sfVector2f pnj_pos, sfVector2f mc_pos, float k)
{
    if (pnj_pos.x <= mc_pos.x) {
        sfSprite_setScale(sp, (sfVector2f){k, k});
    } else
        sfSprite_setScale(sp, (sfVector2f){-k, k});
}
