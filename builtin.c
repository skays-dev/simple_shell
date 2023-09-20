#include "main.h"

/**
 * isBuiltinCommand - Check if a command is a built-in command.
 * @command: The command to check.
 * Returns: The index of the built-in command if found, or -1 if not found.
 */
int isBuiltinCommand(char *command)
{
char *builtins[] = {
"env", NULL
};
int i;
for (i = 0; builtins[i]; i++)
{
if (my_strcmp(command, builtins[i]) == 0)
{
return (i);
}
}
return (0);
}

/**
 * handleBuiltinCommand - Handle built-in shell commands.
 * @command: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing the program's arguments.
 * @status: A pointer to the exit status of the shell.
 * @index: The index of the command in the input.
 */
void handleBuiltinCommand(char **command, char **argv, int *status, int index)
{
(void) argv;
(void) index;
if (my_strcmp(command[0], "env") == 0)
{
printEnvironment(command, status);
}
}

/**
 * printEnvironment - Print the environment variables to the standard output.
 * @status: A pointer to the exit status of the shell.
 */
void printEnvironment(char **command ,int *status)
{
int i;
(void) status;
for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], my_strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
freeStringArray(command);
(*status) = 0;
}
