/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** game_loop
*/

#include "../include/my_runner.h"

void    display_active_nodes(list_t *list, sfRenderWindow *window)
{
    node_t *current = list->head->next;
    to_display_t *to_display = (to_display_t *) list->head->data;

    sfRenderWindow_drawSprite(window, to_display->sprite, NULL);
    while (current != list->head) {
        to_display = (to_display_t *) current->data;
        sfRenderWindow_drawSprite(window, to_display->sprite, NULL);
        current = current->next;
    }
}

void display(list_t *map, list_t *background, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlue);
    move_scenery(background);
    move_map(map);
    display_background(background, window);
    if (map->nb_elements)
        display_active_nodes(map, window);
    sfRenderWindow_display(window);
}

sfRenderWindow *init_window(sfRenderWindow *window, int height, int width,
    char *name)
{
    sfVideoMode mode;

    mode.height = height;
    mode.width = width;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
}

void launch_game(list_t *map, list_t *background, player_t *player)
{
    sfRenderWindow *window = init_window(window, 1080, 1920, "my_runner");
    sfClock *clock = sfClock_create();
    float seconds = 0;
    sfEvent event;
    sfTime time;

    sfRenderWindow_setFramerateLimit(window, 144);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            handle_events(event, window);
        if (seconds > 0.01) {
            display(map, background, window);
            sfClock_restart(clock);
        }
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (!fmap->nb_elements)
            sfRenderWindow_close(window);
    }
}
