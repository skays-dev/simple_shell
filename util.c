#include "main.h"

/**
 * freeStringArray - Frees a dynamically allocated array of strings.
 * @stringArray: The array of strings to free.
 */
void freeStringArray(char **stringArray)
{
int index;

if (!stringArray)
{
return;
}

for (index = 0; stringArray[index]; index++)
{
free(stringArray[index]);
stringArray[index] = NULL;
}

free(stringArray);
stringArray = NULL;
}
