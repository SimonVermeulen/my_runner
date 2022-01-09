/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** game_loop
*/

#include "../include/my_runner.h"

static void handle_events(sfEvent event, sfRenderWindow *window,
    player_t *player)
{
    if (event.key.code == sfKeyEscape || event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && player->is_onfloor &&
        event.key.code == sfKeySpace)
        launch_jump(player);
}

static void display_active_nodes(list_t *list, sfRenderWindow *window)
{
    node_t *current = list->head;
    to_display_t *to_display = NULL;

    for (int i = 0; i < list->nb_elements; i++) {
        to_display = (to_display_t *) current->data;
        if (current->type != 3)
            sfRenderWindow_drawSprite(window, to_display->sprite, NULL);
        current = current->next;
    }
}

static void display(list_t *map, list_t *background, player_t *player,
    sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlue);
    move_scenery(background);
    move_map(map);
    display_background(background, window);
    if (map->nb_elements)
        display_active_nodes(map, window);
    check_hitbox(player, map);
    jump(player);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    sfRenderWindow_display(window);
}

static sfRenderWindow *init_window(sfRenderWindow *window, int height,
    int width, char *name)
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
            handle_events(event, window, player);
        if (seconds > 0.01) {
            display(map, background, player, window);
            sfClock_restart(clock);
        }
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (map->nb_elements == 1 && map->head->type == 3)
            sfRenderWindow_close(window);
    }
}
