//Ian Oberle
//cs2750 PA 3
//date 10/20/17

#include <stdio.h>
#include <stdlib.h>

//Header Files
#include "avg.h"
#include "sum.h"
#include "max.h"
#include "min.h"

//Defining constant value
#define N 10

int main()
{
     //Initializing variables
    int i;
    float a[N];

    srand(123);

    //Fills array with random values
    for ( i = 0; i < N; i++)
    {	
    	a[i] = ((double) rand())/ RAND_MAX;
    	printf ("%.2f ", a[i]);
    }

    //Displays average, sum, max, and min of set of numbers
    printf ("\n\n");
    printf ("average: %.2f\n", avg(a,N));
    printf ("sum:     %.2f\n", sum(a,N));
    printf ("maximum: %.2f\n", max(a,N));
    printf ("minimum: %.2f\n", min(a,N));
    return 0;
}
