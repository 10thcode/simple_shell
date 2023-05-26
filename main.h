#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <signal.h>

/**
 * struct env_node - A node that points to an environment variable
 * on the user's environment
 *
 * @name: The variable's name
 * @value: The variable's value
 * @next: The next environment variable
 *
 * Description: Stores all the environment variables
 * found on the user's system
 *
*/
typedef struct env_node
{
	char *name;
	char *value;
	struct env_node *next;
} env_node_t;

#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_MODE 0
#define NULL_FOUND -2
#define INVALID_COMMAND 127
#define VALID_COMMAND 0
#define CTRL_C_SIGNAL_CODE 130
#define IS_ABS_PATH 1
#define IS_REL_PATH 2
#define IS_EXEC 1
#define IS_PATH 1
#define IS_NOT_PATH 0
#define ERROR_OCCURED -1
#define SHLVL_NAME "SHLVL"
#define SHLVL_VAL "1"
#define EQUAL_STRING 0
#define OVERWRITE 1
#define IGNORE 0
#define EXIT (_strcmp(commands[0], "exit") == EQUAL_STRING)

extern char **environ;

int _prompt(char **buffer, size_t *bytes_read);
char **_tokenize(char *str, char *delimiter);
int _tokencount(char *str, char *delimiter);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
void _free(char **commands);
void _freestr(char *str);
int _checkmode(void);
int _execute(char **commands, int commands_executed
, char *program, char **env);
void _printerror(int commands_executed, int param_count, ...);
void print_number(int number);
int _putchar(char character, int file_descriptor);
void handle_sigint(int signum);
int _checkfile(char *path);
int _isrelpath(char *path);
char *_getenvpathvar();
int _isenvvarpath(char *env_variable);
char *_strdup(char *str);
char *_pathbuilder(int argc, ...);
int _checkpath(char *pathname);
char **_loadpaths(env_node_t *head);
char *_getfullpath(char *path, char *command);
int _checkenv(char *command);
void _printenv(void);
void _isexit(char **commands, char *buffer, char **envpath
, int signal_received, char **env_clone);
int _strcmp(char *s1, char *s2);
int _setenv(const char *name, const char *value, int overwrite);
const char *_strstr(const char *haystack, const char *needle);
char **_getenvs(char **env);
env_node_t *_addnodeend(env_node_t **head, char *name, char *value);
env_node_t *_findnode(env_node_t *head, char *name);
void free_list(env_node_t *head);
char *_strdup(char *str);
int _exitshell(char **envpath, char **env_clone, char *buffer);
void _relpath(int *file_info, char **envpath, char **commands
, char *buffer, int *exit_code);
int _isexec(char *path);

extern int signal_received;
extern env_node_t *head;

#endif
