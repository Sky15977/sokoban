/*
** EPITECH PROJECT, 2023
** free.c
** File description:
** free
*/

#include "sokoban.h"

void free_tab(tab_t *tab)
{
    for (int y = 0; tab->tab[y] != NULL; y++)
        free(tab->tab[y]);
    free(tab->tab);
}

void free_save(tab_t *tab)
{
    for (int y = 0; tab->save[y] != NULL; y++)
        free(tab->save[y]);
    free(tab->save);
    free(tab);
}
