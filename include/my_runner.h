/*
** EPITECH PROJECT, 2021
** graphic_lib
** File description:
** header file for my_runner
*/

#ifndef MY_RUNNER_H_
    #define MY_RUNNER_H_

    #include <SFML/Graphics.h>
    #include "graphic_lib.h"

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

typedef struct player_s {
    sfTexture *texture;
    sfSprite *sprite;
    int is_jumping; 
    sfVector2f gravity;
} player_t;

/*-------------------PROTOTYPES--------------------------*/

//GAME LOADING

void launch_game(list_t *map, list_t *background);

list_t *load_background(void);

//CREATE

int create_from_line(list_t *list, char *line, int line_index, 
    char **legend);

block_t *create_block(sfVector2f pos, char *path, int type);

scenery_t *create_scenery(sfVector2f pos, char *path, int active);

//INIT

int init_scenery(scenery_t *scenery, char *path, int active);

int init_block(block_t *block, char *path, int type);


//PARALLAX

void move_scenery(list_t *background_list);

void move_map(list_t *map_list);

//DISPLAY

void display_background(list_t *list, sfRenderWindow *window);

#endif
