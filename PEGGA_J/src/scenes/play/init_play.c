/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/scenes/play/init_play
** File description:
** xkcd.com/378
*/

#include "rpg.h"

static const func_play_t funcs_menus[] = {
    {&events_normal, &update_normal, &draw_normal, &don_t_free},
    {&events_dialogues, &update_dialogues, &draw_dialogues, &don_t_free},
    {&events_petanque, &update_petanque, &draw_petanque, &free_petanque},
    {&event_laby, &update_laby, &draw_laby, &free_laby},
    {&events_skate, &update_skate, &draw_skate, &free_skate}
};

static void init_txt(game_t *g)
{
    g->sc_play->txt = sfText_create();
    sfText_setFont(g->sc_play->txt, g->font);
    sfText_setScale(g->sc_play->txt, (sfVector2f){0.2, 0.2});
    sfText_setFillColor(g->sc_play->txt, sfWhite);
    sfText_setString(g->sc_play->txt, "Press F");
    g->sc_play->near_adm = sfFalse;
    g->sc_play->final_boss = sfFalse;
    g->sc_play->FINAL = 0;
}

static sfRectangleShape *create_medal(sfTexture *text)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setTexture(rect, text, 0);
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){16, 16});
    sfRectangleShape_setOrigin(rect, (sfVector2f){8, 8});
    return rect;
}

static void init_medal(game_t *g)
{
    sfTexture *text0 = sfTexture_createFromFile("./assets/medal1.png", NULL);
    sfTexture *text1 = sfTexture_createFromFile("./assets/medal2.png", NULL);
    sfTexture *text2 = sfTexture_createFromFile("./assets/medal3.png", NULL);
    sfTexture *text3 = sfTexture_createFromFile("./assets/medal4.png", NULL);
    sfTexture *text4 = sfTexture_createFromFile("./assets/medal5.png", NULL);

    g->mc->medal_tab = malloc(sizeof(sfRectangleShape *) * 6);
    g->mc->medal_tab[0] = create_medal(text0);
    g->mc->medal_tab[1] = create_medal(text1);
    g->mc->medal_tab[2] = create_medal(text2);
    g->mc->medal_tab[3] = create_medal(text3);
    g->mc->medal_tab[4] = create_medal(text4);
    g->mc->medal_tab[5] = NULL;
}

void don_t_free(game_t *game)
{
    UNUSED(game);
}

void init_play_scene(game_t *g)
{
    g->sc_play = malloc(sizeof(scene_play_t));
    g->sc_play->game_menus[NORMAL] = funcs_menus[0];
    g->sc_play->game_menus[DIALOGUES] = funcs_menus[1];
    g->sc_play->game_menus[PETANQUE] = funcs_menus[2];
    g->sc_play->game_menus[JONA_MJ] = funcs_menus[3];
    g->sc_play->game_menus[SKATER] = funcs_menus[4];
    g->sc_play->cimetierre = NULL;
    g->sc_play->current_game = NORMAL;
    g->sc_play->current_quest = 4;
    g->sc_play->dialogue_sk = 0;
    g->sc_play->cimetierre_end = 0;
    init_txt(g);
    init_petanque(g);
    init_skate(g);
    init_main_char(g);
    init_laby(g);
    init_pnj(g);
    init_objects(g);
    init_adm(g);
    init_medal(g);
}
