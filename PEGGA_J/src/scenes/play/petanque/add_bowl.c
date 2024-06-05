/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** add_petanque
*/

#include "rpg.h"

void add_bowl(game_t *g, float coef, float angle)
{
    bowl_t *new_bowl = malloc(sizeof(bowl_t));
    sfTexture *text = sfTexture_createFromFile("./assets/bullet.png", NULL);

    new_bowl->bowl = sfRectangleShape_create();
    sfRectangleShape_setPosition(new_bowl->bowl,
    sfRectangleShape_getPosition(g->sc_play->pet->direction));
    sfRectangleShape_setTexture(new_bowl->bowl, text, 0);
    sfRectangleShape_setSize(new_bowl->bowl, (sfVector2f){52, 26});
    sfRectangleShape_setRotation(new_bowl->bowl, angle);
    new_bowl->position = sfRectangleShape_getPosition(new_bowl->bowl);
    new_bowl->angle = angle;
    new_bowl->coef = coef;
    new_bowl->time_save = sfClock_getElapsedTime(g->clock);
    new_bowl->next = g->sc_play->pet->bowl;
    g->sc_play->pet->bowl = new_bowl;
}
