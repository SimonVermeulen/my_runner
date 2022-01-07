/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** main file for my_runner
*/

#include "../include/my_runner.h"
#include "../include/my.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    list_t *map_list = NULL;
    list_t *background_list = NULL;
    char **legend = NULL;

    legend = load_legend(LEGEND_PATH);
    my_printf("legend of map parsed\n");

    map_list = load_map(av[1], legend);
    if (!map_list || !map_list->nb_elements)
        return(84);

    background_list = load_background();
    if (!background_list->nb_elements)
        return (84);
    launch_game(background_list, map_list);
    return (0);
}
