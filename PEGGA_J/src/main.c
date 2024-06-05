/*
** EPITECH PROJECT, 2024
** /home/maxu/delivery/GRAPH/rpg/src/main
** File description:
** code on paper!
*/

#include "rpg.h"

static int check_help(int ac, char **av)
{
    char *help = "-h";

    if (ac != 2)
        return 0;
    if (strcmp(av[1], help) == 0) {
        printf("RPG Made by Etienne Kretz, Maxence Pierre, Jonathan Lotz ");
        printf("and Remi Dumesnil.\n\nYou're a EPITECH student who fell ");
        printf("down the stairs in the basement. You only want one thing,\n");
        printf("\nEscape.\n");
        return 1;
    }
    return 0;
}

static void check_debug(game_t *g, int ac, char **av)
{
    char *debug = "-debug";

    if (ac != 2)
        return;
    if (strcmp(av[1], debug) == 0)
        g->debug = 1;
}

int main(int ac, char **av)
{
    game_t game = {0};

    if (check_help(ac, av))
        return 0;
    init_game(&game);
    check_debug(&game, ac, av);
    sfRenderWindow_setFramerateLimit(game.window, 240);
    while (sfRenderWindow_isOpen(game.window)) {
        game.menus[game.current_scene].event(&game);
        game.menus[game.current_scene].update(&game);
        game.menus[game.current_scene].draw(&game);
        if (game.next_scene != (menu_t)-1) {
            game.current_scene = game.next_scene;
            game.next_scene = -1;
        }
    }
    destroy_game(&game);
    return (0);
}
