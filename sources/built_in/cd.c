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
	char cwd[2048];

	getcwd(cwd, sizeof(cwd));
	ret = my_calloc(sizeof(char) * (my_strsize(cwd) + size + 2));
	my_strcat(ret, cwd);
	my_strcat(ret, "/");
	my_strcat(ret, file);
	return (ret);
}
   
//Three entry point actual diretory, ~ and /
int my_cd(char *cmd[], struct env_t *env)
{
	int ret = 0;
	static char old[2048] = "/"; 
	char old_cpy[2048];

	for (int i = 0; i < 2048; i++)
		old_cpy[i] = old[i];
	getcwd(old, sizeof(old));
	if (cmd[1] == 0x0) {
		ret = chdir(env_get_value(env, "HOME"));
	} else if (cmd[1][0] != '/' && cmd[1][0] != '~') {
		if (cmd[1][0] == '-' && cmd[1][1] == '\0') {
			ret = chdir(old_cpy);
		} else if (cmd[1][0]) {
			ret = chdir(get_were(cmd[1]));
		}
	} else
		ret = chdir(cmd[1]);	
	if (ret == -1)
		perror("cmd ");
	return (ret);
}
