/*
** EPITECH PROJECT, 2022
** ncurses
** File description:
** bootstrap
*/

#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "sokoban.h"

void description(void)
{
    my_printf("USAGE\n     ./my_sokoban map\n DESCRIPTION\n     map file");
    my_printf(" representing the warehouse map, containing '#' for walls,\n");
    my_printf("         'P' for the player, 'X' for boxes and 'O' ");
    my_printf("for storage locations.");
}

int check_map(sokoban_t *sokoban)
{
    sokoban->X = 0; sokoban->O = 0; int P = 0; int D = 0;
    for (int i = 0; sokoban->map[i] != '\0'; i++) {
        if (sokoban->map[i] != '#' && sokoban->map[i] != 'P'
        && sokoban->map[i] != '\n' && sokoban->map[i] != 'X'
        && sokoban->map[i] != 'O' && sokoban->map[i] != ' ')
            return (84);
        if (sokoban->map[i] == 'X') sokoban->X++;
        if (sokoban->map[i] == 'O') sokoban->O++;
        if (sokoban->map[i] == 'P') P++;
        if (sokoban->map[i] == '#') D++;
    }
    if (sokoban->X < sokoban->O)
        return (84);
    if (P != 1 || sokoban->X < 1 || sokoban->O < 1 || D < 1)
        return (84);
    return (0);
}

int fill_sokoban(char *filepath, sokoban_t *sokoban)
{
    struct stat fstat;
    stat(filepath, &fstat);
    if (!S_ISREG(fstat.st_mode))
        return (84);
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    sokoban->map_size = fstat.st_size;
    sokoban->map = malloc(sizeof(char) * (sokoban->map_size + 1));
    if ((read(fd, sokoban->map, sokoban->map_size) <= 0))
        return (84);
    if (check_map(sokoban) == 84) {
        return (84);
    }
    if (close(fd) == -1)
        return (84);
    sokoban->game = my_str_to_word_array(sokoban->map);
    sokoban->reset = my_str_to_word_array(sokoban->map);
    sokoban->check_loose = my_str_to_word_array(sokoban->map);
    return (0);
}

int my_open(sokoban_t *sokoban)
{
    int x = 0; int y = 0; sokoban->ch = 0;
    larger_length(sokoban); back_nb(sokoban); initscr(); keypad(stdscr, true);
    curs_set(0);
    while (true) {
        clear();
        search_p(sokoban); getmaxyx(stdscr, y, x);
        for (int i = 0; sokoban->game[i] != NULL; i++) {
        mvprintw(y / 2 - sokoban->count / 2 + i,
                x / 2 - sokoban->l / 2, "%s\n", sokoban->game[i]);
        }
        sokoban->ch = getch();
        manage_input(sokoban);
        refresh();
        if (sokoban->ch == 27)
            break;
        if (condition(sokoban) == 2) return (0);
        if (condition(sokoban) == 1) return (1);
    }
    endwin();
    return (0);
}

int main(int argc, char **argv)
{
    sokoban_t sokoban;
    char *filepath = argv[1];

    if (argc == 2 && argv[1][0] == '-'
        && argv[1][1] == 'h' && argv[1][2] == '\0') {
        description();
        return (0);
    }
    if (argc != 2)
        return 84;
    if (argc == 2 && fill_sokoban(filepath, &sokoban) == 84)
        return (84);
    if (my_open(&sokoban) == 1) {
        curs_set(1);
        return 1;
    }
    curs_set(1);
    return (0);
}
