/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** file to create default structs
*/

#include "../include/my_runner.h"
#include "../include/my.h"
#include <stdlib.h>

int init_scenery(scenery_t *scenery, char *path, int active)
{
    void *data = NULL;
    sfVector2f speed = {0};

    open_file(path, "path", &data);
    scenery->texture = sfTexture_createFromFile((char *) data, NULL);
    if (scenery->texture)
        scenery->sprite = sfSprite_create();
    open_file(path, "speed_x", &data);
    speed.x = *(float *) data * -1.0;
    open_file(path, "speed_y", &data);
    speed.y = *(float *) data;

    scenery->speed = speed;
    scenery->active = active;
    return (0);
}

int init_block(block_t *block, char *path, int type)
{
    void *data = NULL;

    if (open_file(path, "path", &data))
        return (1);
    block->texture = sfTexture_createFromFile((char *) data, NULL);
    if (block->texture)
        block->sprite = sfSprite_create();
    open_file(path, "dmg", &data);
    block->dmg = *(int *) data;
    open_file(path, "bounciness", &data);
    block->bounciness = *(int *) data;
    block->type = *(int *) data;
    return (0);
}

int init_player(player_t *player, char *path)
{
    void *data = NULL;
    
    if (open_file(path, "path", &data))
        return (1);
    player->texture = sfTexture_createFromFile((char *) data, NULL);
    if (player->texture)
        player->sprite = sfSprite_create();
    open_file(path, "is_jumping", &data);
    player->is_jumping = *(int *) data;
    open_file(path, "gravity", &data);
    player->gravity = (sfVector2f) {0, *(float *) data};
    player->default_gravity = player->gravity;
    player->is_onfloor = 0;
    return (0);
}
