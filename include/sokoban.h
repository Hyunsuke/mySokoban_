/*
** EPITECH PROJECT, 2022
** tek1
** File description:
** sokoban.h
*/
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef SOKOBAN_H
    #define SOKOBAN_H

typedef struct sokoban_s {
    char *map;
    char **game;
    char **reset;
    char ** check_loose;
    int map_size;
    int count;
    int l;
    int ch;
    int temp_y;
    int temp_x;
    int p_y;
    int p_x;
    int p_z;
    int O;
    int X;
    int win;
    int loose;
} sokoban_t;

void back_nb(sokoban_t *sokoban);
void larger_length(sokoban_t *sokoban);
void search_p(sokoban_t *sokoban);
void pushing_p(sokoban_t *sokoban);
void manage_input(sokoban_t *sokoban);
int kp_right(sokoban_t *sokoban);
int kp_left(sokoban_t *sokoban);
int kp_up(sokoban_t *sokoban);
int kp_down(sokoban_t *sokoban);
int condition(sokoban_t *sokoban);
void win_condition(sokoban_t *sokoban, int y, int x);
void loose_map(sokoban_t *sokoban, int y, int x);
void loose_condition(sokoban_t *sokoban, int y, int x);

#endif /* SOKOBAN_H */
