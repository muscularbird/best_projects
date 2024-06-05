/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/inits/init_scene
** File description:
** xkcd.com/378
*/

#include "rpg.h"

static const func_menu_t menus[] = {
    {&init_start_scene, &events_start_scene, &update_start_scene,
        &draw_start_scene, &free_start_scene},
    {&init_set_scene, &events_set_scene, &update_set_scene,
        &draw_set_scene, &free_set_scene},
    {&init_pause_scene, &events_pause_scene, &update_pause_scene,
        &draw_pause_scene, &free_pause_scene},
    {&init_play_scene, &events_play_scene, &update_play_scene,
        &draw_play_scene, &free_play_scene},
    {&init_death, &event_death, &update_death,
        &draw_death, &free_death},
    {&init_save_scene, &events_save_scene, &update_save_scene,
        &draw_save_scene, &free_save_scene},
    {&init_boss, &events_boss, &update_boss,
        &draw_boss, &free_death},
    {&init_lore, &events_lore, &update_lore,
        &draw_lore, &free_death},
};

static void init_icon(game_t *g)
{
    sfImage *icon = sfImage_createFromFile("./assets/icon.png");
    sfVector2u size = sfImage_getSize(icon);
    const sfUint8 *pxl = sfImage_getPixelsPtr(icon);

    sfRenderWindow_setIcon(g->window, size.x, size.y, pxl);
}

static void init_enum(game_t *g)
{
    g->current_scene = START_LORE;
    g->previous_scene = START_LORE;
    g->next_scene = -1;
    g->menus[PLAY].init(g);
    g->menus[START].init(g);
    g->menus[SETTINGS].init(g);
    g->menus[PAUSE].init(g);
    g->menus[DEATH].init(g);
    g->menus[SAVE].init(g);
    g->menus[BOSS].init(g);
    g->menus[START_LORE].init(g);
}

static void init_game3(game_t *g)
{
    sfTexture *txt = sfTexture_createFromFile(COLL_MAP, NULL);

    sfView_setCenter(g->global_POV,
    (sfVector2f){g->w_size.x / 2, g->w_size.y / 2});
    sfView_setSize(g->global_POV, g->w_size);
    g->txt_map_up = sfTexture_createFromFile(MAP_UP, NULL);
    g->map_up = sfSprite_create();
    sfSprite_setTexture(g->map_up, g->txt_map_up, sfFalse);
    sfSprite_setPosition(g->map_up, (sfVector2f){0, 0});
    g->cursor_txt = sfTexture_createFromFile(CURSOR, NULL);
    g->cursor = sfSprite_create();
    sfSprite_setTexture(g->cursor, g->cursor_txt, sfFalse);
    sfSprite_setOrigin(g->cursor, (sfVector2f){13, 13});
    sfRenderWindow_setMouseCursorVisible(g->window, sfFalse);
    sfRenderWindow_setFramerateLimit(g->window, 240);
    g->back_map = sfTexture_copyToImage(txt);
    sfTexture_destroy(txt);
    init_icon(g);
    init_enum(g);
}

static void init_game2(game_t *g)
{
    sfColor color = sfColor_fromRGBA(0, 0, 0, 120);

    if (!g->debug)
        g->debug = 0;
    g->clock = sfClock_create();
    sfClock_restart(g->clock);
    g->save = sfClock_getElapsedTime(g->clock);
    g->click = sfFalse;
    sfRectangleShape_setFillColor(g->opacity, color);
    sfRectangleShape_setPosition(g->opacity, (sfVector2f){0, 0});
    g->map_text = sfTexture_createFromFile("./assets/map.png", NULL);
    g->map_sp = sfSprite_create();
    sfSprite_setTexture(g->map_sp, g->map_text, sfFalse);
    sfSprite_setTexture(g->map_sp, g->map_text, sfFalse);
    sfSprite_setPosition(g->map_sp, (sfVector2f){0, 0});
    g->mouse_pos = (sfVector2f){0, 0};
    g->global_POV = sfView_create();
    init_game3(g);
}

void init_game(game_t *g)
{
    srand(time(NULL));
    g->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "PEGGA_J", sfResize | sfClose, NULL);
    g->menus[START] = menus[0];
    g->menus[SETTINGS] = menus[1];
    g->menus[PAUSE] = menus[2];
    g->menus[PLAY] = menus[3];
    g->menus[DEATH] = menus[4];
    g->menus[SAVE] = menus[5];
    g->menus[BOSS] = menus[6];
    g->menus[START_LORE] = menus[7];
    g->w_size = (sfVector2f){1920, 1080};
    g->opacity = sfRectangleShape_create();
    sfRectangleShape_setSize(g->opacity,
    ch_coor((sfVector2f){1920, 1080}, g->w_size));
    g->font = sfFont_createFromFile(FONT);
    init_music(g);
    init_game2(g);
}
