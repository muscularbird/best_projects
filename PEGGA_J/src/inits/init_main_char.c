/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/inits/init_main_char
** File description:
** man man
*/

#include "rpg.h"

static sfText *create_text(int i, sfVector2f vecn, sfFont *f, int x)
{
    char str[24];
    sfText *txt = sfText_create();

    sfText_setFont(txt, f);
    if (x == 0)
        sprintf(str, "Lvl %d", i);
    else
        sprintf(str, "%d", i);
    sfText_setString(txt, str);
    sfText_setFillColor(txt, sfWhite);
    sfText_setPosition(txt, vecn);
    if (x == 0)
        sfText_setScale(txt, (sfVector2f){0.5, 0.5});
    else
        sfText_setScale(txt, (sfVector2f){0.2, 0.2});
    return txt;
}

static void init_main_char2(game_t *g)
{
    g->mc->attack = sfClock_create();
    g->mc->lvl_nb = 1;
    g->mc->hp_nb = 200;
    g->mc->lvl = create_text(g->mc->lvl_nb,
    (sfVector2f){g->mc->pos.x + 150, g->mc->pos.y - 110}, g->font, 0);
    g->mc->hp = create_text(g->mc->hp_nb,
    (sfVector2f){g->mc->pos.x - 97, g->mc->pos.y - 98}, g->font, 1);
    g->mc->lifebat_texture = sfTexture_createFromFile(LIFEBAR, NULL);
    g->mc->bck_lifebat_tx = sfTexture_createFromFile(BCK_LIFEBAR, NULL);
    g->mc->lifebar = sfRectangleShape_create();
    sfRectangleShape_setTexture(g->mc->lifebar, g->mc->lifebat_texture, 0);
    sfRectangleShape_setSize(g->mc->lifebar,
    ch_coor((sfVector2f){100, 10}, g->w_size));
    sfRectangleShape_setPosition(g->mc->lifebar,
    ch_coor((sfVector2f){g->mc->pos.x - 180, g->mc->pos.y - 100}, g->w_size));
    g->mc->bck_lifebar = sfRectangleShape_copy(g->mc->lifebar);
    sfRectangleShape_setTexture(g->mc->bck_lifebar, g->mc->bck_lifebat_tx, 0);
}

static void init_inv(game_t *g)
{
    sfTexture *text = sfTexture_createFromFile(INVENTORY, NULL);

    g->mc->PREVIOUS_STATE = sfFalse;
    g->mc->inv = sfFalse;
    g->mc->inv_back = sfSprite_create();
    sfSprite_setTexture(g->mc->inv_back, text, 0);
    sfSprite_setScale(g->mc->inv_back,
    ch_coor((sfVector2f){0.1, 0.1}, g->w_size));
    sfSprite_setOrigin(g->mc->inv_back,
    ch_coor((sfVector2f){(1318 * 0.1) / 2, (993 * 0.1) / 2}, g->w_size));
    sfSprite_setPosition(g->mc->inv_back, ch_coor(g->mc->pos, g->w_size));
}

static void init_movs(game_t *g)
{
    g->mc->left = my_strdup("q");
    g->mc->top = my_strdup("z");
    g->mc->bottom = my_strdup("s");
    g->mc->right = my_strdup("d");
    g->mc->fight = my_strdup("l");
    g->mc->topkey = sfKeyZ;
    g->mc->botkey = sfKeyS;
    g->mc->rightkey = sfKeyD;
    g->mc->leftkey = sfKeyQ;
    g->mc->fightkey = sfKeyL;
    g->mc->range = sfCircleShape_create();
    sfCircleShape_setPosition(g->mc->area, g->mc->pos);
    sfCircleShape_setRadius(g->mc->area, 40.0);
    sfCircleShape_setOrigin(g->mc->area, (sfVector2f){40, 40});
    g->mc->anim = 32;
    init_inv(g);
}

void init_main_char(game_t *g)
{
    g->mc = malloc(sizeof(main_char_t));
    g->mc->animation = create_animation(WARRIOR_MC);
    g->mc->pos = ch_coor((sfVector2f){1000, 1000}, g->w_size);
    g->mc->old_pos = (sfVector2f){0, 0};
    g->mc->speed = 60.25;
    g->mc->area = sfCircleShape_create();
    g->mc->POV = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    g->mc->AD = 20;
    sfSprite_setScale(g->mc->animation->sprite,
    ch_coor((sfVector2f){0.7, 0.7}, g->w_size));
    sfSprite_setOrigin(g->mc->animation->sprite,
    ch_coor((sfVector2f){16, 16}, g->w_size));
    sfCircleShape_setPosition(g->mc->area, ch_coor(g->mc->pos, g->w_size));
    sfCircleShape_setRadius(g->mc->area, 160.0);
    sfCircleShape_setOrigin(g->mc->area, (sfVector2f){160, 160});
    sfView_setCenter(g->mc->POV, g->mc->pos);
    sfView_zoom(g->mc->POV, 0.20 * g->w_size.x / 1920);
    init_main_char2(g);
    init_movs(g);
}
