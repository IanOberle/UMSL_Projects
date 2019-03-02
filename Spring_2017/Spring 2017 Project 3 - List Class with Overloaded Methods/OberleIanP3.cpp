/*Created by: Ian Oberle
Started on: 3/15/17, 6:20PM
Completed on: 3/17/17 8:30PM
Special Edits Completed on: 3/18/17 9:20PM
Submitted on: 3/22/17
Resubmitted on: 3/23/17*/

/*
	Purpose of programs is to create a class that contains a constructor that
		dynamically allocates and initializes a List object array.
	The default value of every List array element is 0. The class also
		contains functions to input new values into the List's list array, 
		print the entire list array, average the elements in 
		the list array, return the number of List arrays created,
		and functions that overload the +,-,=,==,and ++ operators.*/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

class List
{
	private:
		//Stating class private items
		int numItems;
		int * list;
		static int objectCount;

	public:  //Public Member Functions
		List(int num);
		List(List &obj);
		void readList();
		void print();
		double getAverage();
		int getNumItems()
		{
			return numItems;
		};

		/*Member function returns the number of List objects that have 
		  been created*/
		static int getObjectCount()
		{ 
			return objectCount; 
		};
		List operator+(List &obj);
		List operator-(List &obj);
		List operator=(List &obj);
		bool operator==(List &obj);

		/*Member function increments all of the list array elements of a single
		List object by 1.*/
		void operator++()
		{
			for (int i = 0; i < numItems; i++)
				this->list[i] = this->list[i] + 1;
		};

		//Destructor
		~List()
		{
			delete[] list;
		}
};

//"Default" Construtor 
List::List(int num)
{
	const int DEFAULT_VALUE = 0;
	numItems = num;
	int *list = new int[numItems];
	for (int i = 0; i < numItems; i++)
		list[i] = DEFAULT_VALUE;
	this->list = list;
	objectCount++;
};

//Copy Constructor
List::List(List &obj)
{
	numItems = obj.numItems;
	int *list = new int[numItems];
	for (int i = 0;i < numItems;i++)
		 list[i] = obj.list[i] ;
	this->list = list;
	objectCount++;
}

/*Member function allows for an object's list array/pointer to be modified
User can choose to manually modify or have
computer randomly generate new element values*/
void List::readList()
{
	int newLine = 0, choice;
	cout << "\nWould you like to manually enter "
		 << "new values into the List array, or\n"
		 << "would you like to have the computer generate"
		 << " random values for the array?\n*Random values are from 1 to 100*";
	cout << "\n1. Manual Entry\t\t2.Random Entry\n";
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		cout << "Please enter a valid option.";
		cin >> choice;
	}
	if (choice == 1)
	{
		cout << "Please enter new values for the List array."
			<< "*Integer values only*\n";
		for (int i = 0; i < numItems; i++)
		{
			cin >> list[i];
			newLine++;
			if (newLine == 5)
			{
				cout << endl;
			}
		}
	}
	else if (choice == 2)
	{
		unsigned seed = time(0);
		srand(seed);
		for (int i = 0; i < numItems; i++)
		{
			list[i] = (rand() % 100);
		}
		cout << "The List object's list array has been randomly filled"
			<< " numbers from 1 to 100.\n";
	}
};

/*Memeber function allows user to view/print the values of the list array
pointer of a List object*/
void List::print()
{ 
	for (int i = 0; i < numItems; i++)
	{
		cout << setw(3) << list[i] << " ";
	}
	cout << endl;
};

/*Member function takes the elements of the first List object's list
array, sums them, and returns the average value of elements.*/
double List::getAverage()
{
	int sum = 0;
	double average;
	for (int i = 0; i < numItems; i++)
		sum += list[i];
	average = static_cast<double>(sum) / numItems;
	return average;
};

/*Member function overloads the "+" operator.
The user can could to manually enter new values into the secondary list
array used in this function or the user can have the computer allocate
randomly generated values into the secondary list array*/
List List::operator+(List &obj)
{
	List nextObj(numItems);
	cout << "The enter new values for the argument List array.\n";
	obj.readList();
	cout << "\n\nList Array 1\t\t";
	print();
	cout << "\nList Array 2\t\t";
	obj.print();
	cout << endl;
	for (int i = 0; i < numItems; i++)
		nextObj.list[i] = (list[i] + obj.list[i]);
	cout << "The list array of the new List object is (List 1 + List 2)\n"
		 << "List Array 3\t\t";
	return nextObj;
};

/*Member function overloads the "-" operator.
The user can could to manually enter new values into the secondary list
array used in this function or the user can have the computer allocate
randomly generated values into the secondary list array*/
List List::operator-(List &obj)
{
	List nextObj(numItems);
	cout << "The enter new values for the argument List array.\n";
	obj.readList();
	cout << "\n\nList Array 1\t\t";
	print();
	cout << "\nList Array 2\t\t";
	obj.print();
	cout << endl;
	for (int i = 0; i < numItems; i++)
		nextObj.list[i] = list[i] - obj.list[i];
	cout << "The list array of the new List object is (List 1 - List 2)\n"
		 << "List Array 3\t\t";
	return nextObj;
};

