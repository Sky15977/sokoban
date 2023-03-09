/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** lib
*/

#include <unistd.h>

#ifndef MY_SOKOBAN_H
    #define MY_SOKOBAN_H

//my_put.c
    void my_putchar(char c);
    int my_putstr(char const *str);
    long long int my_put_nbr(long long int nb);
    long long int my_putnbr_base(long long int nbr, char const *base);

//my_str.c
    int my_strlen(char const *str);
    char *my_strcat(char *dest, char const *src);

#endif
