/*
** EPITECH PROJECT, 2017
** environment_2.c 
** File description:
** environement functions kit
*/

#include <stdlib.h>
#include "environment.h"
#include "my_printf.h"
#include "str_utils.h"
#include "utils.h"

int env_get_size(struct env_t *env)
{
	struct env_t *temp = env;
	int i = 0;

	while (temp->next != NULL) {
		temp = temp->next;
		i++;
	}
	return (i);
}

int env_pop(struct env_t *env, char *name)
{
	struct env_t *temp = env;
	struct env_t *previous = temp;

	while (temp->next != NULL) {
		previous = temp;
		temp = temp->next;
		if(my_strcmp(name, temp->name)) {
			previous->next = temp->next;
			free(temp->name);
			free(temp->value);
			free(temp);
			return (1);
		}
	}
	return (0);
}

char **etsa(struct env_t *env)
{
	int size_env = env_get_size(env);
	char **string_env = my_malloc(sizeof(char *) * (size_env + 1));
	struct env_t *temp = env;
	int actual_size = 0;
	int i = 0;

	while (temp->next != NULL) {
		actual_size = my_strlen(temp->name) + my_strlen(temp->value);
		string_env[i] = my_malloc(sizeof(char) * (actual_size + 1));
		my_strcpy(string_env[i], temp->name);	
		my_strcat(string_env[i], "=");
		my_strcat(string_env[i++], temp->value);	
		temp = temp->next;
	}
	return (string_env);
}	
