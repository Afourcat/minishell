/*
** EPITECH PROJECT, 2017
** setenv.c
** File description:
** built in header for setenv
*/

#include "environment.h"

int my_setenv(char *cmd[], struct env_t *env)
{
	env_push(env, cmd[1]);
	return (0);
}

int my_unsetenv(char *cmd[], struct env_t *env)
{
	env_pop(env, cmd[1]);	
	return (0);
}
