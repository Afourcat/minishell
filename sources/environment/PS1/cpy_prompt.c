/*
** EPITECH PROJECT, 2017
** generate_prompt.c
** File description:
** generate a prompt from PS1
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"
#include "environment.h"
#include "str_utils.h"
#include "utils.h"

char *get_wich(char *value, int *i, struct env_t *env)
{
	char *(*egv)(struct env_t*, char *) = &env_get_value; 

	switch(value[(*i) + 1]) {
	case 'u':
		return (my_strdup(egv(env, "USER")));
	case 'h':
		return (my_strdup(egv(env, "HOSTNAME")));
	case 't':
		return (my_strdup("TIME"));
	case 'w':
		return (getcwd(NULL, 100));
	case 'n':
		return (my_strdup("\n"));
	case ']':
	case '[':
		(*i)++;
	}

	return (NULL);
}

int test_str(char *str, int *i)
{
	if (str == NULL)
		return (1);
	(*i)++;
	my_printf(str);
	free(str);
	return (0);
}

char *generate_prompt(struct env_t *env)
{
	int i = -1;
	char *str = NULL;
	char back_e = '\e';
	char *value = env_get_value(env, "PS1");

	while(value[++i] != '\0') {	
		if ((value[i] == '\\' && value[i + 1] == '0' &&
		     value[i + 2] == '3' && value[i + 3] == '3') ||
		    (value [i] == '\\' && value[i + 1] == 'e')) {
			write(1, &back_e, 1);
			i += 3;
		} else if (value[i] == '\\') {
			str = get_wich(value, &i, env);
			test_str(str, &i);
		} else {
			write(1 ,&value[i], 1);
		}
	}
	return ("");
}
