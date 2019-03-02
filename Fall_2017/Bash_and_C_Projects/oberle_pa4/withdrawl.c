/*
 * Ian Oberle
 * CS 2750 PA4
 * 11/4/2017
 */
#include "object.h"
#include "all.h"

void withdrawl(Account *aptr)
{
    int look, i, check = 0;
    float withdrawl; 

    fptr = fopen("accounts.dat", "rb+");
    printf("Account Number for Withdrawl: ");
    scanf("%d",&look);
    for (i = 0; i < 51;i++)
    {
        fread(&aptr[i], sizeof(Account), 1, fptr);
        if(aptr[i].id == look)
        {
            check++;
            printf("Account has been found.\n");
            printf("This account is owned by %s %s\n",aptr[i].first, aptr[i].last);
            printf("The current balance of this account is $%.2f\n",aptr[i].bal);
            printf("Enter Withdrawl Value: ");
            scanf("%f", &withdrawl);
            if (withdrawl <= aptr[i].bal)
                aptr[i].bal -= withdrawl;
            else
            {
                printf("Insufficienct funds for withdrawl.\n");
                fclose(fptr);
                break;
            }
            printf("New Balance: $%.2f",aptr[i].bal);
            fseek(fptr, ftell(fptr) - sizeof(Account), SEEK_SET);
            fwrite(&aptr[i], sizeof(Account), 1, fptr);
            fclose(fptr);
            break;
        }
    }
    if(check == 0)
    {
        printf("Account could not be found.\n");
        fclose(fptr);
    }
    
}
