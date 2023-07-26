#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>

#define MAX_ARGS 64
#define BUFFER_SIZE 64

extern char **environ;
int tokenize(char *input, char *args[]);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
void print_number(int n);
int _putchar(char c);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
char *get_cmd(char *line);
char *_strdup(char *str);
#endif /* MAIN_H */
