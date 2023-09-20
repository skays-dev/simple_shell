#include "main.h"

/**
 * reverseString - Reverses a string in-place.
 * @str: The string to reverse.
 * @length: The length of the string.
 */
void reverseString(char *str, int length)
{
char temp;
int start = 0;
int end = length - 1;
while (start < end)
{
temp = str[start];
str[start] = str[end];
str[end] = temp;
start++;
end--;
}
}

/**
 * _itoa - Convert an integer to a string.
 * @n: The integer to convert.
 * Returns: A dynamically allocated string representation of the integer.
 * The caller is responsible for freeing the allocated memory.
 */
char *_itoa(int n)
{
char buffer[20];
int i = 0;
if(n == 0)
buffer[i++] = '0';
else
{
while(n > 0)
{
buffer[i++] = (n % 10) + '0';
n /= 10;
}
}
buffer[i] = '\0';
reverseString(buffer, i);
return(my_strdup(buffer));
}

/**
 * printError - Prints an error message to the standard error.
 * @programName: The name of the program.
 * @command: The command that resulted in an error.
 * @index: The index where the error occurred.
 */
void printError(char *programName, char *command, int index)
{
char *indexString, message[] = ": not found\n";
indexString = _itoa(index);
write(STDERR_FILENO, programName, strlen(programName));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, indexString, strlen(indexString));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, command, strlen(command));
write(STDERR_FILENO, message, strlen(message));
free(indexString);
}
