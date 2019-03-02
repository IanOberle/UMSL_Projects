/*Created by: Ian Oberle
Started on: 2/10/17
Finished on:2/12/17
Final Edits Completed On: 2/16/17
Submitted on:2/17/17*/


//Parts of Program
//1. *Create an array and find the most frequent number(s).
/*2. *Create an array, find the two largest numbers, and return their
	 values and positions.
	 *This part of the project is completed in a do/while loop.*/
 /*3. *Create a "new" array using half the of the original array.
	  *Terms in the "new" array are the sum of the pairing
	  of every two elements from the original array.
	  *The function used returns a pointer to the "new" array.
	  *This function uses pointer notation instead of subscripts
	  when working with arrays.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function Protypes
void frequent(int[], int);
void read_array(int[], int, int, int);
void print_array(int[], int);
void two_largest(int[], int, int*, int*, int*, int*);
int* newArray(int[], int);

int main()
{
	unsigned seed = time(0);
	srand(seed);
	//Part 1
	cout << "Part 1 of 3\n";

	//Initializing the base array used for the project
	const int ARRAY_SIZE = 100;
	int arrayRand[ARRAY_SIZE], max, min;

	//Asking user for the max and min values for the new array
	/*Values could have been written into the program code, but
	I prefer this method of entry, it's not as lazy.*/
	cout << "Enter the max and min values for this array.\n"
		<< "*Use integer values only*\n";
	cout << "Max Value\n";
	cin >> max;
	cout << "Min Value\n";
	cin >> min;
	cout << endl;

	read_array(arrayRand, ARRAY_SIZE, min, max);
	print_array(arrayRand, ARRAY_SIZE);
	frequent(arrayRand, ARRAY_SIZE);

	//Part 2
	cout << "Part 2 of 3\n";

	//Initializing variables for Part 2
	int again;
	int numptr1,
		numptr2,
		addressptr1,
		addressptr2;
	/*!!!Note!!!
	Very rarely, the pointers in the Part 2 do not initialize
	correctly and causes the program to fail. Just re-run the program
	and it should resolved the issue.*/

	//Asking user for the max and min values for the new array
	cout << "Enter Max and Min Values for array.\n"
		<< "*Use integer values only*\n";
	cout << "Max Value\n";
	cin >> max;
	cout << "Min value\n";
	cin >> min;
	cout << endl;

	do
	{
		read_array(arrayRand, ARRAY_SIZE, min, max);
		print_array(arrayRand, ARRAY_SIZE);
		two_largest(arrayRand, ARRAY_SIZE, &numptr1, &numptr2, &addressptr1, &addressptr2);

		//States the two largest elements and their positions (Condition 1)
		cout << endl;
		if (numptr1 != numptr2)
		{
			cout << "The largest element in the array is " << numptr1 <<
				" at postion " << addressptr1 + 1 << endl;
			cout << "The second largest element in the array is " << numptr2 <<
				" at postion " << addressptr2 + 1 << endl;
		}

		//States the two largest elements and their positions (Condition 2)
		if (numptr1 == numptr2)
		{
			cout << "The largest element in the array is " << numptr1
				<< " at positions " << addressptr1 + 1 << " and " << addressptr2 + 1 << "\n";
		}
		cout << endl;
		print_array(arrayRand, ARRAY_SIZE);
		cout << "This shows the array has not been modified.\n\n";
		cout << "Would you like to repeat this process?\n"
			<< "If so, enter any integer value that is not -1. If not, enter -1.\n";

		cin >> again;
	} while (again != -1);

	//Part 3
	cout << "\nPart 3 of 3\n";



	//Stating variables for Part 3 of the project;
	const int SIZE = 100;
	int *holder, compensate, arrayRand1[SIZE];
	

	cout << "Enter the max and min values for this array.\n"
		<< "*Use integer values only*\n";
	cout << "Max Value\n";
	cin >> max;
	cout << "Min Value\n";
	cin >> min;
	cout << "\n\nOriginal Array\n";


	read_array(arrayRand1, SIZE, min, max);  //Creates new array				  
	print_array(arrayRand1, SIZE); //Prints new array
	
	holder = newArray(arrayRand1, SIZE); 
	//Initialinzing variable to hold new array
	if ((SIZE / 2) % 2 == 1)
		compensate = ((SIZE / 2) + 1);
	else
		compensate = (SIZE / 2);

	cout << "New Array\n";
	for (int index = 0; index < compensate; index++) 
	
	//This section displays both the new and original arrays
	{
		cout << holder[index] << " ";
		if ((index + 1) % 10 == 0)
			cout << endl;

	}
	cout << endl;
	cout << "Reprint of Original Array\n";
	print_array(arrayRand1, SIZE);
	delete holder;
	return 0;
}

