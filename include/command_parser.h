/*
** EPITECH PROJECT, 2018
** commande_parser.c
** File description:
** commande parser
*/

#ifndef COMAND_PARSER_H_
#define COMAND_PARSER_H_

#include <stdio.h>
#include "utils.h"
#include "environment.h"

void alloc_parser(char *str, int *k, int *j);
void assigne_parser(char *str, int *j, int *k, char *word_array);
char **command_parser(char *str, int *nb);
char *get_path(struct env_t *env);
char *get_function(char *str, struct env_t *env);
int free_cmd(char **cmd);
char *parse_dot(const char *str);
int given_path(const char *str);
int transform_parser(char *str[], struct env_t *env);

#endif /* COMMAND_PARSER_H_ */
