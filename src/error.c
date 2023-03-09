/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** error
*/

#include "sokoban.h"

int manage_error(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n");
    my_putstr("\tmap\tfile representing the warehouse map,");
    my_putstr("containing '#' for walls, \n\t\t'p' for the player, ");
    my_putstr("'X' for boxes and 'O' for storage locations.\n");
    return 0;
}

int manage_file(tab_t *tab)
{
    for (int i = 0; tab->file[i] != '\0'; i++) {
        if (tab->file[i] != '#' && tab->file[i] != ' ' &&
            tab->file[i] != 'X' && tab->file[i] != 'O' &&
            tab->file[i] != 'P' && tab->file[i] != '\n' &&
            tab->file[i] != '\0') {
            my_putstr("Corrupt file !\n");
            exit(84);
            }
    }
    return 0;
}
