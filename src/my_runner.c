/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** main file for my_runner
*/

#include "../include/my_runner.h"
#include "../include/my.h"
#include <stdlib.h>

static int usage(int ac, char *str)
{
    if (ac == 2 && !my_strcmp(str, "-h")) {
        my_printf("Finite runner created with CSFML\n\n");
        my_printf("USAGE:\n./my_runner map.txt\n\n");
        my_printf("OPTIONS:\n-h print the usage and quit\n\n");
        my_printf("USER_INTERACTIONS:\nSPACE_KEY\tjump\n");
        my_printf("ESCAPE\tquit the game\n");
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    list_t *background_list = NULL;
    list_t *map_list = NULL;
    player_t *player = NULL;
    char **legend = NULL;
    sfVector2f max_coord = {0};

    legend = load_legend(LEGEND_PATH);
    if (!legend)
        return (84);
    map_list = load_map(av[1], legend, &create_from_line);
    if (usage(ac, av[1]))
        return (0);
    if (!map_list || !map_list->nb_elements)
        return (84);
    max_coord = get_offset(map_list);
    player = check_player(map_list, max_coord);
    background_list = load_background();
    if (!background_list->nb_elements || !player)
        return (84);
    return(launch_game(map_list, background_list, player));
}
