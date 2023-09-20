#include "main.h"

/**
 * my_strdup - Duplicates a null-terminated string.
 * @source: The source string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if allocation fails.
*/
char *my_strdup(char *source)
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

/**
 * my_strcmp - Compare two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 * Returns: An integer less than, equal to, or greater than zero if str1
 * is found, respectively, to be less than, to match, or be greater
 * than str2.
*/
int my_strcmp(char *str1, char *str2)
{
int comparison;
comparison = (int)*str1 - (int)*str2;
while (*str1)
{
if (*str1 != *str2)
break;
str1++;
str2++;
comparison = (int)*str1 - (int)*str2;
}
return (comparison);
}
