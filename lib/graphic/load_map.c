/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** list functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../../include/my.h"
#include "graphic_lib.h"

list_t *load_map(char *path, char **legend,
    int (*f)(list_t *, char *, int, char **))
{
    list_t *map_list = NULL;
    char *line = NULL;
    size_t len = 0;
    int stop = 0;
    FILE *map;
    
    map = fopen(path, "r");
    map_list = create_empty_list();
    if (!map || !map_list)
        return (NULL);
    for (int l_index = 0; getline(&line, &len, map) != -1 && !stop; l_index++)
        stop = f(map_list, line, l_index, legend);
    free(line);
    fclose(map);
    if (!map_list->nb_elements || stop) {
        write(2, "Error: pls select a valid map\n", 30);
        return (NULL);
    }
    return (map_list);
}

