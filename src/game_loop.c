/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** game_loop
*/

#include "../include/graphic_lib.h"
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
    display_background(background, window);
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

void launch_game(list_t *map, list_t *background)
{
    sfRenderWindow *window = init_window(window, 1080, 1920, "my_runner");
    sfClock *clock = sfClock_create();
    float seconds = 0;
    sfTime time;

    sfRenderWindow_setFramerateLimit(window, 144);
    while (sfRenderWindow_isOpen(window)) {
        if (seconds > 0.01) {
            display(background, map, window);
            sfClock_restart(clock);
        }
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        
    }
}

/*
FAIRE DES TYPES PLUS GÉNÉRIQUES (MURS ET LES FUSIONER AVEC SPYKE) LES INIT DEPUIS LE JSON PARSER POUR POUVOIR DÉTAILLER COMME JE VEUX

    --  POUR POUVOIR LES AFFICHER PLUS SIMPLEMENT (MOINS DE CAST A FAIRE (PEUT ETRE UNE FONCTION PAR TYPE DE TRUC))

    --  SI EN RETARD PRENDRE LE TRUC DU MY_HUNTER DEPUIS LE DÉBUT ET TOUT MODIFIER AU FUR ET A MESURE

    --  GRAVITÉ = CLOCK INVERSION GRAVITE POUR UN TEMPS INTO RÉINVERSION

    --  SCORE AFFICHER AU FUR ET A MESURE, (DONC GERER LES TEXTES A L'AVANCE)

    --  GERER LES HITBOXS (TRIANGLE ET CARRÉ AU MOINS) (TROUVER FORMULE MATHS POUR LE TRIANGLE)
*/
