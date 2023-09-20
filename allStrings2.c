#include "main.h"

/**
 * my_strlen - Calculate the length of a string.
 * @str: The string for which to calculate the length.
 * Returns: The length of the string.
*/
int my_strlen(char *str)
{
int length = 0;
while (str[length])
{
length++;
}
return (length);
}

/**
 * my_strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to append to dest.
 * Returns: A pointer to the concatenated string (dest).
*/
char *my_strcat(char *dest, char *src)
{
char *p = dest;
while (*p)
{
p++;
}
while (*src)
{
*p = *src;
p++;
src++;
}
*p = *src;
return (dest);
}

/**
 * my_strcpy - Copy a string from source to destination.
 * @dest: The destination string.
 * @src: The source string to copy from.
 * Returns: A pointer to the destination string (dest).
*/
char *my_strcpy(char *dest, char *src)
{
int i = 0;
if (dest == src || src == NULL)
{
return dest;
}
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}