/*Member function copies a secondary list array to the
primary list array*/
List List::operator=(List &obj)
{
	List nextObj(numItems);
	for (int i = 0; i < numItems; i++)
	{
		list[i] = obj.list[i];
		nextObj.list[i] = list[i];
	}
	return nextObj;
};

/*Memeber function compares the primary and secondary list arrays if
any of the elements of similar position are different from each
other the function will return a false boolean value. If they are all
the same the fucntion will return a true boolean value.*/
bool List::operator==(List &obj)
{
	bool check;
	obj.readList();
	for (int i = 0; i < numItems; i++)
	{
		if (obj.list[i] == list[i])
			check = true;
		else
			check = false;
	}
	return check;
};

int List::objectCount = 0;

int main()
{
	//Stating necessary basic variables for program/project
	int choice, numItems, again = 0;

	cout << "Please enter the desired array size. *Integers only*\n";
	cin >> numItems;

	//Creating default objects to be used for later
	List obj1(numItems), obj2(numItems), obj3(numItems);
	
	cout << "\nList 1 Array\n";
	obj1.print();

	//Loop to allow user to access/use all possible program functions
	do
	{
		cout << "\n\n\nWhich operation would you like to perform?\n"
			<< "0.\tExit Progam\n"
			<< "1.\tInput New Array Values For First List Object\n"
			<< "2.\tPrint Current Array Values Of The First List Object\n"
			<< "3.\tCreate An Average Of The Elements In "
			<< "First List Object's List Array\n"
			<< "4.\tShow The Number Of List Arrays Created\n"
			<< "5.\tUse Copy Constructor\n6.\tAdd Two List Arrays\n"
			<< "7.\tSubtract Two List Arrays\n"
			<< "8.\tCopy One List Array To Another\n"
			<< "9.\tCompare Two List Arrays\n"
			<< "10.\tIncrement All Elements Of One Array By One\n";
		cin >> choice;

		while (choice > 10 || choice < 0)
		{
			cout << "Please enter a valid number";
			cin >> choice;
		}

		//Exit Program Option
		if (choice == 0)
			again = -1;
		/*Read Function (Specifics of function located at the 
		  top of code, under class)*/
		else if (choice == 1)
			obj1.readList();

		/*Print Function (Specifics of function located at the 
		  top of code, under class)*/
		else if (choice == 2)
		{
			cout << endl;
			cout << "List Array 1.\n";
			obj1.print();
		}

		//Get Average Function 
		//(Specifics of function located at the top of code, under class)
		else if (choice == 3)
		{
			double average;
			average = obj1.getAverage();
			cout << "\nThe average of the List Array 1 is ";
			cout << average << endl;
		}

		//Get Object Count Function
		//(Specifics of function located at the top of code, in class)
		else if (choice == 4)
		{
			int objectCount;
			cout << endl;
			objectCount = obj1.getObjectCount();
			cout << objectCount << " List objects have been created\n";
		}

		//Copy Constructor
		//(Specifics of function located at the top of code, under class)
		else if (choice == 5)
		{
			cout << "This is the Copy Constructor Function\n";
			obj1.readList();
			cout << "\nList Array 1\t";
			obj1.print();
			cout << "Value of numItems: " << obj1.getNumItems() << endl;
			List obj4(obj1);
			cout << "\nList Array 4\t";
			obj4.print();
			cout << "Value of numItems: " << obj4.getNumItems() << endl;
		}

		//"+" Operator Overload Function
		//(Specifics of function located at the top of code, under class)
		else if (choice == 6)
		{
			obj3 = (obj1.operator+(obj2));
			obj3.print();
		}		

		//"-" Operator Overload Function
		//(Specifics of function located at the top of code, under class)
		else if (choice == 7)
		{		
			obj3 = obj1.operator-(obj2);
			obj3.print();
		}

		// Copy Constructor Function
		// (Specifics of function located at the top of code, under class)
		else if (choice == 8)
		{
			cout << "\nList Array 1\n";
			obj1.print();
			cout << endl;
			cout << "List Array 2\n";
			obj2.print();
			obj3 = obj1.operator=(obj2);
			cout << "\nThis shows that the second List has been copied "
				<< "to the first List.\n";
			cout << "List Array 1:\t";
			obj3.print();
		}

		//Comparision Function
		//(Specifics of function located at the top of code, under class)
		/* *Special Note* This function will more than likely 
		    never produce a "true" result, but it is possible. (For if you are 
			using the random number generator) */
		else if (choice == 9)
		{
			bool check, temp;
			List obj2(numItems);
			temp = obj1.operator==(obj2);
			cout << "\nList Array 1" << endl;
			obj1.print();
			cout << "List Array 2" << endl;
			obj2.print();
			check = temp;
			cout << "This is the boolean value returned: " << check <<  endl;
		}

		//Increment by 1 Function
		//(Specifics of function located at the top of code, in class)
		else if (choice == 10)
		{
			cout << "\nList Array 1\n";
			obj1.print();
			cout << endl;
			obj1.operator++();
			cout << "The first List object's list array elements"
				 << " have been incremented by one" << endl;
			obj1.print();
		}

	} while (again != -1);

	cout << "\nHave a nice day.\n";
	return 0;
}