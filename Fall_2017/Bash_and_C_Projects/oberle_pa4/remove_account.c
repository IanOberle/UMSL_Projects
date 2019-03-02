/*
 * Ian Oberle
 * CS 2750 PA4
 * 11/4/2017
 */
#include "object.h"
#include "all.h"
void remove_account(Account *aptr)
{
    int i, look;

    fptr = fopen("accounts.dat", "wb+");

    printf("Enter the Account Number of the Account you wish to Delete: ");
    scanf("%d",&look);
    
    //Rewrites all current accounts if no account is found to delete
    if(look < 100000 || look >= 1000000)
    {
        for(i = 0; i < 51; i++)
            fwrite(&aptr[i], sizeof(Account), 1, fptr);
        printf("Account could not be found.\n");
        return(0);
    }

    //Rewrites all currenct accounts except for the specified account
    for(i = 0; i < 51;i++)
    {
        if(look != aptr[i].id)
            fwrite(&aptr[i], sizeof(Account), 1, fptr);
    }
    fclose(fptr);
}
