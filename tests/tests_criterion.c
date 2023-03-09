/*
** EPITECH PROJECT, 2022
** tests.c
** File description:
** tests
*/

#include "../includes/sokoban.h"
#include "../includes/my.h"
#include <criterion/criterion.h>

Test(sokoban, check_player_position)
{
    struct sokoban_map *map;
    struct position *pos;

    map = make_map_from_string("##########\n"
                               "#        #\n"
                               "#        #\n"
                               "# PXO  ###\n"
                               "#        #\n"
                               "# OX     #\n"
                               "##########\n");
    pos = get_player_position(map);

    cr_assert_neq(pos, NULL);
    cr_assert_eq(pos->x, 2);
    cr_assert_eq(pos->y, 3);

    free(pos);
    free_map(map);
}
