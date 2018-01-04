/*
** EPITECH PROJECT, 2018
** env.c
** File description:
** environnement function
*/

#include <my_printf.h>

int my_env(char *cmd[], char *env[])
{
	int i = 0;

	while (env[++i] != 0x0) {
		my_printf("%s\n", env[i]);
	}
	return (0);
}
