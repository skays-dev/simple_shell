#include "main.h"

/**
 * executeCommand - Execute a command and wait for it to complete.
 * @command: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing the program's arguments.
 * @index: The index of the command in the input.
 * Returns: The exit status of the executed command.
 */
int executeCommand(char **command, char **argv, int index)
{
char *fullPath;
pid_t childPid;
int exitStatus;
fullPath = findCommandPath(command[0]);
if (!fullPath)
{
printError(argv[0], command[0], index);
freeStringArray(command);
return (127);
}
childPid = fork();
if (childPid == 0)
{
if (execve(fullPath, command, environ) == -1)
{
free(fullPath), fullPath = NULL;
freeStringArray(command);
}
}
else
{
waitpid(childPid, &exitStatus, 0);
freeStringArray(command);
free(fullPath), fullPath = NULL;
}
return (WEXITSTATUS(exitStatus));
}