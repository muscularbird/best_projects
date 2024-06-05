/*
** EPITECH PROJECT, 2024
** src/destroys/destroy_all_scenes
** File description:
** r/ProgrammerHumor
*/

#include "rpg.h"

void free_death(game_t *g)
{
    free_buttons(&g->dth_sc->btn);
    sfRectangleShape_destroy(g->dth_sc->opacity);
    sfText_destroy(g->dth_sc->text);
    free(g->dth_sc);
}

void free_pause_scene(game_t *g)
{
    sfSprite_destroy(g->sc_pau->bck_stat);
    sfSprite_destroy(g->sc_pau->bck_inv);
    sfText_destroy(g->sc_pau->stat);
    sfText_destroy(g->sc_pau->quest);
    free_buttons(&g->sc_pau->button);
    free(g->sc_pau);
}

void free_play_scene(game_t *g)
{
    free_pnj(&g->pnj);
    sfText_destroy(g->sc_play->txt);
    g->sc_play->game_menus[PETANQUE].free(g);
    g->sc_play->game_menus[JONA_MJ].free(g);
    g->sc_play->game_menus[SKATER].free(g);
}

void free_start_scene(game_t *g)
{
    free_buttons(&g->sc_st->button);
    sfSprite_destroy(g->sc_st->back_sprite);
    sfSprite_destroy(g->sc_st->logo);
    free(g->sc_st);
}

static void destroy_texts(game_t *g)
{
    sfTexture_destroy(g->sc_settings->mus_texture);
    sfTexture_destroy(g->sc_settings->back_texture);
    sfTexture_destroy(g->sc_settings->no_mus_texture);
    sfTexture_destroy(g->sc_settings->sound_texture);
    sfTexture_destroy(g->sc_settings->no_sound_texture);
    sfTexture_destroy(g->sc_settings->bar_texture);
    sfTexture_destroy(g->sc_settings->ybar_texture);
    sfText_destroy(g->sc_settings->left_t);
    sfText_destroy(g->sc_settings->right_t);
    sfText_destroy(g->sc_settings->top_t);
    sfText_destroy(g->sc_settings->bottom_t);
    sfText_destroy(g->sc_settings->fight_t);
}

void free_set_scene(game_t *g)
{
    free_buttons(&g->sc_settings->button);
    free_buttons(&g->sc_settings->w_size);
    sfSprite_destroy(g->sc_settings->back_sprite);
    sfSprite_destroy(g->sc_settings->info_sp);
    sfRectangleShape_destroy(g->sc_settings->sound_bar);
    sfRectangleShape_destroy(g->sc_settings->sound_y_bar);
    sfRectangleShape_destroy(g->sc_settings->mus_bar);
    sfRectangleShape_destroy(g->sc_settings->mus_y_bar);
    destroy_texts(g);
    free(g->sc_settings);
}
