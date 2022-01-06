/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** file to create default structs
*/

#include "../include/my_runner.h"
#include "../include/my.h"
#include <stdlib.h>

void set_texture_and_pos(sfTexture *texture, sfSprite *sprite, sfVector2f pos)
{
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
}

wall_t *create_wall(sfVector2f pos, int type)
{
    wall_t *new_wall = NULL;

    new_wall = malloc(sizeof(wall_t));
    if (!new_wall)
        return (NULL);
    new_wall->texture = sfTexture_createFromFile(WALL_PATH, NULL);
    new_wall->sprite = sfSprite_create();
    new_wall->bounciness = 0;
    if (!new_wall->texture || !new_wall->sprite)
        return (NULL);
    set_texture_and_pos(new_wall->texture, new_wall->sprite, pos);

    my_printf("Wall created at: %d\t%d\n", (int)pos.x, (int)pos.y);
    return (new_wall);
}

spike_t *create_spike(sfVector2f pos, int type)
{
    spike_t *new_spike = NULL;

    new_spike = malloc(sizeof(spike_t));
    if (!new_spike)
        return (NULL);
    new_spike->texture = sfTexture_createFromFile(SPIKE_PATH, NULL);
    new_spike->sprite = sfSprite_create();
    new_spike->size = 1;
    if (!new_spike->texture || !new_spike->sprite)
        return (NULL);
    set_texture_and_pos(new_spike->texture, new_spike->sprite, pos);

    my_printf("Spike created at: %d\t%d\n", (int)pos.x, (int)pos.y);
    return (new_spike);
}

scenery_t *create_scenery(sfVector2f pos, char *path, int active)
{
    scenery_t *new_scenery = NULL;

    new_scenery = malloc(sizeof(scenery_t));
    if (!new_scenery)
        return (NULL);
    init_scenery(new_scenery, path, active);
    if (!new_scenery->texture || !new_scenery->sprite)
        return (NULL);
    set_texture_and_pos(new_scenery->texture, new_scenery->sprite, pos);

    my_printf("Scenery element created at: %d\t%d\n", (int)pos.x, (int)pos.y);
    return (new_scenery);
}
