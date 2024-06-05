/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** func_scene
*/

#include "rpg.h"

void update_items(game_t *g)
{
    int height = 0;
    int width = 0;

    for (int i = 0; g->mc->full_inv[i]; i++) {
        if (i > 3)
            height = 110;
        if (i == 4)
            width = 0;
        sfRectangleShape_setPosition(g->mc->full_inv[i],
        ch_coor((sfVector2f){1475 + width, 780 + 28 + height}, g->w_size));
        sfRectangleShape_setScale(g->mc->full_inv[i],
        ch_coor((sfVector2f){2.5, 2.5}, g->w_size));
        width += 88.5;
    }
}

static void quest_color(game_t *g, int i)
{
    sfColor c = sfColor_fromRGBA(255, 140, 0, 255);
    sfColor b = sfColor_fromRGB(124, 84, 60);

    if (i < g->sc_play->current_quest)
        sfText_setFillColor(g->sc_pau->quests[i], sfGreen);
    else if (i == g->sc_play->current_quest)
        sfText_setFillColor(g->sc_pau->quests[i], c);
    else
        sfText_setFillColor(g->sc_pau->quests[i], b);
}

static void update_stats(game_t *g)
{
    char str[128];
    char str2[128];
    char str3[128];

    sprintf(str, "Attack damage: %d", g->mc->AD);
    sprintf(str2, "Health: %d", g->mc->hp_nb);
    sprintf(str3, "Move speed: %d", (int)g->mc->speed);
    sfText_setString(g->sc_pau->stats[0], str);
    sfText_setString(g->sc_pau->stats[1], str2);
    sfText_setString(g->sc_pau->stats[2], str3);
    for (int i = 0; i < 6; i++) {
        quest_color(g, i);
    }
}

static void update_anim_pause(game_t *g, float d)
{
    static sfIntRect rect = {0, 32, 32, 32};

    sfSprite_setTextureRect(g->sc_pau->mc, rect);
    if (d > 0.1) {
        sfClock_restart(g->clock);
        rect.left += 32;
        if (rect.left >= 320)
            rect.left = 0;
        sfSprite_setTextureRect(g->sc_pau->mc, rect);
    }
}

void update_pause_scene(game_t *g)
{
    float d = sfClock_getElapsedTime(g->clock).microseconds / MILION;

    if (!g->sc_pau->cp) {
        sfSprite_setScale(g->mc->inv_back,
        ch_coor((sfVector2f){0.3, 0.3}, g->w_size));
        sfSprite_setPosition(g->mc->inv_back,
        ch_coor((sfVector2f){1425, 730}, g->w_size));
        update_items(g);
    }
    g->sc_pau->cp++;
    update_anim_pause(g, d);
    g->mouse_pos = sfRenderWindow_mapPixelToCoords(g->window,
    sfMouse_getPositionRenderWindow(g->window), sfFalse);
    sfSprite_setPosition(g->cursor, g->mouse_pos);
    update_stats(g);
}
