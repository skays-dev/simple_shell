#include "main.h"

/**
 * main - Simple shell main function
 * @argc: Count of arguments
 * @argv: Arguments
 * Return: 0 Always (success)
 */
int main(int argc, char **argv) {
char *line = NULL, **command = NULL;
int status = 0, index = 0;

(void)argc;

while (1) {
line = readCommandLine();
if (line == NULL)
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "\n", 1);
}
return (status);
}
index++;
command = tokenizeInput(line);
if (!command)
{
continue;
}
if (isBuiltinCommand(command[0]))
{
handleBuiltinCommand(command, argv, &status, index);
}
else
{
status = executeCommand(command, argv, index);
}
}
}
