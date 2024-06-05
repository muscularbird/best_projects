/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** animation
*/

#include "rpg.h"

void update_animation(animation_t *animation, float delta_tim, int h, float k)
{
    UNUSED(k);
    if (h == -1)
        return;
    if (delta_tim > 0.1) {
        animation->bounds.top = h;
        animation->bounds.left += 32;
        if (animation->bounds.left >= 320) {
            animation->bounds.left = 0;
        }
        sfSprite_setTextureRect(animation->sprite, animation->bounds);
    }
}
