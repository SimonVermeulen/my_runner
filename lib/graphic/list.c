/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** list functions
*/

#include "../../include/graphic_lib.h"
#include <stdlib.h>

list_t *create_empty_list(void)
{
    list_t *new_list = malloc(sizeof(list_t));

    if (!new_list)
        return (NULL);

    new_list->head = NULL;
    new_list->nb_elements = 0;

    return (new_list);
}

void add_node(list_t *list, void *data, int type)
{
    node_t *head = list->head;
    node_t *new_node = NULL;

    new_node = malloc(sizeof(node_t));
    if (!new_node)
        return;
    new_node->data = data;
    new_node->type = type;
    if (!head) {
        new_node->next = new_node->prev = new_node;
        list->head = new_node;
    } else {
        head->prev->next = new_node;
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev = new_node;
    }
    list->nb_elements++;
}

void delete_element(list_t *list, int id)
{
    node_t *head = list->head;
    node_t *current = head;

    for (int i = 0; i < id; i++)
        current = current->next;

    current->prev->next = current->next;
    current->next->prev = current->prev;
    if (current == head)
        list->head = current;
    free(current);
}

void delete_list(list_t *list, node_t *current)
{
    current = current->next;
    if (current != list->head) {
        delete_list(list, current);
        free(current);
    } else {
        free(current);
        free(list);
    }
}
