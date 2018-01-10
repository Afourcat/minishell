/*
** EPITECH PROJECT, 2017
** environment.h
** File description:
** environment header functions
*/

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

struct env_t {
	char *name;
	char *value;
	struct env_t *next;
};

struct env_t *env_create(char *cmd[]);
char *env_get_value(struct env_t *env, char *name);
void env_push(struct env_t *env, char *environment);
void env_push_two_part(struct env_t *env, char *name, char *value);
void env_set_value(char *name, char *value);
void env_delete_value(char *name);
char **etsa(struct env_t *env);
int env_pop(struct env_t *env, char *name);
char *generate_prompt(struct env_t *env);

#endif /* ENVIRONMENT_H_ */
