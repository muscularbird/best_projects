/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** init_lore
*/

#include "rpg.h"

static char const *lore[] = {
    "\tDurant un soir a EPITECH Nancy, un etudiant s'appretant a partir",
    "",
    "",
    "\t\tremarqua que la porte de la cave etait entre-ouverte...",
    "",
    "",
    "\t\tPris de curiosite, il decida de se diriger vers la porte",
    "",
    "",
    "\tMais alors qu'il se penchait pour observer ce qu'il se tramait...",
    "",
    "",
    "\t\tUne ombre le poussa par derriere et il tomba dans la cave",
    "",
    "",
    "\t\tIci allait commencer son periple pour regagner la surface...",
};

sfText *create_txt_lore(char const *str, game_t *g)
{
    float y_coor = 1080;
    float diff = 70.0;
    static int i = 0;
    sfText *txt = sfText_create();

    sfText_setFont(txt, g->font);
    sfText_setFillColor(txt, sfYellow);
    sfText_setString(txt, str);
    sfText_setPosition(txt,
    ch_coor((sfVector2f){300, y_coor + (i * diff)}, g->w_size));
    sfText_setScale(txt, ch_coor((sfVector2f){1, 1}, g->w_size));
    i++;
    if (i >= 16)
        i = 0;
    return txt;
}

void init_lore(game_t *g)
{
    g->sc_lore = malloc(sizeof(lore_t));
    g->sc_lore->lore = malloc(sizeof(sfText *) * 16);
    for (int i = 0; i != 16; i++)
        g->sc_lore->lore[i] = create_txt_lore(lore[i], g);
}
