/*
** EPITECH PROJECT, 2018
** get_path.c
** File description:
** get path from environement variable
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "str_utils.h"
#include "utils.h"
#include "environment.h"

//The original pointer is -0x5 of the one returned
char *get_path(char *env[])
{
	int i = 0;
	
	while (42) {
		if (env[i][0] == 'P' && env[i][1] == 'A' &&
		    env[i][2] == 'T' && env[i][3] == 'H' &&
		    env[i][4] == '=')
			return (env[i] + 5);
		i++;
	}
	exit(84);
}

static void reset_env(char *all_path, int nbr)
{
	int j = -1;
	int i = 1;
	
	while (i < nbr)
		if (all_path[++j] == '\0') {
			all_path[j] = ':';
			i++;
		}
}

static char *concate_path(char *program, char *all_path, int *f_c)
{
	int i = 1;
	int j = -1;
	int size_path = 0;
	int size_program = my_strlen(program);
	char *ret = NULL;
	
	while (i < *f_c)
		if (all_path[++j] == '\0')
			i++;
	j++;
	size_path = my_strlen(all_path + j);
	ret = my_malloc(sizeof(char) * (size_program + size_path + 2));
	my_strcat(ret, all_path + j);
	my_strcat(ret, "/");
	my_strcat(ret, program);
	(*f_c)++;
	return (ret);
}

static int set_path(char *all_path)
{
	int nb_path = 1;
	int i = -1;

	while (all_path[++i])
		if (all_path[i] == ':') {
			nb_path++;
			all_path[i] = '\0';
		}
	return (nb_path);
}

char *get_function(char *program, struct env_t *env)
{
	char *all_path = env_get_value(env, "PATH");
	int i = -1;
	int nb_path = set_path(all_path);
	char *ret = NULL;
	int f_cnt = 0;
	
	while (++i < nb_path) {
		ret = concate_path(program, all_path, &f_cnt);
		if (access(ret, F_OK) != -1) {
			reset_env(all_path, nb_path);
			return (ret);
		}
		free(ret);
	}
	reset_env(all_path, nb_path);
	return (NULL);
}
