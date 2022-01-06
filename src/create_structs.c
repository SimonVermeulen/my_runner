/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** file to create default structs
*/

#include "../include/my_runner.h"
#include "../include/my.h"
#include <stdlib.h>

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

    sfSprite_setTexture(new_wall->sprite, new_wall->texture, sfTrue);
    sfSprite_setPosition(new_wall->sprite, pos);

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

    sfSprite_setTexture(new_spike->sprite, new_spike->texture, sfTrue);
    sfSprite_setPosition(new_spike->sprite, pos);

    my_printf("Spike created at: %d\t%d\n", (int)pos.x, (int)pos.y);
    return (new_spike);
}

scenery_t *create_scenery(sfVector2f pos, char *path, int active)
{
    scenery_t *new_scenery = NULL;
    sfIntRect rect = {0, 0, 3840, 1080};

    new_scenery = malloc(sizeof(scenery_t));
    if (!new_scenery)
        return (NULL);
    new_scenery->texture = sfTexture_createFromFile(path, NULL);
    new_scenery->sprite = sfSprite_create();
    new_scenery->speed = (sfVector2f) {-2, 0};
    new_scenery->active = active;
    if (!new_scenery->texture || !new_scenery->sprite)
        return (NULL);
    
    sfSprite_setTexture(new_scenery->sprite, new_scenery->texture, sfTrue);
    sfSprite_setPosition(new_scenery->sprite, pos);
    sfSprite_setTextureRect(new_scenery->sprite, rect);

    my_printf("Scenery element created at: %d\t%d\n", (int)pos.x, (int)pos.y);
    return (new_scenery);
}

/*
    --  UTILISER LE PARSER JSON POUR POUVOIR LIRE LES CHEMINS D'ACCÈS VERS LES SPRITES DE CHAQUE ELEMENTS
*/
