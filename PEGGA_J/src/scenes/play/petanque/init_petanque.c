/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-myrpg-jonathan.lotz
** File description:
** init_pet
*/

#include "rpg.h"

static fonc_par_t buttons_func[] = {
    {RETRY, {0, 0}, {0, 0}, 0, &restart_pet, 0},
    {CLOSE, {0, 0}, {0, 0}, 0, &close_pet, 1}
};

sfRectangleShape *create_life(int pos)
{
    sfRectangleShape *new = sfRectangleShape_create();
    sfTexture *text = sfTexture_createFromFile(LIFE_HEART, NULL);

    sfRectangleShape_setOrigin(new, (sfVector2f){50, 50});
    sfRectangleShape_setPosition(new, (sfVector2f){100 * pos, 100});
    sfRectangleShape_setSize(new, (sfVector2f){100, 100});
    sfRectangleShape_setTexture(new, text, 0);
    return new;
}

void create_mob(game_t *g)
{
    mob_t *new_mob = malloc(sizeof(mob_t));
    int a = 0;

    srand(time(NULL));
    a = 400 + (rand() % (int)g->w_size.y - 400);
    new_mob->rect = sfRectangleShape_create();
    sfRectangleShape_setOrigin(new_mob->rect, (sfVector2f){50, 50});
    sfRectangleShape_setPosition(new_mob->rect,
    (sfVector2f){g->w_size.x + 10, a});
    new_mob->text = sfTexture_createFromFile(ORC, NULL);
    sfRectangleShape_setTexture(new_mob->rect, new_mob->text, 0);
    sfRectangleShape_setSize(new_mob->rect, (sfVector2f){100, 100});
    new_mob->next = g->sc_play->pet->mob;
    new_mob->time = sfClock_getElapsedTime(g->clock);
    new_mob->clock_anim = sfClock_getElapsedTime(g->clock);
    sfRectangleShape_setScale(new_mob->rect, (sfVector2f){-1, 1});
    new_mob->bounds = (sfIntRect){0, 0, 32, 32};
    g->sc_play->pet->mob = new_mob;
}

static void init_petanque2(game_t *g)
{
    g->sc_play->pet->tower_text = sfTexture_createFromFile(TOWER_SRC, NULL);
    sfRectangleShape_setSize(g->sc_play->pet->direction,
    (sfVector2f){150, 50});
    sfRectangleShape_setOrigin(g->sc_play->pet->direction,
    (sfVector2f){50, 25});
    g->sc_play->pet->move_dir = sfTrue;
    sfRectangleShape_setTexture(g->sc_play->pet->direction,
        g->sc_play->pet->tower_text, 0);
    g->sc_play->pet->dir = 1;
    g->sc_play->pet->save = sfClock_getElapsedTime(g->clock);
    g->sc_play->pet->moving_bowl = sfFalse;
    g->sc_play->pet->count = 0;
    g->sc_play->pet->angle = 0.0;
    g->sc_play->pet->time_ball = sfClock_getElapsedTime(g->clock);
    g->sc_play->pet->bowl = NULL;
    g->sc_play->pet->mob_clock = sfClock_getElapsedTime(g->clock);
    g->sc_play->pet->kill = 0;
}

static void modif_funcs_btn(game_t *g)
{
    buttons_func[0].pos = ch_coor((sfVector2f){1050, 775}, g->w_size);
    buttons_func[0].rect_size = ch_coor((sfVector2f){150, 150}, g->w_size);
    buttons_func[1].pos = ch_coor((sfVector2f){850, 775}, g->w_size);
    buttons_func[1].rect_size = ch_coor((sfVector2f){150, 150}, g->w_size);
}

static void init_win(game_t *g)
{
    g->sc_play->pet->text = sfText_create();
    sfText_setPosition(g->sc_play->pet->text,
    ch_coor((sfVector2f){1920 / 2, 1080 / 2}, g->w_size));
    sfText_setFillColor(g->sc_play->pet->text, sfBlack);
    sfText_setString(g->sc_play->pet->text, "You Won !");
    sfText_setFont(g->sc_play->pet->text, g->font);
    rect_btn(&g->sc_play->pet->btn, buttons_func[1]);
    g->sc_play->pet->life_tab = malloc(sizeof(sfRectangleShape *) * 3);
    for (int i = 0; i < g->sc_play->pet->life; i++)
        g->sc_play->pet->life_tab[i] = create_life(i + 1);
}

void init_petanque(game_t *g)
{
    g->sc_play->pet = malloc(sizeof(petanque_t));
    g->sc_play->pet->direction = sfRectangleShape_create();
    g->sc_play->pet->mob = NULL;
    g->sc_play->pet->btn = NULL;
    g->sc_play->pet->background = sfRectangleShape_create();
    g->sc_play->pet->back_text = sfTexture_createFromFile(PET_BACK, NULL);
    sfRectangleShape_setTexture(g->sc_play->pet->background,
    g->sc_play->pet->back_text, 0);
    sfRectangleShape_setPosition(g->sc_play->pet->background,
    (sfVector2f){0, 0});
    sfRectangleShape_setSize(g->sc_play->pet->background, g->w_size);
    sfRectangleShape_setPosition(g->sc_play->pet->direction,
    ch_coor((sfVector2f){200, 540}, g->w_size));
    sfRectangleShape_setRotation(g->sc_play->pet->direction, -40.0);
    g->sc_play->pet->life = 3;
    modif_funcs_btn(g);
    rect_btn(&g->sc_play->pet->btn, buttons_func[0]);
    init_petanque2(g);
    init_win(g);
}
