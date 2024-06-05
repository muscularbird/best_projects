/*
** EPITECH PROJECT, 2024
** test
** File description:
** error_message
*/

#include "rpg.h"

void my_puterror(char c)
{
    write(2, &c, 1);
}

int error_message(char *message)
{
    for (int i = 0; message[i]; i++) {
        my_puterror(message[i]);
    }
    return 84;
}
