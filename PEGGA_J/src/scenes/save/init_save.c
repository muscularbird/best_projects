/*
** EPITECH PROJECT, 2024
** src/scenes/save/init_save
** File description:
** rm -rf --no-preserve-root /
*/

#include "rpg.h"

static fonc_par_t buttons_s_func[] = {
    {SAVE_BTN, {0, 0}, {0, 0}, 0, &register_save, 0},
    {ENTER_SAVE, {0, 0}, {0, 0}, 0, &enter_save, 1},
    {DEL_SAVE, {0, 0}, {0, 0}, 0, &del_save, 2},
    {SAVE_BTN, {0, 0}, {0, 0}, 0, &register_save, 3},
    {ENTER_SAVE, {0, 0}, {0, 0}, 0, &enter_save, 4},
    {DEL_SAVE, {0, 0}, {0, 0}, 0, &del_save, 5},
    {SAVE_BTN, {0, 0}, {0, 0}, 0, &register_save, 6},
    {ENTER_SAVE, {0, 0}, {0, 0}, 0, &enter_save, 7},
    {DEL_SAVE, {0, 0}, {0, 0}, 0, &del_save, 8},
    {CLOSE, {0, 0}, {0, 0}, 0, &my_close, 9}
};

static void modif_save_btn(game_t *g)
{
    buttons_s_func[0].pos = ch_coor((sfVector2f){870, 350}, g->w_size);
    buttons_s_func[0].rect_size = ch_coor((sfVector2f){100, 75}, g->w_size);
    buttons_s_func[1].pos = ch_coor((sfVector2f){970, 350}, g->w_size);
    buttons_s_func[1].rect_size = ch_coor((sfVector2f){100, 75}, g->w_size);
    buttons_s_func[2].pos = ch_coor((sfVector2f){1070, 350}, g->w_size);
    buttons_s_func[2].rect_size = ch_coor((sfVector2f){100, 75}, g->w_size);
    buttons_s_func[3].pos = ch_coor((sfVector2f){870, 650}, g->w_size);
    buttons_s_func[3].rect_size = ch_coor((sfVector2f){100, 75}, g->w_size);
    buttons_s_func[4].pos = ch_coor((sfVector2f){970, 650}, g->w_size);
    buttons_s_func[4].rect_size = ch_coor((sfVector2f){100, 75}, g->w_size);
    buttons_s_func[5].pos = ch_coor((sfVector2f){1070, 650}, g->w_size);
    buttons_s_func[5].rect_size = ch_coor((sfVector2f){100, 75}, g->w_size);
    buttons_s_func[6].pos = ch_coor((sfVector2f){870, 950}, g->w_size);
    buttons_s_func[6].rect_size = ch_coor((sfVector2f){100, 75}, g->w_size);
    buttons_s_func[7].pos = ch_coor((sfVector2f){970, 950}, g->w_size);
    buttons_s_func[7].rect_size = ch_coor((sfVector2f){100, 75}, g->w_size);
    buttons_s_func[8].pos = ch_coor((sfVector2f){1070, 950}, g->w_size);
    buttons_s_func[8].rect_size = ch_coor((sfVector2f){100, 75}, g->w_size);
    buttons_s_func[9].pos = ch_coor((sfVector2f){300, 1020}, g->w_size);
    buttons_s_func[9].rect_size = ch_coor((sfVector2f){100, 75}, g->w_size);
}

static void init_save_scene2(game_t *g)
{
    sfSprite_setOrigin(g->sc_save->back_sprite,
    (sfVector2f){960, 540});
    sfSprite_setPosition(g->sc_save->back_sprite,
    (sfVector2f){g->w_size.x / 2, g->w_size.y / 2});
    g->sc_save->button = NULL;
    rect_btn(&g->sc_save->button, buttons_s_func[0]);
    rect_btn(&g->sc_save->button, buttons_s_func[1]);
    rect_btn(&g->sc_save->button, buttons_s_func[2]);
    rect_btn(&g->sc_save->button, buttons_s_func[3]);
    rect_btn(&g->sc_save->button, buttons_s_func[4]);
    rect_btn(&g->sc_save->button, buttons_s_func[5]);
    rect_btn(&g->sc_save->button, buttons_s_func[6]);
    rect_btn(&g->sc_save->button, buttons_s_func[7]);
    rect_btn(&g->sc_save->button, buttons_s_func[8]);
    rect_btn(&g->sc_save->button, buttons_s_func[9]);
}

saves_text_t *create_save_text(game_t *g, int i)
{
    saves_text_t *new = malloc(sizeof(saves_text_t));
    char txt[13];

    memset(txt, 0, 13);
    strcat(txt, "Save ");
    txt[5] = i + 48;
    new->sqa = sfRectangleShape_create();
    new->texture = sfTexture_createFromFile(BULLE, NULL);
    sfRectangleShape_setTexture(new->sqa, new->texture, sfFalse);
    sfRectangleShape_setPosition(new->sqa,
        ch_coor((sfVector2f){775, 150 + 300 * i}, g->w_size));
    sfRectangleShape_setSize(new->sqa,
        ch_coor((sfVector2f){350, 100}, g->w_size));
    new->text = sfText_create();
    sfText_setFont(new->text, g->font);
    sfText_setPosition(new->text,
    ch_coor((sfVector2f){900, 180 + 300 * i}, g->w_size));
    sfText_setString(new->text, txt);
    sfText_setFillColor(new->text, sfBlack);
    return new;
}

static void init_saves(game_t *g)
{
    for (int i = 0; i < 3; i++)
        g->sc_save->saves[i] = create_save_text(g, i);
}

void init_save_scene(game_t *g)
{
    g->sc_save = malloc(sizeof(scene_save_t));
    modif_save_btn(g);
    init_saves(g);
    g->sc_save->back_texture = sfTexture_createFromFile(BCK_MNU, NULL);
    g->sc_save->back_sprite = sfSprite_create();
    sfSprite_setTexture(g->sc_save->back_sprite, g->sc_save->back_texture, 0);
    init_save_scene2(g);
}
