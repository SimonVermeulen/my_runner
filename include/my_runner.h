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

enum NB_OBJECTS {
    NB_OBJECTS = 2
};

#define WALL_PATH   "ressources/json/wall.json"
#define SPIKE_PATH  "ressources/json/spike.json"

#define BACKGROUND_1 "ressources/json/background_1.json"
#define BACKGROUND_2 "ressources/json/background_2.json"
#define BACKGROUND_3 "ressources/json/background_3.json"

#define JSON_ERROR "Cannot load json file, launch from default repository\n"
#define IMG_ERROR "Cannot load png file, launch from default repository\n"

enum NB_BACKGROUND {
    NB_BACKGROUND = 3   
};

#define VALID_CHAR(c, m) (c >= m && c != '\0' && c != 32 && c != '\n') ? 0 : 1

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
    int is_onfloor;
    sfVector2f gravity;
    sfVector2f default_gravity;
} player_t;

/*-------------------PROTOTYPES--------------------------*/

//GAME LOADING

void launch_game(list_t *map, list_t *background, player_t *player);

list_t *load_background(void);

sfVector2f get_offset(list_t *map);

sfVector2f apply_offset(list_t *map, sfVector2f max_coord);

player_t *check_player(list_t *map, sfVector2f offset);

//CREATE

int create_from_line(list_t *list, char *line, int line_index, 
    char **legend);

block_t *create_block(sfVector2f pos, char *path, int type);

scenery_t *create_scenery(sfVector2f pos, char *path, int active);

player_t *create_player(sfVector2f pos, char *path);

//INIT

int init_scenery(scenery_t *scenery, char *path, int active);

int init_block(block_t *block, char *path, int type);

int init_player(player_t *player, char *path);

//PARALLAX

void move_scenery(list_t *background_list);

void move_map(list_t *map_list);

//DISPLAY

void display_background(list_t *list, sfRenderWindow *window);

//PLAYER

void jump(player_t *player);

void launch_jump(player_t *player);

void check_hitbox(player_t *player, list_t *map);

#endif
