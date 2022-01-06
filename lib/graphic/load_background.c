/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** list functions
*/

#include "../../include/my_runner.h"
#include <stdlib.h>

list_t *load_background(void)
{
    char paths[3][29] = {BACKGROUND_1, BACKGROUND_2, BACKGROUND_3};
    list_t *background_list = NULL;
    scenery_t *current = NULL;
    int active = 1;

    background_list = malloc(sizeof(list_t));
    if (!background_list)
        return (NULL);

    background_list = create_empty_list();
    for (int i = 0; i < (NB_BACKGROUND * 2); i++) {
        add_node(background_list, create_scenery((sfVector2f) {0, 0}, paths[i / 2], active), i + 3);
        active = -active;
    }
    return (background_list);
}
