/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** load_legend of the map
*/

#include "graphic_lib.h"
#include "../../include/my.h"
#include <stdlib.h>

static char *concat_strings(char *src, char *src2)
{
    int size = my_strlen(src) + my_strlen(src2);
    char *result = malloc(sizeof(char) * size + 1);
    int i = 0;

    for (; src[i]; i++)
        result[i] = src[i];
    for (int j = 0; src2[j]; j++)
        result[i + j] = src2[j];
    result[size] = '\0';

    return (result);
}

char **load_legend(char *path)
{
    char **legend = NULL;
    int nb_objects = 0;
    void *value = NULL;

    open_file(path, "nb_objects", &value);
    nb_objects = *(float *) value;
    legend = malloc(sizeof(char *) * nb_objects);
    if (!legend)
        return (NULL);
    for (int i = 0; i < nb_objects; i++) {
        open_file(path, concat_strings("block_", my_itos(i + 1)), &value);
        legend[i] = my_strdup(value);
    }
    
    for (int i = 0; i < nb_objects; i++) {
        if (!legend[i])
            return (NULL);
    }
    return (legend);
}
