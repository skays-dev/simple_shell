#include "shell.h"

/** 
 * main - Simple shell main function
 * @ac: Count of arguments
 * @av: Arguments
 * Return: 0 Always (success)
*/
int main(int ac, char **argv)
{
    char *line = NULL;
    /*char **command = NULL;*/
    int status = 0;
    (void) ac;
    (void) argv;

    while (1)
    {
        line = read_line();
        if(line == NULL) 
            return (status);

        printf("%s", line);
        free(line);
        /* command = splicer(line);

        status = _execute(command, argv); */
    }
}
