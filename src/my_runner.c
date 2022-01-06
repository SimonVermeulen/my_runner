/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** main file for my_runner
*/

#include "../include/graphic_lib.h"
#include "../include/my_runner.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    list_t *map_list = NULL;
    list_t *background_list = NULL;

    map_list = load_map(av[1]);
    background_list = load_background();
    if (!map_list || !background_list)
        return (84);
    launch_game(background_list, map_list);
    return (0);
}
