/*
** EPITECH PROJECT, 2018
** minishell.h
** File description:
** minishell header file
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_
#define UNUSED __attribute__ ((unused))

#include "environment.h"

int my_cd(char *cmd[], struct env_t *env);
int my_exit(char *cmd[], struct env_t *env);
int my_env(char *cmd[], struct env_t *env);
int my_setenv(char *cmd[], struct env_t *env);
int my_unsetenv(char *cmd[], struct env_t *env);
void my_exec(char **cmd, char *prog, struct env_t *env);

static const char * const BUILT_IN_STR[5] = {"cd", "exit", "env", "setenv", "unsetenv"};
static const int BUILT_IN_NB = 5;
static int (* const BUILT_IN[5]) (char **, struct env_t *env) = \
{&my_cd, &my_exit, &my_env, &my_setenv, &my_unsetenv};

#endif /* MINISHELL_H_ */
