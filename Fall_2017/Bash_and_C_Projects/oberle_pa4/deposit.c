/*
 * Ian Oberle
 * CS 2750 PA4
 * 11/4/2017
 */

#include "object.h"
#include "all.h"

void deposit(Account *aptr)
{
    //Necessary Variables
    int look, i, check1 = 0;
    float deposit;

    //Open file for reading and writing
    fptr = fopen("accounts.dat", "rb+");
    printf("Account Number for Deposit: ");
    
    //Enter account number to look for
    scanf("%d",&look);
    for (i = 0; i < 51;i++)
    {
        fread(&aptr[i], sizeof(Account), 1, fptr);
        if(aptr[i].id == look)
        {

            ++check1;

            //Display basic account information
            printf("Account has been found.\n");
            printf("This account is owned by %s %s\n",aptr[i].first, aptr[i].last);
            printf("The current balance of this account is $%.2f\n",aptr[i].bal);
            printf("Enter Deposit Value: ");

            //Enter Deposit Value
            scanf("%f", &deposit);
            aptr[i].bal += deposit;

            //Writes new balance to dat file
            printf("New Balance: $%.2f", aptr[i].bal);
            fseek(fptr, ftell(fptr) - sizeof(Account), SEEK_SET);
            fwrite(&aptr[i], sizeof(Account), 1, fptr);
        }
    }
    //Checks if account was found
    if(check1 < 1)
    {
        printf("Account could not be found.\n");
    }
    fclose(fptr);
}
