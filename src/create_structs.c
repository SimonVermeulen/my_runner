/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** file to create default structs
*/

#include "../include/my_runner.h"
#include "../include/my.h"
#include <stdlib.h>

int create_from_line(list_t *list, char *line, int line_index, 
    char **legend)
{
    sfVector2f pos = {0, (float)line_index * 50};
    int line_size = my_strlen(line);
    char c = 0;

    for (int char_index = 0; char_index < line_size; char_index++) {
        pos.x = (float)char_index * 50;
        if (line[char_index] >= '1' && line[char_index] <= '2') {
            c = line[char_index];
            add_node(list, create_block(pos, legend[c - '1'], 1), c - 48);
        }
        if (!IS_VALID_CHAR(line[char_index], '3'))
            return (1);
    }
    return (0);
}

void set_texture_and_pos(sfTexture *texture, sfSprite *sprite, sfVector2f pos)
{
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
}

block_t *create_block(sfVector2f pos, char *path, int type)
{
    block_t *new_block = NULL;

    new_block = malloc(sizeof(block_t));
    if (!new_block)
        return (NULL);
    if (init_block(new_block, path, type))
        return (NULL);
    if (!new_block || !new_block->texture || !new_block->sprite)
        return (NULL);
    set_texture_and_pos(new_block->texture, new_block->sprite, pos);

    my_printf("Block created at: %d\t%d\n", (int)pos.x, (int)pos.y);
    return (new_block);
}

scenery_t *create_scenery(sfVector2f pos, char *path, int active)
{
    scenery_t *new_scenery = NULL;

    new_scenery = malloc(sizeof(scenery_t));
    if (!new_scenery)
        return (NULL);
    if (init_scenery(new_scenery, path, active))
        return (NULL);
    if (!new_scenery->texture || !new_scenery->sprite)
        return (NULL);
    set_texture_and_pos(new_scenery->texture, new_scenery->sprite, pos);

    my_printf("Scenery element created at: %d\t%d\n", (int)pos.x, (int)pos.y);
    return (new_scenery);
}
