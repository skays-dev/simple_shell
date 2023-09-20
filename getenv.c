#include "main.h"

/**
 * getenvValue - Get the value of an environment variable by its name.
 * @variableName: The name of the environment variable to retrieve.
 * Returns: A dynamically allocated string containing the variable's value,
 *          or NULL if the variable is not found.
 * The caller is responsible for freeing the allocated memory.
 */
char *getenvValue(char *variableName)
{
int i;
for (i = 0; environ[i]; i++) {
char *envEntry = my_strdup(environ[i]);
char *key = strtok(envEntry, "=");
if (my_strcmp(key, variableName) == 0)
{
char *value = strtok(NULL, "\n");
char *envValue = my_strdup(value);
free(envEntry);
return (envValue);
}
free(envEntry), envEntry = NULL;
}
return (NULL);
}