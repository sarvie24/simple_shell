#ifndef SHELL_H
#define SHELL_H

#define CODE 1080
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
  * struct builtin_func - structure to hold builtins
  * @arg: argument name
  * @func: function
  *
  *
  */
typedef struct builtin_func
{
	char *arg;
	int (*func)(char **arr);
} builtin_t;


char **make_arr(char *arg, char *dels);
size_t num_tokens(char *arg, char *dels);

void free_path(char **path, char **arr);
void free_all(char **arr, char *n);

int counter(size_t num_comm);

int exit_builtin(char **arr);
int env_builtin(char **arr);
int cd_builtin(char **arr);

char *getenv_builtin(const char *n);
int print_env(void);

void path_creator(char **file, char **arr, int index, char *arg);
int valid_path(char *path);
char *_path_finder(char *name);

char **arr_alloc(char **arr, size_t size, char *message);
char *char_alloc(char **s, size_t size, char *message);
int arr_copy(char **dest, char **src);
int name_env_found(const char *n);
int strlen_env(void);

ssize_t get_the_line(char **input, size_t num, int status);

int preprocessing(char *command, char **arr);

void is_signal(int sig);

int not_found(char **argv, char **commands, size_t num_comm);

int builtin_check(char **arr);
int builtin_expo(char **arr);

void prompt(void);

void reverse_string(char *str);
char *atoi_reverse(size_t num);

#endif
