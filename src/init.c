/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** file to create default structs
*/

#include "../include/my_runner.h"
#include "../include/my.h"
#include <stdlib.h>

void init_scenery(scenery_t *scenery, char *path, int active)
{
    void *data = NULL;
    sfVector2f speed = {0};

    open_file(path, "path", &data);
    scenery->texture = sfTexture_createFromFile((char *) data, NULL);
    scenery->sprite = sfSprite_create();
    data = NULL;
    open_file(path, "speed_x", &data);
    speed.x = *(float *) data * -1.0;
    data = NULL;
    open_file(path, "speed_y", &data);
    speed.y = *(float *) data;

    scenery->speed = speed;
    scenery->active = active;
}
