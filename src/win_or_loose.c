/*
** EPITECH PROJECT, 2022
** tek1
** File description:
** win_or_loose.c
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

void win_condition(sokoban_t *sokoban, int y, int x)
{
    if (sokoban->reset[y][x] == 'O' && sokoban->game[y][x] == 'X') {
        sokoban->win = sokoban->win + 1;
    }
}

void loose_map(sokoban_t *sokoban, int y, int x)
{
    sokoban->loose = 0;
    if (sokoban->game[y][x] == 'X' && sokoban->game[y][x + 1] == '#'
    && sokoban->game[y - 1][x] == '#') {
        sokoban->check_loose[y][x] = '1';
    }
    if (sokoban->game[y][x] == 'X' && sokoban->game[y][x + 1] == '#'
    && sokoban->game[y + 1][x] == '#') {
        sokoban->check_loose[y][x] = '1';
    }
    if (sokoban->game[y][x] == 'X' && sokoban->game[y][x - 1] == '#'
    && sokoban->game[y - 1][x] == '#') {
        sokoban->check_loose[y][x] = '1';
    }
    if (sokoban->game[y][x] == 'X' && sokoban->game[y][x - 1] == '#'
    && sokoban->game[y + 1][x] == '#') {
        sokoban->check_loose[y][x] = '1';
    }
}

void loose_condition(sokoban_t *sokoban, int y, int x)
{
    if (sokoban->check_loose[y][x] == '1')
        sokoban->loose = sokoban->loose + 1;
}

int condition(sokoban_t *sokoban)
{
    sokoban->win = 0;
    for (int y = 0; sokoban->reset[y] != NULL; y++) {
        for (int x = 0; sokoban->reset[y][x] != '\0'; x++)
            win_condition(sokoban, y, x);
    }
    if (sokoban->win == sokoban->O)
        return (2);
    for (int y = 0; sokoban->game[y] != NULL; y++) {
        for (int x = 0; sokoban->game[y][x] != '\0'; x++)
            loose_map(sokoban, y, x);
    }
    for (int y = 0; sokoban->game[y] != NULL; y++) {
        for (int x = 0; sokoban->game[y][x] != '\0'; x++) {
            loose_condition(sokoban, y, x);
        }
    }
    if (sokoban->loose == sokoban->X)
        return (1);
    sokoban->check_loose = my_str_to_word_array(sokoban->map);
    return (0);
}
