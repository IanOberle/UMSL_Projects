/*
 * Ian Oberle
 * CS 2750 PA4
 * 11/4/2017
 */
#include "object.h"
#include "all.h"
void inquiry(Account *aptr)
{
    int look, i, check = 0;

    printf("Enter the Account Number to view Balance: ");
    scanf("%d", &look);

    //Opens file for reading and writing
    fptr = fopen("accounts.dat", "rb+");
    for(i = 0; i < 51; i++)
    {
        fread(&aptr[i], sizeof(Account), 1, fptr);
        if (aptr[i].id == look)
        {
            check++;

            //Displays basic account information
            printf("Account has been found. Retrieving Balance.\n");
            printf("This account belongs to %s %s %s\n",aptr[i].first,aptr[i].middle, aptr[i].last);
            printf("Balance: $%.2f\n", aptr[i].bal);
            fclose(fptr);
        }
    }
    //Checks if account was found
    if(check == 0)
    {
        printf("Account could not be found.\n");
        fclose(fptr);
    }
}
