/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/mouvements/draw_dialogue
** File description:
** rm -rf --no-preserve-root /
*/

#include "rpg.h"

static void draw_txt(game_t *g, ADM_t *adm)
{
    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->map_sp, NULL);
    sfRenderWindow_drawSprite(g->window, g->mc->animation->sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->map_up, NULL);
    sfRenderWindow_drawSprite(g->window, adm->a->sprite, NULL);
    sfRenderWindow_drawSprite(g->window, adm->back_text, NULL);
    sfRenderWindow_drawSprite(g->window, adm->pp, NULL);
    sfRenderWindow_drawText(g->window, adm->text, NULL);
    sfRenderWindow_display(g->window);
    sfSleep(sfSeconds(DELAY_DIALOGUE));
}

static void draw_txt_sk(game_t *g, ADM_t *adm)
{
    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawRectangleShape(g->window, g->sc_play->sk->bg, NULL);
    sfRenderWindow_drawSprite(g->window, g->mc->animation->sprite, NULL);
    sfRenderWindow_drawSprite(g->window, adm->back_text, NULL);
    sfRenderWindow_drawSprite(g->window, adm->pp, NULL);
    sfRenderWindow_drawText(g->window, adm->text, NULL);
    sfRenderWindow_display(g->window);
    sfSleep(sfSeconds(DELAY_DIALOGUE));
}

static void which_txt(game_t *g, ADM_t *adm)
{
    if (!g->sc_play->dialogue_sk)
        draw_txt(g, adm);
    else
        draw_txt_sk(g, adm);
}

void update_adm_anim(game_t *g, float delta)
{
    ADM_t *tmp = g->adm;

    while (tmp) {
        update_animation(tmp->a, delta, 0, 12);
        tmp = tmp->next;
    }
}

static void init_text(ADM_t *adm, game_t *g)
{
    sfText_setFont(adm->text, g->font);
    sfText_setCharacterSize(adm->text, 24);
    sfText_setScale(adm->text, (sfVector2f){0.20, 0.20});
    sfText_setFillColor(adm->text, sfBlack);
    sfText_setPosition(adm->text,
    (sfVector2f){adm->pos.x - 150, adm->pos.y + 70});
    sfText_setString(adm->text, adm->dialogue[adm->index]);
}

static void init_text_sk(ADM_t *adm, game_t *g)
{
    sfText_setFont(adm->text, g->font);
    sfText_setCharacterSize(adm->text, 18);
    sfText_setScale(adm->text, (sfVector2f){2, 2});
    sfText_setFillColor(adm->text, sfBlack);
    sfText_setPosition(adm->text, (sfVector2f){195, g->w_size.y - 195});
    sfSprite_setScale(adm->pp, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(adm->pp,
        (sfVector2f){g->w_size.x - 340, g->w_size.y - 170});
    sfSprite_setPosition(adm->back_text, (sfVector2f){950, g->w_size.y - 170});
    sfSprite_setScale(adm->back_text, (sfVector2f){2.5, 1.5});
    sfText_setString(adm->text, adm->dialogue[adm->index]);
}

static void which_init_text(ADM_t *adm, game_t *g)
{
    if (!g->sc_play->dialogue_sk)
        init_text(adm, g);
    else
        init_text_sk(adm, g);
}

void draw_dialogue(ADM_t *adm, game_t *g)
{
    which_init_text(adm, g);
    if (!adm->display_complete) {
        for (int i = 0; adm->dialogue[adm->index][i] != '\0'; ++i) {
            sfText_setString(adm->text,
            substring(adm->dialogue[adm->index], 0, i));
            which_txt(g, adm);
        }
        sfText_setString(adm->text, substring(adm->dialogue[adm->index],
        0, strlen(adm->dialogue[adm->index]) - 1));
        sfRenderWindow_drawText(g->window, adm->text, NULL);
        adm->display_complete = sfTrue;
    }
    if (adm->index == adm->len - 1)
        adm->finish = sfTrue;
}
