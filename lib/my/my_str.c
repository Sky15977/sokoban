/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** counts and returns the number of characters found
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;
    int b = 0;

    while (dest[i] != '\0')
        i++;
    while (src[a] != '\0') {
        dest [i + b] = src[a];
        a++;
        b++;
    }
    return (dest);
}

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
