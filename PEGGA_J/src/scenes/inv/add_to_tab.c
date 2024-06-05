/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** add_to_tab
*/

#include "rpg.h"

void add_to_tab(game_t *g, sfRectangleShape *rect)
{
    int i = 0;

    for (; g->mc->full_inv[i] && i < 8; i++);
    sfRectangleShape_setOrigin(rect, (sfVector2f){9, 9});
    sfRectangleShape_setSize(rect, (sfVector2f){18, 18});
    g->mc->full_inv[i] = rect;
}
