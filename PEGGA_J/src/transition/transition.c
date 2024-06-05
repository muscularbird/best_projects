/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** transition
*/

#include "rpg.h"

void which_fonc(char *str, game_t *g)
{
    if (!strcmp(str, "SAVE")) {
        draw_save_scene_tr(g);
        return;
    }
    if (!strcmp(str, "PLAY")) {
        draw_normal_tr(g);
        return;
    }
    if (!strcmp(str, "DEATH")) {
        draw_death_tr(g);
        return;
    }
    if (!strcmp(str, "START")) {
        draw_start_scene_tr(g);
        return;
    }
    if (!strcmp(str, "LORE")) {
        draw_lore_tr(g);
    }
}

void fade_transition_bis(game_t *g, sfRectangleShape *r, char *s, sfClock *c)
{
    sfTime t = sfSeconds(1.0f);
    float p = 0.0;
    int alpha = 0;

    sfClock_restart(c);
    while (sfClock_getElapsedTime(c).microseconds < t.microseconds) {
        p = sfClock_getElapsedTime(c).microseconds / (float)t.microseconds;
        alpha = 255 - (int)(255 * p);
        sfRectangleShape_setFillColor(r, (sfColor){0, 0, 0, alpha});
        sfRenderWindow_clear(g->window, sfBlack);
        which_fonc(s, g);
        sfRenderWindow_drawRectangleShape(g->window, r, NULL);
        sfRenderWindow_display(g->window);
    }
    sfRectangleShape_destroy(r);
    sfClock_destroy(c);
}

void fade_transition(game_t *g, menu_t m, char *i1, char *i2)
{
    sfTime t = sfSeconds(1.0f);
    sfRectangleShape *fadeRect = sfRectangleShape_create();
    sfClock* c = sfClock_create();
    int alpha = 0;
    float p = 0.0;

    sfRectangleShape_setSize(fadeRect, g->w_size);
    sfRectangleShape_setFillColor(fadeRect, (sfColor){0, 0, 0, 0});
    while (sfClock_getElapsedTime(c).microseconds < t.microseconds) {
        p = sfClock_getElapsedTime(c).microseconds / (float)t.microseconds;
        alpha = (int)(255 * p);
        sfRectangleShape_setFillColor(fadeRect, (sfColor){0, 0, 0, alpha});
        sfRenderWindow_clear(g->window, sfBlack);
        which_fonc(i1, g);
        sfRenderWindow_drawRectangleShape(g->window, fadeRect, NULL);
        sfRenderWindow_display(g->window);
    }
    g->current_scene = m;
    fade_transition_bis(g, fadeRect, i2, c);
}
