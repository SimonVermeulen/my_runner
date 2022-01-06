/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** list functions
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/graphic_lib.h"
#include "../../include/my_runner.h"
#include "../../include/my.h"

static int create_from_line(list_t *list, char *line, int line_index)
{
    sfVector2f pos = {0, (float)line_index * 50};
    int line_size = my_strlen(line);

    for (int char_index = 0; char_index < line_size; char_index++) {
        pos.x = (float)char_index * 50;
        if (line[char_index] == '1')
            add_node(list, create_wall(pos, 1), 1);
        else if (line[char_index] == '2')
            add_node(list, create_spike(pos, 2), 2);
        if (line[char_index] != '1' && line[char_index] != '2' && line[char_index] != ' ' && line[char_index] != '\n')
            return (1);
    }
    return (0);
}

list_t *load_map(char *path)
{
    list_t *map_list = NULL;
    char *line = NULL;
    size_t len = 0;
    int stop = 0;
    FILE *map;
    
    map = fopen(path, "r");
    if (!map)
        return (NULL);
    map_list = create_empty_list();
    if (!map_list)
        return (NULL);
    for (int l_index = 0; getline(&line, &len, map) != -1 && !stop; l_index++)
        stop = create_from_line(map_list, line, l_index);
    free(line);
    fclose(map);
    if (!map_list->nb_elements)
        return (NULL);
    return (map_list);
}

