#include "main.h"

/**
 * executeCommand - Executes a command in a child process.
 * @command: An array of strings representing the command and its arguments.
 * @programName: The name of the program (used for error reporting).
 * Returns: The exit status of the child process.
*/
int executeCommand(char **command, char **programName)
{
pid_t childPid;
int childStatus;

childPid = fork();

if (childPid == 0)
{
if (execve(command[0], command, environ) == -1)
{
perror(programName[0]);
freeStringArray(command);
exit(0);
}
}
else
{
waitpid(childPid, &childStatus, 0);
freeStringArray(command);
}

return (WEXITSTATUS(childStatus));
}
