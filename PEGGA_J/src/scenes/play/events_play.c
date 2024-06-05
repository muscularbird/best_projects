/*
** EPITECH PROJECT, 2024
** src/scenes/play/events_play
** File description:
** epitech > epita
*/

#include "rpg.h"

static void event_debug(game_t *g, sfEvent event)
{
    if (event.key.code == sfKeyJ)
        g->sc_play->current_game = JONA_MJ;
    if (event.key.code == sfKeyM)
        g->next_scene = BOSS;
    if (event.key.code == sfKeyB) {
        g->sc_play->current_game = PETANQUE;
        sfRenderWindow_setView(g->window, g->global_POV);
    }
    if (event.key.code == sfKeyK) {
        g->sc_play->current_game = SKATER;
        sfRenderWindow_setView(g->window, g->global_POV);
    }
}

static void event_key(game_t *g, sfEvent event)
{
    if (event.key.code == sfKeyEscape) {
        g->sc_pau->is_pause = sfTrue;
        play_sound(g);
        sfRenderWindow_setView(g->window, g->global_POV);
        g->sc_pau->cp = 0;
        g->next_scene = PAUSE;
    }
    if (event.key.code == sfKeyTab) {
        play_sound(g);
        g->mc->inv = !g->mc->inv;
    }
}

void events_normal(game_t *g)
{
    sfEvent event;

    sfView_setCenter(g->mc->POV, g->mc->pos);
    sfRenderWindow_setView(g->window, g->mc->POV);
    events_cimetierre(g);
    while (sfRenderWindow_pollEvent(g->window, &event)) {
        event_sound(g);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (event.type == sfEvtKeyPressed)
            event_key(g, event);
        if (event.type == sfEvtKeyPressed && g->debug)
            event_debug(g, event);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF)
            isnear(g, g->mc->pos, g->sc_play->current_quest);
    }
}

void events_dialogues(game_t *g)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(g->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF) {
            update_variables(g->adm, g);
        }
    }
}

void events_play_scene(game_t *g)
{
    g->sc_play->game_menus[g->sc_play->current_game].event(g);
}
