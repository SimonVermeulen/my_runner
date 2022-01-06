/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** functions for parallax
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/graphic_lib.h"
#include "../../include/my_runner.h"
#include "../../include/my.h"

scenery_t *choose_next(node_t *node, int i)
{
    if (!(i % 2))
        return ((scenery_t *) node->next->data);
    else
        return ((scenery_t *) node->prev->data);
}

void move_scenery(list_t *background_list)
{
    node_t *current_node = background_list->head;
    scenery_t *current_bckgrnd = (scenery_t *) current_node->data;
    scenery_t *next_bckgrnd = NULL;
    sfVector2f rect = {0};

    for (int i = 0; i < background_list->nb_elements; i++) {
        rect = sfSprite_getPosition(current_bckgrnd->sprite);
        next_bckgrnd = choose_next(current_node, i);
        if (rect.x < -1920 && next_bckgrnd->active == -1) {
            next_bckgrnd = choose_next(current_node, i);
            next_bckgrnd->active = 1;
            sfSprite_setPosition(next_bckgrnd->sprite, (sfVector2f) {1920, 0});
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
/*
trouver pourquoi petite cindure une fois sur deux (sans doute à cause de la vitesse) 

vitesse * 3 semble marcher (from a chaque fois to une fois sur deux)

trouver solutions pour les lignes trop longues (macro ?)
*/
