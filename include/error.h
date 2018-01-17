/*
** EPITECH PROJECT, 2018
** error.h
** File description:
** error header
*/

#ifndef ERROR_H_
#define ERROR_H_

#include "environment.h"

int check_error(int status, struct env_t *env);
void my_perror(const char *str);
int is_dir(char *prog);

#endif /* ERROR_H_ */
