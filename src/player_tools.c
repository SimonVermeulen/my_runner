/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** player tools
*/

#include "../include/my_runner.h"
#include <stdlib.h>

player_t *init_player(void)
{
    player_t *player = NULL;

    player = malloc(sizeof(player));
    if (!player)
        return (NULL);

    player->texture = sfTexture_createFromFile("ressources/img/player.png", sfTrue);
    player->sprite = sfSprite_create();
    sfSprite_setTexture(player->sprite, player->texture, NULL);
    player->is_jumping = 0;
    player->gravity = (sfVector2f) {0, 5};
    return (player);
}

void jump(player_t *player)
{
    if (player->is_jumping) {
        player->gravity.y += 0.10;
        sfSprite_move(player->sprite, player->gravity);
    }
}
