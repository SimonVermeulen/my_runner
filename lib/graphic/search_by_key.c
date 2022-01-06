/*
** EPITECH PROJECT, 2021
** json_parser
** File description:
** searches an element by key
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

static int get_value_len(char *line)
{
    int value_len = 0;

    for (; line[value_len] != ','; value_len++);
    return (value_len - 1);
}

static char *get_char_value(char *line)
{
    int len = get_value_len(line);
    char *value = NULL;

    value = malloc(sizeof(char) * (len + 1));
    if (!value)
        return (NULL);

    for (int i = 0; line[i] != '"'; i++)
        value[i] = line[i];
    value[len] = '\0';

    return (value);
}

static float *get_float_value(char *line)
{
    float *value = NULL;

    value = malloc(sizeof(float));
    *value = my_atof(line);
    return (value);
}

static void *get_value(char *line)
{
    void *value = NULL;

    for (int i = 0; line[i] && !value; i++) {
        if (i > 2 && line[i - 3] == ':' && line[i - 1] == '"')
            value = get_char_value(&line[i]);
        else if ((line[i] == '-' || is_num(line[i])) && line[i - 2] == ':')
            value = get_float_value(&line[i]);
    }
    return (value);
}

void **open_file(char *path, char *key_id, void **value)
{
    char *line_value = NULL;
    size_t len = 0;
    FILE *fd;

    fd = fopen(path, "r");
    while (getline(&line_value, &len, fd) != -1 && !*value) {
        if (my_strstr(line_value, key_id))
            *value = get_value(line_value);
    }
    fclose(fd);
}
