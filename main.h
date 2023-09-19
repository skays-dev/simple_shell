#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

/* the main functions */
char *readCommandLine(void);
char **tokenizeInput(char *input);
int executeCommand(char **command, char **programName);

/* all utils functions */
void freeStringArray(char **stringArray);

/* all Strings Functions */
char *my_strdup(const char *source);


#endif
