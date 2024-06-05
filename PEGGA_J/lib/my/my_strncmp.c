/*
** EPITECH PROJECT, 2023
** strncmp
** File description:
** comp 2 str
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while ((*s1 == *s2) && (*s1 != 0) && i < n) {
        s1++;
        s2++;
        i++;
    }
    return (*s1 - *s2);
}
