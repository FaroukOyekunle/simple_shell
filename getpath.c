#include <string.h>
#include "shell.h"
#include <stdlib.h>
#include <sys/stat.h>
/**
 * get_cmd - get PATH
 * @line: line
 *
 * Return: NULL
 */
char *get_cmd(char *line)
{
	char *path, *path_copy, *path_token, *file_path;
	int line_len, dir_len;
	struct stat file_stats;

	path = getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		line_len = _strlen(line);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			dir_len = strlen(path_token);
			file_path = malloc(line_len + dir_len + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, line);
			_strcat(file_path, "\0");
			if (stat(file_path, &file_stats) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(line, &file_stats) == 0)
			return (line);
	}
	return (NULL);
}
