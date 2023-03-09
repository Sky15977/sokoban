/*
** EPITECH PROJECT, 2022
** game_file.c
** File description:
** game_file
*/

#include "sokoban.h"

int nb_char(char *str, int nb)
{
    int i = 0;

    for (i = nb; str[i] != '\0'; i++);
    return i - nb;
}

void check_loose_two(tab_t *tab, int x, int y, int *i)
{
    if (tab->tab[y][x] == 'X' &&
        ((tab->tab[y + 1][x] == '#' && tab->save[y][x + 1] == '#') ||
         (tab->tab[y + 1][x] == '#' && tab->save[y][x - 1] == '#') ||
         (tab->tab[y - 1][x] == '#' && tab->save[y][x - 1] == '#') ||
         (tab->tab[y - 1][x] == '#' && tab->save[y][x + 1] == '#')))
        (*i)++;
    if (tab->nb_X == *i) {
        endwin();
        free_tab(tab);
        free_save(tab);
        exit(1);
    }
}

void check(tab_t *tab)
{
    check_win(tab);
    check_loose(tab);
}

void double_save(tab_t *tab)
{
    int i = 0;
    int x = 0;
    int y = 0;

    tab->save = malloc(sizeof(char *) * ((tab->nb_cols) + 1));
    while (y < tab->nb_cols) {
        x = 0;
        tab->save[y] = malloc(sizeof(char) * (nb_char(tab->file, i) + 2));
        while (tab->file[i] != '\0' && tab->file[i] != '\n') {
            tab->save[y][x] = tab->file[i];
            x++;
            i++;
        }
        tab->save[y][x] = '\n';
        tab->save[y][x + 1] = '\0';
        y++;
        i++;
    }
    free(tab->file);
    tab->save[y] = NULL;
}

void game_file(tab_t *tab)
{
    int key;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        for (int cols = 0; cols < tab->nb_cols; cols++)
            printw("%s", tab->tab[cols]);
        refresh();
        key = getch();
        move_key(key, tab);
        check(tab);
        if (key == ' ') {
            double_tab(tab);
            check_p(tab);
        }
    }
    endwin();
    exit(84);
}
