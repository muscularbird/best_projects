/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** free_petanque
*/

#include "rpg.h"

void free_mob(game_t *g, mob_t *tmp, mob_t *prev)
{
    if (tmp == g->sc_play->pet->mob) {
        g->sc_play->pet->mob = tmp->next;
        sfRectangleShape_destroy(tmp->rect);
        sfTexture_destroy(tmp->text);
        free(tmp);
        return;
    } else {
        prev->next = tmp->next;
        sfRectangleShape_destroy(tmp->rect);
        sfTexture_destroy(tmp->text);
        free(tmp);
    }
}

void free_all_mob(game_t *g)
{
    mob_t *prev = g->sc_play->pet->mob;

    while (g->sc_play->pet->mob) {
        free_mob(g, g->sc_play->pet->mob, prev);
    }
}

void free_all_bullet(game_t *g)
{
    bowl_t *prev = g->sc_play->pet->bowl;

    while (g->sc_play->pet->bowl) {
        free_bowl(g, g->sc_play->pet->bowl, prev);
    }
}

void free_bowl(game_t *g, bowl_t *bowl, bowl_t *prev)
{
    if (bowl == g->sc_play->pet->bowl) {
        g->sc_play->pet->bowl = bowl->next;
        sfRectangleShape_destroy(bowl->bowl);
        free(bowl);
        return;
    } else {
        prev->next = bowl->next;
        sfRectangleShape_destroy(bowl->bowl);
        free(bowl);
    }
}

void free_petanque(game_t *g)
{
    sfTexture_destroy(g->sc_play->pet->back_text);
    sfTexture_destroy(g->sc_play->pet->tower_text);
    free_buttons(&g->sc_play->pet->btn);
    sfRectangleShape_destroy(g->sc_play->pet->direction);
    sfText_destroy(g->sc_play->pet->text);
    free(g->sc_play->pet);
}
