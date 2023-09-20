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
int executeCommand(char **command, char **argv, int index);

/* PATH */
char *findCommandPath(char *command);

/* environ */
char *getenvValue(char *variableName);

/* all utils functions */
void freeStringArray(char **stringArray);
void reverseString(char *str, int length);
void printError(char *programName, char *command, int index);
char *_itoa(int n);

/* all builtin commands */
int isBuiltinCommand(char *command);
void handleBuiltinCommand(char **command, char **argv, int *status, int index);
void printEnvironment(char **command ,int *status);

/* all Strings Functions */
char *my_strdup(char *source);
int my_strcmp(char *str1, char *str2);
int my_strlen(char *str);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char *src);



#endif
