/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** detect_color
*/

#include "rpg.h"

bool is_pnj_walk(sfImage *image, sfVector2f pos)
{
    sfColor color = sfImage_getPixel(image, pos.x, pos.y);

    return (color.r == 255 && color.g == 255 && color.b == 255);
}

int colo(sfImage *img, unsigned int x, unsigned int y, scene_play_t *p)
{
    sfColor color;
    sfVector2u img_size = sfImage_getSize(img);

    if (img_size.x <= x || img_size.y <= y)
        return 0;
    color = sfImage_getPixel(img, x, y);
    if (color.r == 0 && color.g == 0 && color.b == 0) {
        return 0;
    }
    if (color.r == 255 && color.g == 0 && color.b == 0 && !p->final_boss)
        p->FINAL = 1;
    return 1;
}
