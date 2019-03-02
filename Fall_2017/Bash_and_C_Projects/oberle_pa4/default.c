/*
 * Ian Oberle
 * CS 2750 PA4
 * 11/4/2017
 */

#include "all.h"
#include "object.h"

//File sends 7 accounts to accounts.dat file
//Useful for testing functions

int main()
{
    //Initializes 7 accounts
    Account accounts[7] = {{"Ian", "T", "Oberle", 101101, 45.00},{"Steve", "K", "Thompson", 101102, 15.00}, {"Mark", "S", "Mores", 101103, 48.00},{"Alexis", "M", "Hanover", 101104, 56.00}, {"Nikola", "F", "Tesla", 101105, 855.00},{"Albert", "E" , "Einstien", 101106, 4568.00},{"Katy", "R", "Perry", 101107, 8652.00}};

    int i;

    //Writes account information to accounts.dat file
    fptr = fopen("accounts.dat", "ab");
    for(i = 0; i < 7;i++)
        fwrite(&accounts[i], sizeof(Account), 1, fptr);
    fclose(fptr);
    return(0);
}
