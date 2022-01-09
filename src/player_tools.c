/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** player tools
*/

#include "../include/my_runner.h"
#include <stdlib.h>

void launch_jump(player_t *player)
{
    if (!player->is_jumping) {
        player->is_jumping = 1;
        player->gravity.y *= -1;
    }
}

void jump(player_t *player)
{
    if (!player->is_onfloor)
        player->gravity.y += 0.10;
    if (player->is_onfloor) {
        player->is_jumping = 0;
        player->gravity.y = player->default_gravity.y;
    }
    if (!player->is_onfloor)
        sfSprite_move(player->sprite, player->gravity);
}

int check_floor_hitbox(player_t *player, sfVector2f player_pos, sfVector2f blockoord)
{
    if (player_pos.x >= blockoord.x && player_pos.x <= blockoord.x + 50 &&
        player_pos.y + player->gravity.y >= blockoord.y) {
        player->is_onfloor = 1;
        blockoord.y = blockoord.y - player_pos.y;
        blockoord.x = 0;
        sfSprite_move(player->sprite, blockoord);
        return (1);
    } else {
        player->is_onfloor = 0;
    }
    return (0);
}

int check_wall_hitbox(player_t *player, sfVector2f player_pos, sfVector2f blockoord)
{

    if (player_pos.x >= blockoord.x - 2 &&
        player_pos.x <= blockoord.x + 50 - 2 &&
        player_pos.y == blockoord.y)
        return(0);
    return (0);
}

void check_hitbox(player_t *player, list_t *map)
{
    sfVector2f player_pos = sfSprite_getPosition(player->sprite);
    node_t *current_node = map->head;
    block_t *current_block = NULL;
    sfVector2f blockoord = {0};
    int stop = 0;

    player_pos.y += 71;
    for (int i = 0; i < map->nb_elements && !stop; i++) {
        if (current_node->type != 3) {
            current_block = (block_t *) current_node->data;
            blockoord = sfSprite_getPosition(current_block->sprite);
            stop = check_wall_hitbox(player, player_pos, blockoord);
            stop = check_floor_hitbox(player, player_pos, blockoord);
        }
        current_node = current_node->next;
    }
}
