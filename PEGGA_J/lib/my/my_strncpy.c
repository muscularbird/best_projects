/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** copy an str onto another
*/

char *my_strncpy(char *dest, char const *str, int n)
{
    int i = 0;

    for (; i < n; i++) {
        if (str[i] != '\0')
            dest[i] = str[i];
        else {
            dest[i] = '\0';
            return dest;
        }
    }
    dest[i] = '\0';
    return dest;
}
