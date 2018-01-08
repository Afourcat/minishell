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
	}
	return (NULL);
}

int count_size(char *value, int *i, struct env_t *env)
{
	int ret = 0;
	char *str = NULL;

	if (value[*i] == '\\' && value[*i + 1] != 'e') {
		str = get_wich(value, i, env);
		my_printf("STR = %s\n", str);
		ret += my_strsize(str);
		free(str);
	} else {
		ret++;
	}
	return (ret);
}

static int cpy(char *ret, char *str, int *j, int k)
{
	while (str[++k])
		ret[(*j)++] = str[k];
	return (0);
}

int print_elem(char *value, int *i, struct env_t *env, char *ret)
{
	char *str = NULL;
	static int j = 0;
	int k = -1;

	if (value[*i] == '\\' && value[*i + 1] != 'e') {
		str = get_wich(value, i, env);
		if (str != NULL) {
			cpy(ret, str, &j, k);	
			(*i) += 1;
			free(str);
		}
	} else {
		ret[j++] = value[*i];
	}
	return (j);
}

char *generate_prompt(char *value, struct env_t *env)
{
	int i = -1;
	int size = 0;
	char *ret = NULL;
	int j = 0;

	while (value[++i] != '\0')
		size += count_size(value, &i, env);
	ret = my_calloc(sizeof(char) * (size + 10));	
	i = -1;
	while(value[++i] != '\0')
		j = print_elem(value, &i, env, ret);
	ret[j] = 0;
	i = -1;
	while (ret[++i])
		if (ret[i] == '\\' && ret[i + 1] == 'e') {
			ret[i] = '\e';
			str_swipe(ret, i + 1, 1);
		}
	return (ret);
}
