/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** sokoban
*/

#include "sokoban.h"

void init(tab_t *tab)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int z = 0;

    for (;tab->file[i] != '\n'; i++);
    tab->nb_rows = i;
    i = 0;
    for (; tab->file[i] != '\0'; i++) {
        if (tab->file[i] == 'O')
            j++;
        if (tab->file[i] == 'X')
            x++;
        if (tab->file[i] == '\n')
            z++;
    }
    tab->nb_cols = z + 1;
    tab->nb_O = j;
    tab->nb_X = x;
}

void double_tab(tab_t *tab)
{
    int i = 0;
    int x = 0;
    int y = 0;

    tab->tab = malloc(sizeof(char *) * ((tab->nb_cols) + 1));
    while (y < tab->nb_cols) {
        x = 0;
        tab->tab[y] = malloc(sizeof(char) * (nb_char(tab->file, i) + 2));
        while (tab->file[i] != '\0' && tab->file[i] != '\n') {
            tab->tab[y][x] = tab->file[i];
            x++;
            i++;
        }
        tab->tab[y][x] = '\n';
        tab->tab[y][x + 1] = '\0';
        y++;
        i++;
    }
    tab->tab[y] = NULL;
    double_save(tab);
}

void fs_open_file(char *filepath, tab_t *tab)
{
    struct stat sb;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        exit(84);
    if (stat(filepath, &sb) == -1) {
        close(fd);
        exit(84);
    }
    tab->file = malloc(sizeof(char) * (sb.st_size + 1));
    tab->size = read(fd, tab->file, sb.st_size);
    tab->file[tab->size] = '\0';
    close(fd);
}

void init_struct(tab_t *tab)
{
    tab->x = 0;
    tab->y = 0;
    tab->nb_rows = 0;
    tab->nb_cols = 0;
    tab->nb_O = 0;
    tab->nb_X = 0;
    tab->size = 0;
    tab->file = NULL;
    tab->tab = NULL;
}

int sokoban(char *str)
{
    tab_t *tab = NULL;

    tab = malloc(sizeof(tab_t));
    init_struct(tab);
    fs_open_file(str, tab);
    manage_file(tab);
    init(tab);
    double_tab(tab);
    check_p(tab);
    game_file(tab);
    return 0;
}
