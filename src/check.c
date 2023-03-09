/*
** EPITECH PROJECT, 2022
** check.c
** File description:
** check
*/

#include "sokoban.h"

void check_loose(tab_t *tab)
{
    int i = 0;

    for (int y = 0; tab->tab[y] != NULL; y++)
        for (int x = 0; x < tab->nb_rows; x++)
            check_loose_two(tab, x, y, &i);
}

void check_win_two(tab_t *tab, int x, int y, int *i)
{
    if (tab->tab[y][x] == 'X' && tab->save[y][x] == 'O')
        (*i)++;
    if (tab->nb_O == *i) {
        endwin();
        free_tab(tab);
        free_save(tab);
        exit(0);
    }
}

void check_win(tab_t *tab)
{
    int i = 0;

    for (int y = 0; tab->tab[y] != NULL; y++)
        for (int x = 0; x < tab->nb_rows; x++)
            check_win_two(tab, x, y, &i);
}

void check_p_two(tab_t *tab, int x, int y)
{
    if (tab->tab[y][x] == 'P') {
        tab->y = y;
        tab->x = x;
    }
}

void check_p(tab_t *tab)
{
    for (int y = 0; tab->tab[y] != NULL; y++)
        for (int x = 0; x < tab->nb_rows; x++)
            check_p_two(tab, x, y);
}
