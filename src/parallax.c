/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** functions for parallax
*/

#include <stdio.h>
#include <stdlib.h>

#include "../include/my_runner.h"
#include "../include/my.h"
#include "../include/graphic_lib.h"

scenery_t *choose_next(node_t *node, int i, int opt)
{
    scenery_t *next_bckgd = NULL;
    sfVector2f pos = {0, 0};

    if (!(i % 2)) {
        next_bckgd = (scenery_t *) node->next->data;
        if (opt) {
            pos.x = 1920 + next_bckgd->speed.x;
            sfSprite_setPosition(next_bckgd->sprite, pos);
        }
    } else {
        next_bckgd = (scenery_t *) node->prev->data;
        if (opt) {
            pos.x = 1920 + 2 * next_bckgd->speed.x;
            sfSprite_setPosition(next_bckgd->sprite, pos);
        }
    }
    return (next_bckgd);
}

void move_map(list_t *map_list)
{
    node_t *current_node = NULL;
    block_t *current_block = NULL;
    int nb_destroyed = 0;

    if (map_list->nb_elements) {
        current_node = map_list->head;
        current_block = (block_t *) current_node->data;
    }
    for (int i = 0; i < map_list->nb_elements + nb_destroyed; i++) {
        if (sfSprite_getPosition(current_block->sprite).x + 50 < 0) {
            current_node = current_node->next;
            current_block = (block_t *) current_node->data;
            delete_element(map_list, i - nb_destroyed);
            nb_destroyed++;
        } else if (current_node->type < 3) {
            sfSprite_move(current_block->sprite, (sfVector2f) {-2, 0});
            current_node = current_node->next;
            current_block = (block_t *) current_node->data;
        } else {
            current_node = current_node->next;
            current_block = (block_t *) current_node->data;
        }
    }
}

void move_scenery(list_t *background_list)
{
    node_t *current_node = background_list->head;
    scenery_t *current_bckgrnd = (scenery_t *) current_node->data;
    scenery_t *next_bckgrnd = NULL;
    sfVector2f rect = {0};

    for (int i = 0; i < background_list->nb_elements; i++) {
        rect = sfSprite_getPosition(current_bckgrnd->sprite);
        next_bckgrnd = choose_next(current_node, i, 0);
        if (rect.x < -1920 && next_bckgrnd->active == -1) {
            next_bckgrnd = choose_next(current_node, i, 1);
            next_bckgrnd->active = 1;
        }
        if (rect.x < -3840)
            current_bckgrnd->active = -1;
        if (current_bckgrnd->active == 1)
            sfSprite_move(current_bckgrnd->sprite, current_bckgrnd->speed);
        current_node = current_node->next;
        current_bckgrnd = (scenery_t *) current_node->data;
    }
}

void display_background(list_t *list, sfRenderWindow *window)
{
    node_t *current = list->head->next;
    scenery_t *scenery = (scenery_t *) list->head->data;

    if (scenery->active != -1)
        sfRenderWindow_drawSprite(window, scenery->sprite, NULL);
    while (current != list->head) {
        scenery = (scenery_t *) current->data;
        if (scenery->active != -1)
            sfRenderWindow_drawSprite(window, scenery->sprite, NULL);
        current = current->next;
    }
}
