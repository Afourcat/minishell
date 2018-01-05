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

char **command_parser(char *str, int *nb);
char *get_path(char *env[]);
char *get_function(char *str, char *env[]);
int free_cmd(char **cmd, int nbr);
char *parse_dot(const char *str);
int given_path(const char *str);
int transform_parser(char *str[], char *env[]);

#endif /* COMMAND_PARSER_H_ */
