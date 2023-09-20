#include "main.h"

/**
 * readCommandLine - Read a line of input from the user.
 * Returns a dynamically allocated string containing the input.
 * The caller is responsible for freeing the allocated memory.
*/
char *readCommandLine(void)
{
char *inputLine = NULL;
size_t bufferSize = 0;
ssize_t bytesRead;
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "$ ", 2);
}
bytesRead = getline(&inputLine, &bufferSize, stdin);
if (bytesRead == -1)
{
free(inputLine);
return (NULL);
}
return (inputLine);
}
