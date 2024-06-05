/*
** EPITECH PROJECT, 2024
** /rpg/src/destroys/destroy_all_scenes
** File description:
** if you code on paper, you're not a real programmer
*/

#include "rpg.h"

static void free_mc2(game_t *g)
{
    for (int i = 0; i < 5; i++)
        sfRectangleShape_destroy(g->mc->medal_tab[i]);
    free(g->mc->medal_tab);
    free(g->mc->left);
    free(g->mc->top);
    free(g->mc->bottom);
    free(g->mc->right);
    free(g->mc->fight);
    free(g->mc);
}

void free_mc(game_t *g)
{
    sfSprite_destroy(g->mc->animation->sprite);
    sfClock_destroy(g->mc->attack);
    sfClock_destroy(g->mc->animation->clock);
    sfTexture_destroy(g->mc->animation->texture);
    free(g->mc->animation);
    sfCircleShape_destroy(g->mc->area);
    sfCircleShape_destroy(g->mc->range);
    sfView_destroy(g->mc->POV);
    sfRectangleShape_destroy(g->mc->lifebar);
    sfRectangleShape_destroy(g->mc->bck_lifebar);
    sfSprite_destroy(g->mc->inv_back);
    sfText_destroy(g->mc->hp);
    sfText_destroy(g->mc->lvl);
    free_mc2(g);
}

void destroy_music(game_t *g)
{
    sfMusic_stop(g->music->main_music);
    sfMusic_destroy(g->music->main_music);
    sfMusic_stop(g->music->main_music2);
    sfMusic_destroy(g->music->main_music2);
    sfMusic_stop(g->music->sound);
    sfMusic_destroy(g->music->sound);
    free(g->music);
}

void destroy_game(game_t *g)
{
    sfRectangleShape_destroy(g->opacity);
    sfTexture_destroy(g->map_text);
    sfTexture_destroy(g->txt_map_up);
    sfTexture_destroy(g->cursor_txt);
    sfSprite_destroy(g->map_sp);
    sfImage_destroy(g->back_map);
    g->menus[START].destroy(g);
    g->menus[PLAY].destroy(g);
    g->menus[SETTINGS].destroy(g);
    g->menus[PAUSE].destroy(g);
    g->menus[SAVE].destroy(g);
    g->menus[DEATH].destroy(g);
    sfFont_destroy(g->font);
    sfClock_destroy(g->clock);
    destroy_music(g);
    free_mc(g);
    sfRenderWindow_destroy(g->window);
}

void free_buttons(button_t **now)
{
    button_t *follow = (void *)0;

    while ((*now)) {
        follow = (*now)->next;
        sfCircleShape_destroy((*now)->circle);
        sfRectangleShape_destroy((*now)->rect);
        sfTexture_destroy((*now)->texture);
        free((*now));
        *now = follow;
    }
}

void free_pnj(pnj_t **now)
{
    pnj_t *follow = (void *)0;

    while ((*now)) {
        follow = (*now)->next;
        sfCircleShape_destroy((*now)->area);
        sfClock_destroy((*now)->anim->clock);
        sfTexture_destroy((*now)->anim->texture);
        sfSprite_destroy((*now)->anim->sprite);
        free((*now)->type);
        free((*now)->anim);
        free((*now));
        *now = follow;
    }
}
