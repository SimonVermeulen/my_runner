/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** event_handling
*/

#include "../../include/my_runner.h"
#include "graphic_lib.h"

void handle_events(sfEvent event, sfRenderWindow *window)
{
    if (event.key.code == sfKeyEscape || event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        
    }
}
