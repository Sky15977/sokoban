/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "sokoban.h"

int main(int ac, char **av)
{
    if (ac != 2) {
        my_putstr("USE :\n\t./my_sokoban -h\n");
        return 84;
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        manage_error();
        return 84;
    }
    sokoban(av[1]);
    return 0;
}
