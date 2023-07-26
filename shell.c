#include "shell.h"

/**
 * tilt - print 
 *
 * Return: void
 */
void tilt(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(1, *env, _strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}
/**
 * tokenize - Tokenizes the input string into an array of arguments.
 * @input: userinput
 * @args: argements
 *
 * Return: the number of arguments.
 */
int tokenize(char *input, char *args[])
{
	int i = 0;
	char *token = strtok(input, " \n\t\r");

	while (token != NULL && i < MAX_ARGS)
	{
		args[i++] = token;
		token = strtok(NULL, " \n\t\r");
	}
	args[i] = NULL;
	return (i);
}
/**
 * exe - execute command
 * @args: argement
 * @env: envirement
 * @av: agenment vector
 * @count: count
 * Return: int
 */
void exe(char *args[], char *env[], char **av, int count)
{
	pid_t pid;
	char cmd[64];
	char *get = NULL;

	_strcpy(cmd, args[0]);
	get = get_cmd(cmd);
	pid = fork();
	if (pid == -1)
	{
		perror("Fork fail");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(get, args, env) == -1)
		{
			write(1, av[0], _strlen(av[0]));
			write(1, ": ", 2);
			print_number(count);
			write(1, ": ", 2);
			_puts(cmd);
			write(1, ": not found\n", 12);
		}
		else
			perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		if (waitpid(pid, &status, 0) == -1)
			perror("waitpid");
	}
}

/**
 * main - main
 * @ac: argenment count
 * @av: argement vector
 * Return: success
 */

int main(__attribute__((unused))int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	char *args[MAX_ARGS + 1];
	char *env[] = {NULL};
	ssize_t line_len;
	int argc;
	int count = 0;

	while (true)
	{
		count++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		line_len = getline(&line, &len, stdin);
		if (line_len == -1)
		{
			write(1, "Exiting shell....\n", 18);
			free(line);
			return (-1);
		}
		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (_strcmp(line, "env\n") == 0)
		{
			tilt();
			continue;
		}
		if (line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		argc = tokenize(line, args);
		if (argc > 0)
			exe(args, env, av, count);
	}
		free(line);
		return (0);
}
