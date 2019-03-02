/*
 * Ian Oberle
 * CS 2750 PA 4
 * 11/4/2017
 */

#include "all.h"

int main()
{
    Account accounts[MAX];
    int menu = 0, choice;
    Account *aptr = accounts;

    while (menu >= 0)
    {
        printf("\n--------------------------------------------------------");
        printf("\n0.\tExit\n1.\tDeposit\n2.\tWithdrawl\n3.\tAdd Account\n");
        printf("4.\tRemove Account\n5.\tBalance Inquiry\n6.\tView Accounts\n");
        printf("Enter Option Choice: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            menu = -1;
            printf("Program Terminated\n");
        }
        else if (choice == 1)
            deposit(aptr);
        else if (choice == 2)
            withdrawl(aptr);
        else if (choice == 3)
            add_account(aptr);
        else if (choice == 4)
            remove_account(aptr);
        else if (choice == 5)
            inquiry(aptr);
        else if (choice == 6)
            display(aptr);
        else
            printf("An invalid choice has been entered.\nRestarting menu.\n");


    }
    return(0);
}

