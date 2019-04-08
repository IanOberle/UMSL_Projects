/*
 * Ian Oberle
 * CS 2750 PA5
 * 11/09/2017
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void phone_fmt()
{
    int count = 0;
    char num[11];
    char num1[200];
    int i;
    
    printf("Enter up to 200 integers/character/etc. to create a phone number.\n");
    printf("There must be at least 10 integers entered.");
    printf("\n\nINPUT: ");
    
    scanf("%s",num1);
    
    //Check argument string for integers
    //Stores first ten integers in an array
    for(i = 0; i < strlen(num1); i++)
    {
        if(isdigit(num1[i]) && count != 10)
        { 
            num[count] = num1[i];
            count++;
        }
    }
    
    //Error Message, if there weren't enough integers
    if (count < 10)
        printf("OUTPUT: ERROR: Not enough digits in input!\n");

    //Displays first ten intergers as a phone number
    else
    {
        printf("OUTPUT: ");
        printf("(");
        for(i = 0; i < 3;i++)
            printf("%c", num[i]);
        printf(")");
        for(i = 3; i < 6;i++)
            printf("%c", num[i]);
        printf("-");
        for(i = 6; i < 10;i++)
            printf("%c", num[i]);
        printf("\n\n");
    }
}
