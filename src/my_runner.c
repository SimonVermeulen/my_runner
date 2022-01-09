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
    list_t *background_list = NULL;
    list_t *map_list = NULL;
    player_t *player = NULL;
    char **legend = NULL;
    sfVector2f max_coord = {0};

    legend = load_legend(LEGEND_PATH);

    map_list = load_map(av[1], legend, &create_from_line);
    if (!map_list || !map_list->nb_elements)
        return (84);
    max_coord = get_offset(map_list);
    player = check_player(map_list, max_coord);
    if (!player)
        return (84);
    background_list = load_background();
    if (!background_list->nb_elements)
        return (84);
    launch_game(map_list, background_list, player);
    return (0);
}
