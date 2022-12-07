/*
** EPITECH PROJECT, 2022
** tek1
** File description:
** keypad.c
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

int kp_right(sokoban_t *sokoban)
{
    if (sokoban->game[sokoban->p_y][sokoban->p_x + 1] != '#') {
        if (sokoban->game[sokoban->p_y][sokoban->p_x + 1] == 'X' &&
        sokoban->game[sokoban->p_y][sokoban->p_x + 2] == '#')
            return (0);
        if (sokoban->game[sokoban->p_y][sokoban->p_x + 1] == 'X' &&
        sokoban->game[sokoban->p_y][sokoban->p_x + 2] == 'X')
            return (0);
        if (sokoban->game[sokoban->p_y][sokoban->p_x + 1] == 'X')
            (sokoban->game[sokoban->p_y][sokoban->p_x + 2] = 'X');
        sokoban->game[sokoban->p_y][sokoban->p_x] = ' ';
        if (sokoban->reset[sokoban->p_y][sokoban->p_x] == 'O')
            sokoban->game[sokoban->p_y][sokoban->p_x] = 'O';
        sokoban->game[sokoban->p_y][sokoban->p_x + 1] = 'P';
    }
    return (0);
}

int kp_left(sokoban_t *sokoban)
{
    if (sokoban->game[sokoban->p_y][sokoban->p_x - 1] != '#') {
        if (sokoban->game[sokoban->p_y][sokoban->p_x - 1] == 'X' &&
        sokoban->game[sokoban->p_y][sokoban->p_x - 2] == '#')
            return (0);
        if (sokoban->game[sokoban->p_y][sokoban->p_x - 1] == 'X' &&
        sokoban->game[sokoban->p_y][sokoban->p_x - 2] == 'X')
            return (0);
        if (sokoban->game[sokoban->p_y][sokoban->p_x - 1] == 'X')
            (sokoban->game[sokoban->p_y][sokoban->p_x - 2] = 'X');
        sokoban->game[sokoban->p_y][sokoban->p_x] = ' ';
        if (sokoban->reset[sokoban->p_y][sokoban->p_x] == 'O')
            sokoban->game[sokoban->p_y][sokoban->p_x] = 'O';
        sokoban->game[sokoban->p_y][sokoban->p_x - 1] = 'P';
    }
    return (0);
}

int kp_up(sokoban_t *sokoban)
{
    if (sokoban->game[sokoban->p_y - 1][sokoban->p_x] != '#') {
        if (sokoban->game[sokoban->p_y - 1][sokoban->p_x] == 'X' &&
        sokoban->game[sokoban->p_y - 2][sokoban->p_x] == '#')
            return (0);
        if (sokoban->game[sokoban->p_y - 1][sokoban->p_x] == 'X' &&
        sokoban->game[sokoban->p_y - 2][sokoban->p_x] == 'X')
            return (0);
        if (sokoban->game[sokoban->p_y - 1][sokoban->p_x] == 'X')
            (sokoban->game[sokoban->p_y - 2][sokoban->p_x] = 'X');
        sokoban->game[sokoban->p_y][sokoban->p_x] = ' ';
        if (sokoban->reset[sokoban->p_y][sokoban->p_x] == 'O')
            sokoban->game[sokoban->p_y][sokoban->p_x] = 'O';
        sokoban->game[sokoban->p_y - 1][sokoban->p_x] = 'P';
    }
    return (0);
}

int kp_down(sokoban_t *sokoban)
{
    if (sokoban->game[sokoban->p_y + 1][sokoban->p_x] != '#') {
        if (sokoban->game[sokoban->p_y + 1][sokoban->p_x] == 'X' &&
        sokoban->game[sokoban->p_y + 2][sokoban->p_x] == '#')
            return (0);
        if (sokoban->game[sokoban->p_y + 1][sokoban->p_x] == 'X' &&
        sokoban->game[sokoban->p_y + 2][sokoban->p_x] == 'X')
            return (0);
        if (sokoban->game[sokoban->p_y + 1][sokoban->p_x] == 'X')
            (sokoban->game[sokoban->p_y + 2][sokoban->p_x] = 'X');
        sokoban->game[sokoban->p_y][sokoban->p_x] = ' ';
        if (sokoban->reset[sokoban->p_y][sokoban->p_x] == 'O')
            sokoban->game[sokoban->p_y][sokoban->p_x] = 'O';
        sokoban->game[sokoban->p_y + 1][sokoban->p_x] = 'P';
    }
    return (0);
}
