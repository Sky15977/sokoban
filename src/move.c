/*
** EPITECH PROJECT, 2022
** move.c
** File description:
** move p
*/

#include "sokoban.h"

void move_up(tab_t *tab)
{
    if (tab->tab[tab->y - 1][tab->x] == 'X' &&
        tab->tab[tab->y - 2][tab->x] != '#' &&
        tab->tab[tab->y - 2][tab->x] != 'X') {
        if (tab->save[tab->y][tab->x] == 'O')
            tab->tab[tab->y][tab->x] = 'O';
        else
            tab->tab[tab->y][tab->x] = ' ';
        tab->tab[tab->y - 1][tab->x] = 'P';
        tab->tab[tab->y - 2][tab->x] = 'X';
        tab->y--;
    }
    if (tab->tab[tab->y - 1][tab->x] != 'X') {
        if (tab->save[tab->y][tab->x] == 'O')
            tab->tab[tab->y][tab->x] = 'O';
        else
            tab->tab[tab->y][tab->x] = ' ';
        tab->tab[tab->y - 1][tab->x] = 'P';
        tab->y--;
    }
}

void move_down(tab_t *tab)
{
    if (tab->tab[tab->y + 1][tab->x] == 'X' &&
        tab->tab[tab->y + 2][tab->x] != '#' &&
        tab->tab[tab->y + 2][tab->x] != 'X') {
        if (tab->save[tab->y][tab->x] == 'O')
            tab->tab[tab->y][tab->x] = 'O';
        else
            tab->tab[tab->y][tab->x] = ' ';
        tab->tab[tab->y + 1][tab->x] = 'P';
        tab->tab[tab->y + 2][tab->x] = 'X';
        tab->y++;
    }
    if (tab->tab[tab->y + 1][tab->x] != 'X') {
        if (tab->save[tab->y][tab->x] == 'O')
            tab->tab[tab->y][tab->x] = 'O';
        else
            tab->tab[tab->y][tab->x] = ' ';
        tab->tab[tab->y + 1][tab->x] = 'P';
        tab->y++;
    }
}

void move_left(tab_t *tab)
{
    if (tab->tab[tab->y][tab->x - 1] == 'X' &&
        tab->tab[tab->y][tab->x - 2] != '#' &&
        tab->tab[tab->y][tab->x - 2] != 'X') {
        if (tab->save[tab->y][tab->x] == 'O')
            tab->tab[tab->y][tab->x] = 'O';
        else
            tab->tab[tab->y][tab->x] = ' ';
        tab->tab[tab->y][tab->x - 1] = 'P';
        tab->tab[tab->y][tab->x - 2] = 'X';
        tab->x--;
    }
    if (tab->tab[tab->y][tab->x - 1] != 'X') {
        if (tab->save[tab->y][tab->x] == 'O')
            tab->tab[tab->y][tab->x] = 'O';
        else
            tab->tab[tab->y][tab->x] = ' ';
        tab->tab[tab->y][tab->x - 1] = 'P';
        tab->x--;
    }
}

void move_right(tab_t *tab)
{
    if (tab->tab[tab->y][tab->x + 1] == 'X' &&
        tab->tab[tab->y][tab->x + 2] != '#' &&
        tab->tab[tab->y][tab->x + 2] != 'X') {
        if (tab->save[tab->y][tab->x] == 'O')
            tab->tab[tab->y][tab->x] = 'O';
        else
            tab->tab[tab->y][tab->x] = ' ';
        tab->tab[tab->y][tab->x + 1] = 'P';
        tab->tab[tab->y][tab->x + 2] = 'X';
        tab->x++;
    }
    if (tab->tab[tab->y][tab->x + 1] != 'X') {
        if (tab->save[tab->y][tab->x] == 'O')
            tab->tab[tab->y][tab->x] = 'O';
        else
            tab->tab[tab->y][tab->x] = ' ';
        tab->tab[tab->y][tab->x + 1] = 'P';
        tab->x++;
    }
}

void move_key(int key, tab_t *tab)
{
    if (key == KEY_UP && tab->tab[tab->y - 1][tab->x] != '#')
        move_up(tab);
    if (key == KEY_DOWN && tab->tab[tab->y + 1][tab->x] != '#')
        move_down(tab);
    if (key == KEY_LEFT && tab->tab[tab->y][tab->x - 1] != '#')
        move_left(tab);
    if (key == KEY_RIGHT && tab->tab[tab->y][tab->x + 1] != '#')
        move_right(tab);
}
