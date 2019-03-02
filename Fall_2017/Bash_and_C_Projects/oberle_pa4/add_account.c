/*
 * Ian Oberle
 * CS 2750 PA 4
 * 11/4/2017
 */

#include "object.h"
#include "all.h"

void add_account(Account *aptr)
{
    //Initializing base variables
    int i, j, look;
    char first[16], middle[3], last[16];
    float num;

    //Open file for reading
    fptr = fopen("accounts.dat", "wb");
    if (fptr);
    for (i = 0; i < 51;i++)
    {
        //If account number is default
        if (aptr[i].id == 0)
        {
            //Rewrite all current accounts
            for (j = 0; j < i; j++)
            {
                fwrite(&aptr[j], sizeof(Account), 1, fptr);
            }
            printf("Enter a 6-digit Account Number: ");
            scanf("%d",&look);
                //Looks to see to if account already exists
                for (j = 0; j < i; j++)
                {
                    if(look == aptr[j].id)
                    {
                        printf("Account already exists.\n");
                        return(0);
                    }
                }
                //Checks if entered account number is valid
                if (look < 100000 || look >= 1000000)
                { 
                    printf("An invalid account number was entered.\nNo account was created");
                    break;   
                }
                //Enter all information for new account
                else
                {

                    aptr[i].id = look;
    
                    printf("\nEnter First Name: ");
                    scanf("%s", &first);
                    strcpy(aptr[i].first, first);

                    printf("\nEnter Middle Intial: ");
                    scanf("%s", &middle);
                    strcpy(aptr[i].middle, middle);

                    printf("\nEnter Last Name: ");
                    scanf("%s", &last);
                    strcpy(aptr[i].last, last);

                    printf("\nEnter Account Balance: ");
                    scanf("%f", &num);
                    aptr[i].bal = num;
                    
                    fwrite(&aptr[i], sizeof(Account), 1, fptr);
                    break;
                }
        }
    }
    fclose(fptr);
}

