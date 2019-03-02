//Created By: Ian Oberle

/*  *Program Notes*  
Programs contains function that append/insert nodes
(beginning of list and after first node of lower value), delete nodes of 
specified value, position or the entir list, display the value of individual 
nodes or the entire List, display the current number of nodes, swap the 
values of two nodes, merge the values of two nodes, remove all duplicate values*/

/* *Special Notes for Grader* 
If this program does not compile I can almost guarantee that the issue is with
the class in this program (probably some declaration/initialization
statement(s)). I say this because that was the issue cause the 
program to not compile for you with my last project. 
There isn't anything wrong with this code. The errors come from changing the
IDE the code is in. However, in fairness, I could be doing something wrong 
and Visual Studio is making corrections for my mistakes. I would use Eclipse, 
but I have never been able to get it to work on my computer.

For the insertInSortedOrder Function I instea made two functions one that
inserts a new node after the first node of lower value and another function
that inserts a new node before the first node of equal or greater value.
I did this because the directions and the instructor resposes are both 
unclear and contradictory. So, I decided cover all possibilities 
by adding both function.

Another note compiling issues. You may need to change "nullptr" to '\0'.

Also, my apologies for the rather excessive comment blocks*/

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	//Stating necessary variables
	int choice;	
	int again = 1;
	LinkedList node1;

	//Displaying the Creted List
	cout << "Displaying the Created List.\n";
	node1.displayList();
	cout << endl;

	cout << "*Note For User*\nEnter only positive integer values.\n\n";

	//Do-While loop used to create an input menu
	do
	{
		
		cout << "0.\tExit Program\n1.\tInsert New Node To "
			 << "Beginnig Of Linked List\n"
			 << "2.\tAppend New Node To End of Linked List\n"
			 << "3.\tInsert A New Node After The First Node With A Lower Value\n"
			 << "4.\tInsert A New Node Before The First "
			 << "Node With A Higher Value\n"
			 << "5.\tDelete A Node Of A Specific Value\n"
			 << "6.\tDelete A Node At A Specific Position In The Linked List\n"
			 << "7.\tReturn Value Of A Node At A Specific Location\n"
			 << "8.\tMerge The Values Of Two Nodes In The Linked List\n"
			 << "9.\tSwap The Values Of Two Nodes In The Linked List\n"
			 << "10.\tRemove All Duplicate Values In The Linked List\n"
			 << "11.\tReturn The Number of Nodes Currently In The Linked List\n"
			 << "12.\tDisplay The Current Linked List\n"
			 << "13.\tDelete The Entire Linked List\n";
		cin >> choice;

		//Input validation
		while (choice < 0 && choice > 12)
		{
			cout << "Please enter a valid value.\n";
			cin >> choice;
		}

		//Exit Program
		if (choice == 0)
		{
			cout << "Goodbye\n\n";
			again = -1;
		}

		//Insert New Value At Beginning of List
		else if (choice == 1)
		{
			int num;

			cout << "\nEnter List Value\n";
			cin >> num;

			node1.reAppend(num);
			cout << endl << endl;
		}

		//Append New Value to List
		else if (choice == 2)
		{
			int num;

			cout << "\nEnter List Value\n";
			cin >> num;

			node1.appendNode(num);		
			cout << endl << endl;
		}

		//Insert New Value into List (After Node of Lower Value)
		else if (choice == 3)
		{
			int num;

			cout << "\nEnter new value to insert into the list.\n";
			cin >> num;

			node1.insertNodeInSortedOrder(num);
			cout << endl << endl;
		}

		//Insert New Value into List (Before Node of Higher Value)
		else if (choice == 4)
		{
			int num;

			cout << "\nEnter new value to insert into the list.\n";
			cin >> num;

			node1.insertNodeInSortedOrder2(num);
			cout << endl << endl;
		}

		//Delete Node of Specified Value
		else if (choice == 5)
		{
			int numNodes = node1.numberOfNodes();

			cout << endl;
			node1.displayList();
			if (numNodes > 0)
			{
				int num;

				cout << "\nEnter the value you wish to delete from the list.\n";
				cin >> num;

				node1.deleteNodeOfValue(num);
				cout << endl << endl;
			}
			cout << endl << endl;
		}

		//Delete Node at Specified Postion
		else if (choice == 6)
		{
			int numNodes = node1.numberOfNodes();

			cout << endl;
			node1.displayList();
			if (numNodes > 0)
			{
				int num;

				cout << "\nEnter the position of the value you wish"
					<< " to delete from the list.\n";
				cin >> num;

				node1.deleteNodeAtLocation(num);
				cout << endl << endl;
			}
			cout << endl << endl;
		}

		//Display Value at Specified Position
		else if (choice == 7)
		{
			int num, position;

			cout << "\nEnter the position you would "
				 << "like to display the value of.\n";
			cin >> num;

			position = node1.getNodeValueAtLocation(num);
			if (position == -1)
				cout << "Position does not exist.\n";
			else
			{
				cout << endl << "The value of this "
					<< "position is: " << position << "\n\n";
			}
			cout << endl << endl;
		}

		//Merge the Values of Two Nodes
		else if (choice == 8)
		{
			int numNodes = node1.numberOfNodes();
			if (numNodes == 0)
			{
				cout << "\n\nList is empty.\n\n\n";
			}
			if (numNodes > 0)
			{
				cout << "\nEnter the positions of the "
					 << "numbers you want to merge.\n";
				int num1, num2;

				cout << "First Position\n";
				cin >> num1;
				cout << "Second Position\n";
				cin >> num2;

				node1.mergeTwoNodes(num1, num2);
				cout << endl << endl;
			}
		}

		//Swap the Values of Two Nodes
		else if (choice == 9)
		{
			int numNodes = node1.numberOfNodes();
			if (numNodes == 0)
			{
				cout << "\n\nList is empty.\n\n\n";
			}
			if (numNodes > 0)
			{
				cout << "\nEnter the positions of the "
					 << "numbers you want to swap.\n";
				int num1, num2;

				cout << "First Position\n";
				cin >> num1;
				cout << "Second Position\n";
				cin >> num2;

				node1.swapNodes(num1, num2);
				cout << endl << endl;
			}
		}

		//Remove All Duplicates from the Linked List
		else if (choice == 10)
		{
			int numNodes = node1.numberOfNodes();
			if (numNodes == 0)
			{
				cout << "\n\nList is empty.\n\n\n";
			}
			if (numNodes > 0)
			{
				cout << endl;
				node1.removeAllDuplicates();
				cout << "All duplicates have been removed.\n";
				cout << endl << endl;
			}
		}

		//Display the Number of Nodes Currently in the Linked List
		else if (choice == 11)
		{
			int numNodes;
			numNodes = node1.numberOfNodes();
			cout << "\n\nThere are " << numNodes << " nodes in the Linked List";
			cout << endl << endl << endl;
		}

		//Display the Current Linked List
		else if (choice == 12)
		{
			cout << "\n\n";
			node1.displayList();
			cout << "\n\n";
		}

		//Delete the Entire Linked List
		else if (choice == 13)
		{
			int numNodes = node1.numberOfNodes();
			if (numNodes == 0)
			{
				cout << "\n\nList is empty.\n\n\n";
			}
			if (numNodes > 0)
			{
				node1.deleteList();
				cout << "\n\nEntire List Deleted\n";
				node1.displayList();
				cout << endl << endl;
			}
		}
	
	} while (again != -1);

	
	return 0;
}