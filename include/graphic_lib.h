/*
** EPITECH PROJECT, 2021
** graphic_lib
** File description:
** header file for graphic lib
*/

#ifndef GRAPHIC_LIB_H_
    #define GRAPHIC_LIB_H_

//MACROS
//STRUCT DEFS

typedef struct node_s {
    void *data;
    int type;
    struct node_s *next;
    struct node_s *prev;
} node_t;

typedef struct list_s {
    node_t *head;
    int nb_elements;
} list_t;

//LIST PROTOTYPES

list_t *create_empty_list(void);

void add_node(list_t *list, void *data, int type);

void delete_element(list_t *list, int id);

void delete_list(list_t *list, node_t *current);

//MAP LOADING

list_t *load_map(char *path);

list_t *load_background(void);

//PARALLAX

void move_scenery(list_t *background_list);

#endif
