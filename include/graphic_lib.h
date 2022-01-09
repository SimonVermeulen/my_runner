/*
** EPITECH PROJECT, 2021
** graphic_lib
** File description:
** header file for graphic lib
*/

#ifndef GRAPHIC_LIB_H_
    #define GRAPHIC_LIB_H_

    #include <SFML/Graphics.h>

/*---------------------------macros------------------------*/

/*-------------------------struct defs---------------------*/

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

/*-------------------------prototypes---------------------*/

//LIST PROTOTYPES

list_t *create_empty_list(void);

void add_node(list_t *list, void *data, int type);

void delete_element(list_t *list, int id);

void delete_list(list_t *list, node_t *current);

//MAP LOADING

list_t *load_map(char *path, char **legend,
    int (*f)(list_t *, char *, int, char **));

char **load_legend(char *path);

//PARSING

int open_file(char *path, char *key_id, void **value);

//EVENT HANDLING

void handle_events(sfEvent event, sfRenderWindow *window);

#endif
