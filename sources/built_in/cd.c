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
#include "environment.h"

char *get_were(char *file)
{
	char *ret = 0;
	int size = my_strsize(file);
	char *cwd = getcwd(NULL, 0);

	ret = my_calloc(sizeof(char) * (my_strsize(cwd) + size + 2));
	my_strcat(ret, cwd);
	my_strcat(ret, "/");
	my_strcat(ret, file);
	free(cwd);
	return (ret);
}

static int choose_case(struct env_t *env, char *cmd[])
{
	int ret = 0;
	char *home = NULL;
	
	if (cmd[1] == 0x0) {
		home = env_get_value(env, "HOME");
		ret = chdir(home);
		return (ret);
	} else if (cmd[1][0] != '/' && cmd[1][0] != '~') {
		if (cmd[1][0] == '-' && cmd[1][1] == '\0') {
			ret = chdir(env_get_value(env, "OLDPWD"));
		} else if (cmd[1][0]) {
			ret = chdir(get_were(cmd[1]));
		}
	} else {
		ret = chdir(cmd[1]);
	}
	return (ret);
}

//Three entry point actual diretory, ~ and /
int my_cd(char *cmd[], struct env_t *env)
{
	int ret = 0;
	char *cwd = NULL;
	
	ret = choose_case(env, cmd);
	if (ret == -1) {
		my_printf("%s", cmd[1]);
		perror(" :");
	} else {
		env_pop(env, "OLDPWD");
		env_push_two_part(env, "OLDPWD", env_get_value(env, "PWD"));
		env_pop(env, "PWD");
		cwd = getcwd(NULL, 0);
		env_push_two_part(env, "PWD", cwd);
		free(cwd);
	}
	return (ret);
}
