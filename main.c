#include "shell.h"

/** 
 * main - Simple shell main function
 * @ac: Count of arguments
 * @av: Arguments
 * Return: 0 Always (success)
*/
int main(int ac, char **argv)
{
    char *line = NULL, **command = NULL;
    int status = 0;
    (void) ac;

    while (1)
    {
        line = read_line();
        if(line == NULL) 
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (status);
        }

        command = splicer(line);
        if(command) {
            continue;
        }


        status = _execute(command, argv);
    }
}
