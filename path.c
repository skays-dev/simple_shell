#include "main.h"

/**
 * findCommandPath - Find the full path of a command in the directories listed in PATH.
 * @command: The command to search for.
 * Returns: A dynamically allocated string containing the full path of the command,
 *          or NULL if not found.
 * The caller is responsible for freeing the allocated memory.
 */
char *findCommandPath(char *command)
{
char *pathEnv, *fullPath, *directory;
struct stat st;
int i;
for (i = 0; command[i]; i++)
{
if (command[i] == '/') {
if (stat(command, &st) == 0)
{
return my_strdup(command);
}
return (NULL);
}
}
pathEnv = getenvValue("PATH");
if (!pathEnv)
{
return (NULL);
}
directory = strtok(pathEnv, ":");
while (directory) {
fullPath = malloc(my_strlen(directory) + my_strlen(command) + 2);
if (fullPath)
{
my_strcpy(fullPath, directory);
my_strcat(fullPath, "/");
my_strcat(fullPath, command);
if (stat(fullPath, &st) == 0)
{
free(pathEnv), pathEnv = NULL;
return (fullPath);
}
free(fullPath), fullPath = NULL;
directory = strtok(NULL, ":");
}
}
free(pathEnv);
return (NULL);
}
