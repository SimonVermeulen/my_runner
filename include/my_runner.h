/*
** EPITECH PROJECT, 2021
** graphic_lib
** File description:
** header file for my_runner
*/

#ifndef MY_RUNNER_H_
    #define MY_RUNNER_H_

    #include <SFML/Graphics.h>
    #include "../lib/graphic/graphic_lib.h"

#define LEGEND_PATH "ressources/json/legend.json"
#define NB_OBJECTS 2

#define WALL_PATH   "ressources/json/wall.json"
#define SPIKE_PATH  "ressources/json/spike.json"

#define BACKGROUND_1 "ressources/json/background_1.json"
#define BACKGROUND_2 "ressources/json/background_2.json"
#define BACKGROUND_3 "ressources/json/background_3.json"

#define NB_BACKGROUND 3

#define IS_VALID_CHAR(c, max) (c >= max && c != '\0' && c != ' ' && c != '\n') ? 0 : 1

//STRUCTS DEFS

typedef struct block_s {
    sfTexture *texture;
    sfSprite *sprite;
    int dmg;
    int bounciness;
    int type;
} block_t;

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

//CREATE

block_t *create_block(sfVector2f pos, char *path, int type);

scenery_t *create_scenery(sfVector2f pos, char *path, int active);

//INIT

int init_scenery(scenery_t *scenery, char *path, int active);

int init_block(block_t *block, char *path, int type);

//DISPLAY

void display_background(list_t *list, sfRenderWindow *window);

#endif
