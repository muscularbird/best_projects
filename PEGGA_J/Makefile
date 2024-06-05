##
## EPITECH PROJECT, 2023
## this is makefile
## File description:
## moi quand je read le truc
##

BUTTONS	=	create_button.c\
		event_button.c\
		draw_button.c\
		enter_save.c\
		register_save.c\
		del_save.c\
		disable_button.c\
		button_pointed_function.c\
		button_pointed_function2.c\
		pointed_function_window.c\
		pointed_function_binding.c\
		button_pointed_func2.c\

DESTROYS	=	destroy_all_scenes.c\
			destroy_save.c\
			destroy_game.c

INITS	=	init_main_char.c\
		init_pnj.c\
		init_game.c\
		init_music.c\
		create_animation.c\
		init_rain.c\
		init_objects.c

MOUVEMENTS	=	animation.c\
			main_char.c\
			pnj.c\
			vector.c\
			adm.c\
			draw_dialogue.c\
			string.c\
			detect_color.c\
			infos.c\
			boss.c\

SAVE	=	open_save.c\
		infos_mc.c\
		create_save.c\
		delete_save.c\
		open_save2.c\

MINI_GAMES	=	death/init_death.c\
			death/event_death.c\
			death/update_death.c\
			death/draw_death.c\
			\
			petanque/func_petanque.c\
			petanque/init_petanque.c\
			petanque/add_bowl.c\
			petanque/draw_petanque.c\
			petanque/free_petanque.c\
			petanque/update_petanque.c\
			\
			cimetierre_game/func_cimetierre.c\
			\
			labyrinthe/init_laby.c\
			labyrinthe/update_laby.c\
			labyrinthe/event_laby.c\
			labyrinthe/draw_laby.c\
			labyrinthe/free_laby.c\
			\
			underground_skate/draw_skate.c\
			underground_skate/events_skate.c\
			underground_skate/init_skate.c\
			underground_skate/move_sprites.c\
			underground_skate/update_skate.c\
			underground_skate/free_skate.c\

SCENES	=	inv/add_to_tab.c\
		pause/update_pause.c\
		pause/events_pause.c\
		pause/draw_pause.c\
		pause/init_pause.c\
		pause/init_pause2.c\
		settings/update_settings.c\
		settings/events_settings.c\
		settings/draw_settings.c\
		settings/init_buttons_settings.c\
		settings/init_settings.c\
		play/update_play.c\
		play/events_play.c\
		play/draw_play.c\
		play/draw_play2.c\
		play/init_play.c\
		play/update2.c\
		start/update_start.c\
		start/events_start.c\
		start/draw_start.c\
		start/init_start.c\
		save/update_save.c\
		save/events_save.c\
		save/draw_save.c\
		save/init_save.c\
		boss/init_boss.c\
		boss/update_boss.c\
		boss/draw_boss.c\
		boss/events_boss.c\
		boss/main_char_in_boss.c\
		start_lore/init_lore.c\
		start_lore/draw_lore.c\
		start_lore/update_lore.c\
		start_lore/events_lore.c\
		$(addprefix play/, $(MINI_GAMES))

OTHERS	=	main.c\
		add_node.c\
		event_sound.c\
		ch_coor.c\
		error_message.c\

TRANSITION = transition.c\
		draw_start_transition.c\
		draw_save_transition.c\
		draw_play_transition.c\
		draw_death_transition.c\

SRC	=	$(addprefix buttons/, $(BUTTONS))\
		$(addprefix destroys/, $(DESTROYS))\
		$(addprefix inits/, $(INITS))\
		$(addprefix mouvements/, $(MOUVEMENTS))\
		$(addprefix save/, $(SAVE))\
		$(addprefix scenes/, $(SCENES))\
		$(addprefix transition/, $(TRANSITION))\
		$(OTHERS)


OBJ	=	$(addprefix ./src/, $(SRC:.c=.o))

NAME	=	my_rpg

CFLAGS	+=	-Wall -Wextra -lm -Iinclude -Iinclude/lib/ -lcsfml-graphics\
			-lcsfml-audio -lcsfml-window -lcsfml-system -Llib -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug: CFLAGS += -g

debug: clean all

clean:
	rm -f $(OBJ)

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
