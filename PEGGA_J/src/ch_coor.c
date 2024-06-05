/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** ch_coor
*/

#include "rpg.h"

sfVector2f ch_coor(sfVector2f coor, sfVector2f w_size)
{
    sfVector2f vect = {0, 0};

    vect.x = coor.x * w_size.x / 1920;
    vect.y = coor.y * w_size.y / 1080;
    return vect;
}
