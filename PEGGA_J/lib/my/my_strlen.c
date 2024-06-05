/*
** EPITECH PROJECT, 2023
** mystrlen
** File description:
** str len
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
