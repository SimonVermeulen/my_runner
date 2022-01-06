/*
** EPITECH PROJECT, 2021
** graphic_lib
** File description:
** header file for my_runner
*/

/*
    Faire une structure par type avec chacune son type et son constructeur
        - 0 background
        - 1 murs/sol
        - 2 spykes
        - 3 ennemis
        - 4 joueur
        - 5 portails ?? faire un type pour celui d'arrivée et un pour celui d'entrée et les link par id ???
    FAIRE MAP LABYRINTHE AVEC LES PORTAILS
*/

#ifndef MY_RUNNER_H_
    #define MY_RUNNER_H_

    #include <SFML/Graphics.h>
    #include "../include/graphic_lib.h"

#define WALL_PATH   "ressources/img/wall.png"
#define SPIKE_PATH  "ressources/img/spike.png"

#define BACKGROUND_1 "ressources/img/city.png"
#define BACKGROUND_2 "ressources/img/cloud.png"
#define BACKGROUND_3 "ressources/img/mountains.png"

#define NB_BACKGROUND 3

//STRUCTS DEFS

typedef struct wall_s {
    sfTexture *texture;
    sfSprite *sprite;
    int bounciness;
} wall_t;

typedef struct spike_s {
    sfTexture *texture;
    sfSprite *sprite;
    int size;
} spike_t;

typedef struct scenery_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f speed;
    int active;
} scenery_t;

typedef struct to_display_s {
    sfTexture *texture;
    sfSprite *sprite;
} to_display_t;

//PROTOTYPES

void launch_game(list_t *map, list_t *background);

wall_t *create_wall(sfVector2f pos, int type);

spike_t *create_spike(sfVector2f pos, int type);

scenery_t *create_scenery(sfVector2f pos, char *path, int active);

void display_background(list_t *list, sfRenderWindow *window);

#endif
