/*
** EPITECH PROJECT, 2021
** C Pool Day 07
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
