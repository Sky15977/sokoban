/*
** EPITECH PROJECT, 2022
** sokoban.h
** File description:
** dico func
*/

#include <stdio.h>

#include "my.h"
#include <ncurses.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#ifndef SOKOBAN_H
    #define SOKOBAN_H

//struct
    typedef struct tab_s {
        int x;
        int y;
        int nb_rows;
        int nb_cols;
        int nb_O;
        int nb_X;
        int size;
        char *file;
        char **tab;
        char **save;
    } tab_t;

//error.c
    int manage_error(void);
    int manage_file(tab_t *tab);

//sokoban.c
    void init(tab_t *tab);
    void double_tab(tab_t *tab);
    void fs_open_file(char *filepath, tab_t *tab);
    void init_struct(tab_t *tab);
    int sokoban(char *str);

//move.c
    void move_up(tab_t *tab);
    void move_down(tab_t *tab);
    void move_left(tab_t *tab);
    void move_right(tab_t *tab);
    void move_key(int key, tab_t *tab);

//check.c
    void check_loose(tab_t *tab);
    void check_win_two(tab_t *tab, int x, int y, int *i);
    void check_win(tab_t *tab);
    void check_p_two(tab_t *tab, int x, int y);
    void check_p(tab_t *tab);

//game_file.c
    int nb_char(char *str, int nb);
    void check_loose_two(tab_t *tab, int x, int y, int *i);
    void check(tab_t *tab);
    void double_save(tab_t *tab);
    void game_file(tab_t *tab);

//free.c
    void free_tab(tab_t *tab);
    void free_save(tab_t *tab);

#endif
