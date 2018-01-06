/*
** EPITECH PROJECT, 2017
** environment.c
** File description:
** environment list function
*/

#include <stdlib.h>
#include "environment.h"
#include "utils.h"
#include "str_utils.h"
#include "my_printf.h"

char *env_get_value(struct env_t *env, char *name)
{
	struct env_t *temp = env;

	while (!my_strcmp(temp->name, name) && temp->next != NULL) {
		temp = temp->next;
	}
	return (temp->value);
}

static void assign_name(struct env_t *env, char *value)
{
	int i = -1;
	int j = 0;
	int size_name = -1;
	int size_value = 0;
	
	while (value[++size_name] != '=');
	env->name = my_malloc(sizeof(char) * (size_name + 2));
	while (value[size_name + (++size_value)] != '\0');
	env->value = my_malloc(sizeof(char) * (size_value + 2));
	while (++i < size_name)
		env->name[i] = value[i];
	env->name[i + 1] = 0;
	while (++i < size_value + size_name)
		env->value[j++] = value[i];
	env->value[j + 1] = 0;
	env->next = NULL;
}

void env_push(struct env_t *env, char *value)
{
	struct env_t *temp = env;
	struct env_t *new_elem = malloc(sizeof(struct env_t));

	assign_name(new_elem, value);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_elem;
}

struct env_t *env_create(char *envp[])
{
	int i = -1;
	struct env_t *env = malloc(sizeof(struct env_t));

	assign_name(env, envp[++i]);
	while (envp[++i] != 0)
		env_push(env, envp[i]);
	return (env);
}

void env_printf(struct env_t *env)
{
	struct env_t *temp = env;

	while (temp->next != NULL) {
		my_printf("NAME  = %s\n", temp->name);
		my_printf("VALUE = %s\n", temp->value);
		temp = temp->next;
	}
}

#ifdef DEBUG_1

int main(int argc, char *argv[], char *envp[])
{
	struct env_t *env = env_create(envp);
	env_printf(env);
	my_printf("GET TEST \n");
	my_printf("get USER %s\n", env_get_value(env, "USER"));
	my_printf("get PATH %s\n", env_get_value(env, "PATH"));
	return (0);
}

#endif /* DEBUG_1 */
