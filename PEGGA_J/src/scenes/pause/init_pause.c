/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/scenes/pause/init_pause
** File description:
** if you code on paper, you're not a real programmer
*/

#include "rpg.h"

static fonc_par_t buttons_p_func[] = {
    {PLAY_BTN, {0, 0}, {0, 0}, 0, &play, 0},
    {SETTINGS_BTN, {0, 0}, {0, 0}, 0, &settings_f, 1},
    {CLOSE, {0, 0}, {0, 0}, 0, &my_close, 2},
    {SAVE_BTN, {0, 0}, {0, 0}, 0, &menu_save, 3}
};

static char const *stats[] = {
    "Attack damage: 20",
    "Health: 200",
    "Move speed: 60"
};

static char const *quests[] = {
    "0: Talk with Yohann",
    "1: Geoffreys's quest",
    "2: Eliott's quest",
    "3: Pierre's quest",
    "4: Gautier's quest",
    "5: Archi's quest"
};

sfText *create_txt(char const *str, game_t *g)
{
    float y_coor = 250;
    float diff = 70.0;
    static int i = 0;
    sfText *txt = sfText_create();

    sfText_setFont(txt, g->font);
    sfText_setFillColor(txt, sfWhite);
    sfText_setString(txt, str);
    sfText_setPosition(txt,
    ch_coor((sfVector2f){120, y_coor + (i * diff)}, g->w_size));
    sfText_setScale(txt, ch_coor((sfVector2f){1, 1}, g->w_size));
    i++;
    if (i >= 3)
        i = 0;
    return txt;
}

sfText *create_txt2(char const *str, game_t *g)
{
    float y_coor = 700;
    float diff = 50.0;
    static int i = 0;
    sfText *txt = sfText_create();

    sfText_setFont(txt, g->font);
    sfText_setFillColor(txt, sfRed);
    sfText_setString(txt, str);
    sfText_setPosition(txt,
    ch_coor((sfVector2f){120, y_coor + (i * diff)}, g->w_size));
    sfText_setScale(txt, ch_coor((sfVector2f){1, 1}, g->w_size));
    i++;
    if (i >= 6)
        i = 0;
    return txt;
}

void init_sai2(game_t *g)
{
    g->sc_pau->stats = malloc(sizeof(sfText *) * 3);
    for (int i = 0; i < 3; i++)
        g->sc_pau->stats[i] = create_txt(stats[i], g);
    g->sc_pau->quest = sfText_create();
    sfText_setFont(g->sc_pau->quest, g->font);
    sfText_setPosition(g->sc_pau->quest,
    ch_coor((sfVector2f){180, 590}, g->w_size));
    sfText_setFillColor(g->sc_pau->stat, sfWhite);
    sfText_setScale(g->sc_pau->quest,
    ch_coor((sfVector2f){2, 2}, g->w_size));
    sfText_setString(g->sc_pau->quest, "Quests:");
    g->sc_pau->quests = malloc(sizeof(sfText *) * 6);
    for (int i = 0; i < 6; i++)
        g->sc_pau->quests[i] = create_txt2(quests[i], g);
    init_sai3(g);
}

static void init_stat_and_inv(game_t *g)
{
    g->sc_pau->beige_txt = sfTexture_createFromFile(BEIGE, NULL);
    g->sc_pau->brown_txt = sfTexture_createFromFile(BRUN, NULL);
    g->sc_pau->bck_stat = sfSprite_create();
    g->sc_pau->bck_inv = sfSprite_create();
    sfSprite_setTexture(g->sc_pau->bck_stat, g->sc_pau->beige_txt, 0);
    sfSprite_setPosition(g->sc_pau->bck_stat,
    ch_coor((sfVector2f){80, 50}, g->w_size));
    sfSprite_setScale(g->sc_pau->bck_stat,
    ch_coor((sfVector2f){1, 2.2}, g->w_size));
    g->sc_pau->stat = sfText_create();
    sfText_setFont(g->sc_pau->stat, g->font);
    sfText_setPosition(g->sc_pau->stat,
    ch_coor((sfVector2f){200, 90}, g->w_size));
    sfText_setFillColor(g->sc_pau->stat, sfWhite);
    sfText_setScale(g->sc_pau->stat,
    ch_coor((sfVector2f){2, 2}, g->w_size));
    sfText_setString(g->sc_pau->stat, "Stats:");
    init_sai2(g);
}

static void modif_pause_btn(game_t *g)
{
    buttons_p_func[0].pos = ch_coor((sfVector2f){700, 600}, g->w_size);
    buttons_p_func[0].rect_size = ch_coor((sfVector2f){150, 100}, g->w_size);
    buttons_p_func[1].pos = ch_coor((sfVector2f){950, 600}, g->w_size);
    buttons_p_func[1].rect_size = ch_coor((sfVector2f){150, 100}, g->w_size);
    buttons_p_func[2].pos = ch_coor((sfVector2f){1200, 600}, g->w_size);
    buttons_p_func[2].rect_size = ch_coor((sfVector2f){150, 100}, g->w_size);
    buttons_p_func[3].pos = ch_coor((sfVector2f){950, 750}, g->w_size);
    buttons_p_func[3].rect_size = ch_coor((sfVector2f){150, 100}, g->w_size);
}

void init_pause_scene(game_t *g)
{
    modif_pause_btn(g);
    g->sc_pau = malloc(sizeof(scene_pause_t));
    g->sc_pau->button = NULL;
    init_stat_and_inv(g);
    rect_btn(&g->sc_pau->button, buttons_p_func[0]);
    rect_btn(&g->sc_pau->button, buttons_p_func[1]);
    rect_btn(&g->sc_pau->button, buttons_p_func[2]);
    rect_btn(&g->sc_pau->button, buttons_p_func[3]);
    g->sc_pau->is_pause = sfFalse;
}
