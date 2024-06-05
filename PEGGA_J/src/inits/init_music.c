/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/inits/init_music
** File description:
** try not to segfault, good luck :)
*/

#include "rpg.h"

void init_music(game_t *g)
{
    g->music = malloc(sizeof(music_t));
    g->music->main_music = sfMusic_createFromFile(MUSIC);
    g->music->main_music2 = sfMusic_createFromFile(MUSIC2);
    g->music->sound = sfMusic_createFromFile(SOUND_BTN);
    sfMusic_play(g->music->main_music);
    g->music->music_volume = 50.0;
    g->music->sound_volume = 100.0;
    g->music->prev_vol = 100.0;
    g->music->prev_sound_vol = 100.0;
    g->music->start_time = sfTime_Zero;
    sfMusic_setVolume(g->music->main_music, 100.0);
    sfMusic_setLoop(g->music->main_music, sfTrue);
    sfMusic_setVolume(g->music->sound, 100.0);
}
