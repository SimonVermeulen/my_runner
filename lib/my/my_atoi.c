/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_atoi
*/

#include "my.h"
#include <stdlib.h>

int my_atoi(char const *str)
{
    int result = 0;
    int power = 0;

    for (; is_num(str[power]); power++);
    for (int i = 0; str[i] != '\0' && is_num(str[i]); i++, power--)
        result += (str[i] - 48) * my_compute_power_rec(10, power - 1);
    return (result);
}

char *my_memset(char *str, char c, int n)
{
    int i = 0;

    while (i != n) {
        str[i] = c;
        i++;
    }
    return (str);
}

int my_len(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

float my_atof(char const *str)
{
    char *tmp = my_strdup(str);
    float result = 0;
    float power_val = 0;
    int i = 0;
    int j = 0;

    for (i = j; str[i] != '.' && str[i] != '\0'; i++);
    tmp[i] = '\0';
    result = (float) my_atoi(&tmp[j]);
    my_memset(tmp, 0, (my_strlen(tmp) + 1));
    if (i != my_strlen(str)) {
        for (j = 0; str[i + 1] != '\0'; i++, j++)
            tmp[j] = str[i + 1];
        tmp[j] = '\0';
        power_val = (float) 1 / (float) my_compute_power_rec(10, my_len(tmp));
        result += (float) my_atoi(tmp) * (float) power_val;
    }
    free(tmp);
    return (result);
}
