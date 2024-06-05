/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/scenes/save/draw_save
** File description:
** csfml is the best thing ever
*/

#include "rpg.h"

void draw_save_scene(game_t *g)
{
    button_t *tmp = g->sc_save->button;

    sfRenderWindow_clear(g->window, sfBlack);
    sfRenderWindow_drawSprite(g->window, g->sc_save->back_sprite, NULL);
    draw_button(g, tmp);
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawRectangleShape(g->window,
            g->sc_save->saves[i]->sqa, sfFalse);
        sfRenderWindow_drawText(g->window, g->sc_save->saves[i]->text, 0);
    }
    sfRenderWindow_drawSprite(g->window, g->cursor, NULL);
    sfRenderWindow_display(g->window);
}
