#include "main.h"

/**
 * my_strdup - Duplicates a null-terminated string.
 * @source: The source string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if allocation fails.
*/
char *my_strdup(const char *source)
{
char *destination;
int index, length = 0;

if (source == NULL)
{
return (NULL);
}

while (*source != '\0')
{
length++;
source++;
}

source = source - length;

destination = (char *)malloc(sizeof(char) * (length + 1));

if (destination == NULL)
{
return (NULL);
}

for (index = 0; index <= length; index++)
destination[index] = source[index];

return (destination);
}
