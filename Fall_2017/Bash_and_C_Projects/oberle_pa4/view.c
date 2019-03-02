/*
 * Ian Oberle
 * CS 2750 PA4
 * 11/4/2017
 */
#include "object.h"
#include "all.h"
void display(Account *aptr)
{
    int i;

    //Opens file for reading and writing
    fptr = fopen("accounts.dat", "rb+");
    for (i = 0; i < 51; i++)
    {
        fread(&aptr[i], sizeof(Account), 1, fptr);
        //Checks if any accounts exists
        if(aptr[0].id < 100000 || aptr[0].id >=1000000)
        {
            printf("No accounts exist.\n");
            fclose(fptr);
            break;
        }

        //Displays information for all created/non-default accounts
        else if (aptr[i].id >= 100000 && aptr[i].id < 1000000)
        { 
            printf("--------------------------------------\n");
            printf("Account Number: %d\n", aptr[i].id);
            printf("Name: %s %s %s\n", aptr[i].first, aptr[i].middle, aptr[i].last);
            printf("Balance: $%.2f\n", aptr[i].bal); 
            printf("--------------------------------------\n");
        }
        //Closes file 
        else
        {
            fclose(fptr);
            break;
        }
    }
}
