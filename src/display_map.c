/*
** EPITECH PROJECT, 2022
** tek1
** File description:
** display_map.c
*/
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "sokoban.h"
#include <curses.h>

void back_nb(sokoban_t *sokoban)
{
    sokoban->win = 0;
    sokoban->loose = 0;
    sokoban->count = 1;
    for (int i = 0; sokoban->game[i] != NULL; i++)
        sokoban->count++;
}

void larger_length(sokoban_t *sokoban)
{
    sokoban->l = 0;
    for (int y = 0; sokoban->game[y] != NULL; y++) {
        for (int x = 0; sokoban->game[y][x] != '\0'; x++) {
            x > sokoban->l ? sokoban->l = x : x == x * 1;
        }
    }
}

void pushing_p(sokoban_t *sokoban)
{
    for (sokoban->temp_x = 0; sokoban->game[sokoban->temp_y][sokoban->temp_x]
    != '\0'; sokoban->temp_x++) {
        if (sokoban->game[sokoban->temp_y][sokoban->temp_x] == 'P') {
            sokoban->p_y = sokoban->temp_y;
            sokoban->p_x = sokoban->temp_x;
        }
    }
}

void manage_input(sokoban_t *sokoban)
{
    if (sokoban->ch == 261)
        kp_right(sokoban);
    if (sokoban->ch == 260)
        kp_left(sokoban);
    if (sokoban->ch == 259)
        kp_up(sokoban);
    if (sokoban->ch == 258)
        kp_down(sokoban);
    if (sokoban->ch == 32) {
        sokoban->game = my_str_to_word_array(sokoban->map);
    }
}

void search_p(sokoban_t *sokoban)
{
    for (sokoban->temp_y = 0; sokoban->game[sokoban->temp_y] != NULL;
    sokoban->temp_y++) {
        pushing_p(sokoban);
    }
}
