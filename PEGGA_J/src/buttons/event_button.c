/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** event_button
*/

#include "rpg.h"

static void pressed_event(button_t *btn, game_t *g)
{
    btn->button_fonc(g, btn);
}

static void hover_event(button_t *btn, game_t *g)
{
    sfColor c = sfColor_fromRGBA(255, 255, 255, 255);

    UNUSED(g);
    if (btn->circle != NULL)
        sfCircleShape_setRadius(btn->circle, btn->circle_size + 20);
    if (btn->rect != NULL) {
        sfRectangleShape_setFillColor(btn->rect, c);
        sfRectangleShape_setSize(btn->rect,
        (sfVector2f){btn->rect_size.x + 30, btn->rect_size.y + 20});
        sfRectangleShape_setOrigin(btn->rect, (sfVector2f){90, 60});
    }
}

static void none_event(button_t *btn, game_t *g)
{
    sfColor c = sfColor_fromRGBA(255, 255, 255, 255);

    UNUSED(g);
    if (btn->circle != NULL)
        sfCircleShape_setRadius(btn->circle, btn->circle_size);
    if (btn->rect != NULL) {
        sfRectangleShape_setFillColor(btn->rect, c);
        sfRectangleShape_setSize(btn->rect,
        (sfVector2f){btn->rect_size.x, btn->rect_size.y});
        sfRectangleShape_setOrigin(btn->rect, (sfVector2f){75, 50});
    }
}

static void desactivate_event(button_t *btn, game_t *g)
{
    sfColor c = sfColor_fromRGBA(128, 128, 128, 110);

    UNUSED(g);
    if (btn->rect != NULL) {
        sfRectangleShape_setFillColor(btn->rect, c);
    }
}

void event_button(button_t *btn, game_t *g)
{
    button_t *tmp = btn;

    while (tmp) {
        if (tmp->state == PRESSED)
            pressed_event(tmp, g);
        if (tmp->state == HOVER)
            hover_event(tmp, g);
        if (tmp->state == NONE)
            none_event(tmp, g);
        if (tmp->state == DESACTIVATE)
            desactivate_event(tmp, g);
        tmp = tmp->next;
    }
}

void eevent_button(game_t *g, button_t *btn, sfEvent event)
{
    button_t *tmp = btn;

    while (tmp) {
        set_button_state(event, g, tmp);
        tmp = tmp->next;
    }
    event_button(btn, g);
}

void set_button_state(sfEvent event, game_t *g, button_t *tmp)
{
    if (sfFloatRect_contains(&tmp->hitb,
    g->mouse_pos.x, g->mouse_pos.y) && tmp->state != DESACTIVATE) {
        if (event.type == sfEvtMouseButtonPressed)
            tmp->state = PRESSED;
        else
            tmp->state = HOVER;
    } else if (tmp->state != DESACTIVATE)
        tmp->state = NONE;
    else
        tmp->state = DESACTIVATE;
}
