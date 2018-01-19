/*
** EPITECH PROJECT, 2017
** getnextline.c
** File description:
** get next line
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int remo(char buffer[])
{
	int j = 0;

	while (buffer[j++] != '\n' && buffer[j] != '\0');
	for (int i = 0; i < READ_SIZE; i++)
		if (buffer[j] != '\0')
			buffer[i] = buffer[j++];
		else
			buffer[i] = '\0';
	return (1);
}

int cat(char *dest, char *str)
{
	int i = 0;
	int j = 0;

	if (str != NULL) {
		while (str[j])
			dest[i++] = str[j++];
		dest[i] = 0;
		free(str);
	} else {
		dest[0] = 0;
	}
	return (i);
}

char *alloc_bigger(char *ret, char buffer[], int size_buff)
{
	char *newstr = NULL;
	int size_ret = -1;
	int j = -1;
	int i = -1;

	if (ret == NULL)
		newstr = malloc(sizeof(char) * (size_buff + 3));
	else {
		while (ret[++size_ret]);
		newstr = malloc(sizeof(char) * ((size_ret) + (size_buff) + 3));
	}
	if (newstr == NULL)
		return (NULL);
	i = cat(newstr, ret);
	while (buffer[++j] != '\0' && buffer[j] != '\n' && j < READ_SIZE)
		newstr[i++] = buffer[j];
	newstr[i] = buffer[j];
	newstr[i + 1] = '\0';
	remo(buffer);
	return (newstr);
}

int there_is_back(char *ret)
{
	int i = -1;

	if (ret == NULL)
		return (1);
	while (ret[++i])
		if (ret[i] == '\n') {
			ret[i] = '\0';
			return (1);
		}
	return (0);
}

char *get_next_line(int fd)
{
	static char buffer[READ_SIZE];
	char *ret = NULL;
	int bool = 0;
	int size_buffer = 0;
	int i = -1;

	do {
		if (!buffer[0])
			bool = read(fd, buffer, READ_SIZE);
		if (!buffer[0] && bool < 0) {
			(ret != NULL) ? free(ret) : 0;
			return (NULL);
		} else if (!buffer[0] && bool == 0)
			return (ret);
		while (buffer[++i] != '\0' && buffer[i] != '\n')
			size_buffer++;
		ret = alloc_bigger(ret, buffer, size_buffer);
	} while (!there_is_back(ret));
	return (ret);
}