//Function Headers

//Function find the most frequent element(s)
//Function takes in an array and its size
void frequent(int randArray[], int SIZE)
{
	int index, value, count = 0, mostFrequent;
	const int size1 = 100;
	int frequency[size1];

	//For loop creates a frequency array
	for (value = 0; value < SIZE; value++)  
	{
		for (index = value; index < SIZE; index++)
		{
			if (randArray[value] == randArray[index])
				count++;
		}
		frequency[value] = count;
		count = 0;
	}

	//This for loop is not necessary.
	//I wanted to show proof my function is working properly.
	for (index = 0; index < SIZE; index++) 

	{
		cout << frequency[index] << "  ";
		if ((index + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;
	mostFrequent = frequency[0];
	for (index = 0; index < size1; index++)
	{
		if (frequency[index] > mostFrequent)
		{
			mostFrequent = frequency[index];
		}
	}

	/*Finds elements with the highest frequency and displays their
	  frequency and position in the array, not their index*/

	for (index = 0; index < size1; index++) 
	{
		if (frequency[index] == mostFrequent)
			cout << randArray[index] << "\tMost Frequent Element\tFrequency of "
			<< frequency[index] << " at position " << index + 1 << "\n\n";
		/*Additional Note: This only displays the position of the
		  first occurance of the most frequent element(s) [Could have multiple
		  elements with the same frequency]*/
	}
}

//Function enters random values into an array
/*Function takes in an array, its size,
and the max and min values for element in the array */
void read_array(int randArray[], int SIZE, int min_range, int max_range)
{
	int index = 0;
	for (index; index < SIZE; index++)
		randArray[index] = ((rand() % (max_range - min_range)) + min_range);
}

//Function prints array/ Creates rows of 10 values
//Function takes in an array and its size
void print_array(int randArray[], int SIZE)
{
	for (int position = 0; position < SIZE; position++)
	{
		cout << randArray[position] << " ";
		if ((position + 1) % 10 == 0)
			cout << endl;
	}
	cout << "\n";
}

//Function find the two largest elements in the array
//Function takes in an array, its size and several pointers
void two_largest(int randArray[], int SIZE, int *numptr_1, int *numptr_2, int *addressptr_1, int *addressptr_2)
{
	int largest = randArray[0], largest2 = randArray[0];
	int numPtr1, numPtr2, addressPtr1, addressPtr2;

	for (int index = 0; index < SIZE; index++)
	{
		if (randArray[index] > largest)
		{
			largest = randArray[index];
			numPtr1 = largest;
			addressPtr1 = index;
		}
	}

	for (int index = 0; index < SIZE; index++)
	{
		if (index != addressPtr1 && randArray[index] > largest2)
		{
			largest2 = randArray[index];
			numPtr2 = largest2;
			addressPtr2 = index;
		}
	}
	*numptr_1 = numPtr1;
	*numptr_2 = numPtr2;
	*addressptr_1 = addressPtr1;
	*addressptr_2 = addressPtr2;
}

//Function creates a new array using dynamically allocated memory
//Function takes in an array and its size
int* newArray(int randArray[], int SIZE)
{
	int size2 = (SIZE / 2), index = 0;

	if (SIZE % 2 == 1)
		size2 = ((SIZE / 2) + 1);
	
	int *arrayptr = new int[size2];

	if ((SIZE % 2) == 0)
	{
		for (index; index < size2; index++)
		{
			*(arrayptr + index) = (*(randArray + (2 * index)) + *(randArray + ((2 * index) + 1)));

		}
	}
	
	/*This part is not really necessary since the function takes
	an array with an even size. However, it can handle arrays 
	with odd size, if you manually change the value	within
	the program code. */
	else if ((SIZE % 2) == 1)
	{
		for (index; index < size2; index++)
		{
			*(arrayptr + index) = (*(randArray + (2 * index)) + *(randArray + ((2 * index) + 1)));

		}
		(*(arrayptr + (size2 - 1))) = *(randArray + (SIZE - 1));

	}
	
	return  arrayptr;
}