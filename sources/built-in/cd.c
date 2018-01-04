/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** cd function for cd built in
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_printf.h"
#include "str_utils.h"
#include "utils.h"

char *get_were(char *file)
{
	char *ret = 0;
	int size = my_strlen(file);
	char cwd[2048];

	getcwd(cwd, sizeof(cwd));
	ret = my_calloc(sizeof(char) * (my_strlen(cwd) + size + 2));
	my_strcat(ret, cwd);
	my_strcat(ret, "/");
	my_strcat(ret, file);
	return (ret);
}

char *get_home(char *env[])
{
	int i = -1;

	while (env[++i] != 0x0)
		if (env[i][0] == 'H' && env[i][1] == 'O' &&
		    env[i][2] == 'M' &&	env[i][3] == 'E' &&
		    env[i][4] == '=')
			return(env[i] + 5);
	return (NULL);
}

static int know_name(char *env[], char *cmd[])
{
	char *path = NULL;
	char *home = NULL;
	char *ret = NULL;
	int error_check = 0;
	int size_home = 0;
	int size_path = 0;

	if (cmd[1][0] == '~') {
		home = get_home(env);
		size_home = my_strlen(home);
		size_path = my_strlen(cmd[1]);
		ret = my_malloc(sizeof(char) * (size_home + size_path + 2));
		my_strcat(ret, home);
		my_strcat(ret, "/");
		my_strcat(ret, cmd[1] + 2);
		error_check = chdir(ret);
		free(ret);
	} else {
		error_check = chdir(cmd[1]);
	}
	return (error_check);
}

//Three entry point actual diretory, ~ and /
int my_cd(char *cmd[], char *env[])
{
	int ret = 0;
	static char old[2048] = "/"; 
	char old_cpy[2048];

	for (int i = 0; i < 2048; i++)
		old_cpy[i] = old[i];
	getcwd(old, sizeof(old));
	if (cmd[1] == 0x0) {
		ret = chdir(get_home(env));
	} else if (cmd[1][0] != '/' && cmd[1][0] != '~') {
		if (cmd[1][0] == '-' && cmd[1][1] == '\0') {
			ret = chdir(old_cpy);
		} else if (cmd[1][0]) {
			ret = chdir(get_were(cmd[1]));
		}
	} else {
		know_name(env, cmd);
	}
	if (ret == -1)
		perror("cmd ");
	return (ret);
}
