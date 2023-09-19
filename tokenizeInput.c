#include "main.h"

/**
 * tokenizeInput - Tokenizes a string into an array of strings.
 * @input: The input string to tokenize.
 * Returns: An array of strings containing the tokens, or NULL on failure.
 * The caller is responsible for freeing the allocated memory.
*/
char **tokenizeInput(char *input)
{
char *token = NULL, *temp = NULL, delimiters[] = " \t\n", **commandArray = NULL;
int tokenCount = 0, index = 0;
if (!input)
{
return (NULL);
}
temp = my_strdup(input);
token = strtok(temp, delimiters);
if (token == NULL)
{
free(input), input = NULL;
free(temp), temp = NULL;
return (NULL);
}
while (token)
{
tokenCount++;
token = strtok(NULL, delimiters);
}
free(temp), temp = NULL;
commandArray = (char **)malloc(sizeof(char *) * (tokenCount + 1));
if (!commandArray)
{
free(input), input = NULL;
return (NULL);
}
token = strtok(input, delimiters);
while (token)
{
commandArray[index] = my_strdup(token);
token = strtok(NULL, delimiters);
index++;
}
free(input), input = NULL;
commandArray[index] = NULL;
return (commandArray);
}
