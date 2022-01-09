/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** load background
*/

#include "../include/my_runner.h"
#include <stdlib.h>
#include <unistd.h>

list_t *load_background(void)
{
    char paths[3][34] = {BACKGROUND_1, BACKGROUND_2, BACKGROUND_3};
    list_t *background_list = NULL;
    scenery_t *current = NULL;
    int active = 1;

    background_list = malloc(sizeof(list_t));
    if (!background_list)
        return (NULL);

    background_list = create_empty_list();
    for (int i = 0; i < (NB_BACKGROUND * 2); i++) {
        current = create_scenery((sfVector2f) {0, 0}, paths[i / 2], active);
        add_node(background_list, current, 0);
        active = -active;
    }
    return (background_list);
}

sfVector2f get_offset(list_t *map)
{
    block_t *current_block = (block_t *) map->head->data;
    node_t *current_node = map->head;
    sfVector2f max_coord = {0};
    sfVector2f coord = {0};

    max_coord = sfSprite_getPosition(current_block->sprite);
    for (int i = 0; i < map->nb_elements; i++) {
        current_node = current_node->next;
        if (current_node->type < 3) {
            current_block = (block_t *) current_node->data;

            coord = sfSprite_getPosition(current_block->sprite);
            max_coord.y = (coord.y > max_coord.y) ? coord.y : max_coord.y;
        }
    }
    max_coord.x = 0;
    max_coord = apply_offset(map, max_coord);
    return (max_coord);
}

sfVector2f apply_offset(list_t *map, sfVector2f max_coord)
{
    block_t *current_block = (block_t *) map->head->data;
    node_t *current_node = map->head;

    max_coord.y = 1080 - max_coord.y - 100;
    for (int i = 0; i < map->nb_elements; i++) {
        current_node = current_node->next;
        if (current_node->type < 3) {
            current_block = (block_t *) current_node->data;

            sfSprite_move(current_block->sprite, (sfVector2f) {0, max_coord.y});
        }
    }
    return (max_coord);
}

player_t *check_player(list_t *map, sfVector2f offset)
{
    node_t *current_node = map->head;
    player_t *player = NULL;
    int nb_player = 0;

    for (int i = 0; i < map->nb_elements; i++) {
        if (current_node->type == 3) {
            player = (player_t *) current_node->data;
            sfSprite_move(player->sprite, offset);
            nb_player++;
        }
        current_node = current_node->next;
    }
    if (nb_player != 1) {
        write(2, "Error: invalid nb of player\n", 29);
        return (NULL);
    }
    return (player);
}
