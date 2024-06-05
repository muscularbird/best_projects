/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/inits/create_animation
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include "rpg.h"

animation_t *create_animation(const char *texture_path)
{
    animation_t *animation = malloc(sizeof(animation_t));

    animation->clock = sfClock_create();
    animation->seconds = 0.0;
    animation->texture = sfTexture_createFromFile(texture_path, NULL);
    animation->sprite = sfSprite_create();
    sfSprite_setTexture(animation->sprite, animation->texture, sfTrue);
    animation->bounds = (sfIntRect){0, 0, 32, 32};
    sfSprite_setTextureRect(animation->sprite, animation->bounds);
    return (animation);
}
