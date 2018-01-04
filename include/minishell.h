/*
** EPITECH PROJECT, 2018
** minishell.h
** File description:
** minishell header file
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

int my_cd(char *cmd[], char *env[]);
int my_exit(char *cmd[], char *env[]);
int my_env(char *cmd[], char *env[]);

static const char *BUILT_IN_STR[5] = {"cd", "exit", "env", "setenv", "unsetenv"};
static const int BUILT_IN_NB = 3;
static const int (*BUILT_IN[3]) (char **, char **) = {&my_cd, &my_exit, &my_env};

#endif /* MINISHELL_H_ */
