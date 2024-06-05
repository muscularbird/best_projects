/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** init_button2
*/

#include "rpg.h"

void rect_btn(button_t **button, fonc_par_t par)
{
    button_t *b = malloc(sizeof(button_t));

    b->texture = sfTexture_createFromFile(par.src, NULL);
    b->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(b->rect, b->texture, sfFalse);
    sfRectangleShape_setSize(b->rect, par.rect_size);
    sfRectangleShape_setOrigin(b->rect, (sfVector2f){75, 50});
    sfRectangleShape_setPosition(b->rect, par.pos);
    b->rect_size = par.rect_size;
    b->state = NONE;
    b->hitb = sfRectangleShape_getGlobalBounds(b->rect);
    b->next = NULL;
    b->button_fonc = par.fonc;
    b->circle = NULL;
    b->id = par.id;
    add_node(b, button);
}

void circle_btn(button_t **button, fonc_par_t par)
{
    button_t *b = malloc(sizeof(button_t));
    sfVector2f origin = {10, 10};

    b->texture = sfTexture_createFromFile(par.src, NULL);
    b->circle = sfCircleShape_create();
    sfCircleShape_setTexture(b->circle, b->texture, sfFalse);
    sfCircleShape_setRadius(b->circle, par.circle_size);
    sfCircleShape_setOrigin(b->circle, origin);
    sfCircleShape_setPosition(b->circle, par.pos);
    b->circle_size = par.circle_size;
    b->state = NONE;
    b->hitb = sfCircleShape_getGlobalBounds(b->circle);
    b->next = NULL;
    b->button_fonc = par.fonc;
    b->rect = NULL;
    b->id = par.id;
    add_node(b, button);
}
