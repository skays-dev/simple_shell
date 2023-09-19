#include "main.h"

/**
 * main - Entry point for a simple shell
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: Always returns 0 (success)
 */
int main(int argc, char **argv)
{
char *inputLine = NULL;
char **parsedCommand = NULL;
int exitStatus = 0;

(void)argc;
(void)argv;

while (1)
{
inputLine = readCommandLine();
if (inputLine == NULL)
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "\n", 1);
}
return (exitStatus);
}

parsedCommand = tokenizeInput(inputLine);
if (!parsedCommand)
{
continue;
}

exitStatus = executeCommand(parsedCommand, argv);
}
}
