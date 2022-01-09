/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** file to create default structs
*/

#include "../include/my_runner.h"
#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>

int create_from_line(list_t *list, char *line, int line_index, 
    char **legend)
{
    sfVector2f pos = {0, (float)line_index * 50};
    int line_size = my_strlen(line);
    int stop = 0;
    char c = 0;

    for (int char_index = 0; char_index < line_size; char_index++) {
        pos.x = (float)char_index * 50;
        c = line[char_index] - 49;
        if (line[char_index] >= '1' && line[char_index] <= '2')
            stop = add_node(list, create_block(pos, legend[c], c), c + 1);
        else if (line[char_index] == '3')
            stop = add_node(list, create_player(pos, legend[c]), c + 1);
        if (!VALID_CHAR(line[char_index], '4'))
            return (1);
        if (stop)
            return (2);
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
    if (init_block(new_block, path, type)) {
        write(2, JSON_ERROR, 55);
        return (NULL);
    }
    if (!new_block || !new_block->texture || !new_block->sprite) {
        write(2, IMG_ERROR, 54);
        return (NULL);
    }
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
    if (init_scenery(new_scenery, path, active)) {
        write(2, JSON_ERROR, 55);
        return (NULL);
    }
    if (!new_scenery->texture || !new_scenery->sprite) {
        write(2, IMG_ERROR, 54);
        return (NULL);
    }
    set_texture_and_pos(new_scenery->texture, new_scenery->sprite, pos);

    my_printf("Scenery element created at: %d\t%d\n", (int)pos.x, (int)pos.y);
    return (new_scenery);
}

player_t *create_player(sfVector2f pos, char *path)
{
    player_t *new_player = NULL;

    new_player = malloc(sizeof(player_t ));
    if (!new_player)
        return (NULL);
    if (init_player(new_player, path)) {
        write(2, JSON_ERROR, 55);
        return (NULL);
    }
    if (!new_player->texture || !new_player->sprite) {
        write(2, IMG_ERROR, 54);
        return (NULL);
    }
    set_texture_and_pos(new_player->texture, new_player->sprite, pos);

    my_printf("Player created at: %d\t%d\n", (int)pos.x, (int)pos.y);
    return (new_player);
}
