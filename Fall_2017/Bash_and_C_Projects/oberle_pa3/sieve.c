//Ian Oberle
//cs2750 PA 3
//date 10/20/17

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Defining constant value
#define size 1000

int main()
{
	//Initializing array and variables
        int arr [size];
	int i,k,j;
        
        //Fills array with values
	for (  i = 0; i < size; i++)
	{
		arr[i] = i;
	}

        //Searches for prime numbers and changes non primes to 0.
	for ( k = 2; k <= sqrt(size); k++)
	{
		if ( arr[k] != 0)
		{
			for ( j = (k * 2); j < size; j += k)
			{
				arr[j] = 0;
			}
		}
	}
       //Displays prime numbers
       for ( k = 0; k < size; k++) 
       {
           if ( arr[k] != 0)
               printf ("%d\n",arr[k]);
       }
}
