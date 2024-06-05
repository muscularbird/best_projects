/*
** EPITECH PROJECT, 2024
** init_skate
** File description:
** vim > emacs
*/

#include "rpg.h"

static fonc_par_t buttons_skate[] = {
    {RETRY, {0, 0}, {0, 0}, 0, &restart_sk, 0},
    {CLOSE, {0, 0}, {0, 0}, 0, &close_sk, 1}
};

sfIntRect *init_rect(int top, int left, int width, int height)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = top;
    rect->left = left;
    rect->width = width;
    rect->height = height;
    return rect;
}

void add_sprite(game_t *g, sfTexture *text, sfVector2f pos)
{
    train_t *node = malloc(sizeof(train_t));

    node->sp = sfRectangleShape_create();
    node->text = text;
    node->pos = pos;
    node->spd = (rand() % 100) + 50;
    node->touched = 0;
    sfRectangleShape_setTexture(node->sp, node->text, sfTrue);
    sfRectangleShape_setPosition(node->sp, node->pos);
    sfRectangleShape_setSize(node->sp, (sfVector2f){150, 150});
    sfRectangleShape_setOrigin(node->sp, (sfVector2f){75, 75});
    my_add_node(&g->sc_play->sk->train, node);
}

void add_train(game_t *g)
{
    sfTexture *t = sfTexture_createFromFile(TRAIN, NULL);
    sfVector2f pos = {0, 0};

    pos.x = (g->w_size.x / 2 - 400) + rand() % 800;
    add_sprite(g, t, pos);
}

static void modif_funcs_btn(game_t *g)
{
    buttons_skate[0].pos = ch_coor((sfVector2f){1050, 775}, g->w_size);
    buttons_skate[0].rect_size = ch_coor((sfVector2f){150, 150}, g->w_size);
    buttons_skate[1].pos = ch_coor((sfVector2f){850, 775}, g->w_size);
    buttons_skate[1].rect_size = ch_coor((sfVector2f){150, 150}, g->w_size);
}

static void fill_skate(game_t *g, skate_t **sk)
{
    (*sk)->btn = (void *)0;
    (*sk)->train = (void *)0;
    (*sk)->score = 0;
    (*sk)->alive = 1;
    (*sk)->life = 3;
    (*sk)->life_tab = malloc(sizeof(sfRectangleShape *) * 3);
    for (int i = 0; i < (*sk)->life; i++)
        (*sk)->life_tab[i] = create_life(i + 1);
    (*sk)->high_max = g->w_size.y - 100;
    (*sk)->spawn_rate = sfClock_create();
    (*sk)->pos = (sfVector2f){g->w_size.x / 2, g->w_size.y - 50};
    (*sk)->time = sfClock_getElapsedTime(g->clock);
    (*sk)->bg = sfRectangleShape_create();
    (*sk)->bg_t = sfTexture_createFromFile(SKATE_BG, NULL);
    sfRectangleShape_setTexture((*sk)->bg, (*sk)->bg_t, 0);
    sfRectangleShape_setPosition((*sk)->bg, (sfVector2f){0, 0});
    sfRectangleShape_setSize((*sk)->bg, g->w_size);
}

static void init_sk_loose(game_t *g)
{
    rect_btn(&g->sc_play->sk->btn, buttons_skate[0]);
    rect_btn(&g->sc_play->sk->btn, buttons_skate[1]);
}

void init_skate(game_t *g)
{
    sfTexture *t = sfTexture_createFromFile(UNDER_BG, NULL);

    g->sc_play->sk = malloc(sizeof(skate_t));
    g->sc_play->sk->u_map = sfTexture_copyToImage(t);
    sfTexture_destroy(t);
    fill_skate(g, &g->sc_play->sk);
    modif_funcs_btn(g);
    add_train(g);
    init_sk_loose(g);
}
