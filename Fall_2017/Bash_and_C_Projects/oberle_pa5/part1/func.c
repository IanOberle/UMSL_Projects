/*
 * Ian Oberle
 * CS 2750 PA 5
 * 11/09/2017
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void func(int argc, char **argv)
{
    //Initializing necessary variables
    int i, j, sum = 0, check;
    int edit[argc];
    char *arg_ptr;
    char *p;
    char num[10];
    
    //Checking for invalid number of arguments
    if (argc < 2 || argc > 200)
        printf("Invalid number of arguments.\n");
    //Look at command-line arguments for integers and sum them
    for (i = 1; i < argc; i++)
    {
        strcpy(num, argv[i]);
        check = strtol(num, &p, 10);
        if (check == 0)
        {
            edit[i] = 0;
        }
        else
        {
            sum += check;
            edit[i] = 1;
        }
    }
    printf("Sum of integers: %d\n",sum);
    
    //Look at command-line arguments for strings
    //and look for substrings
    for(i = 1; i < argc; i++)
    {
        if (edit[i] == 1)
            continue;
        for(j = i + 1; j < argc; j++)
        {
            arg_ptr = strstr(argv[j], argv[i]);
            if (arg_ptr != NULL)
            {
                printf("%s is a substring of %s\n",argv[i], argv[j]);
            }
        }
    }
}
