//Created By: Ian Oberle

/*  *Program Notes*  
Programs contains function that append/insert nodes
(beginning of list and after first node of lower value), delete nodes of 
specified value, position or the entir list, display the value of individual 
nodes or the entire List, display the current number of nodes, swap the 
values of two nodes, merge the values of two nodes, remove all duplicate values
*/


#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	//Stating necessary variables
	int choice;	
	int again = 1;
	LinkedList node1;

	//Displaying the Created List
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
		while (choice < 0 || choice > 13)
		{
			cout << "\nPlease enter a valid value.\n";
			cin >> choice;
		}
		system("CLS");
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

			cout << "Enter List Value\n";
			cin >> num;

			node1.reAppend(num);
			cout << endl << endl;
		}

		//Append New Value to List
		else if (choice == 2)
		{
			int num;

			cout << "Enter List Value\n";
			cin >> num;

			node1.appendNode(num);		
			cout << endl << endl;
		}

		//Insert New Value into List (After Node of Lower Value)
		else if (choice == 3)
		{
			int num;

			cout << "Enter new value to insert into the list.\n";
			cin >> num;

			node1.insertNodeInSortedOrder(num);
			cout << endl << endl;
		}

		//Insert New Value into List (Before Node of Higher Value)
		else if (choice == 4)
		{
			int num;

			cout << "Enter new value to insert into the list.\n";
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

				cout << "Enter the value you wish to delete from the list.\n";
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

				cout << "Enter the position of the value you wish"
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

			cout << "Enter the position you would "
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
				cout << "List is empty.";
			}
			if (numNodes > 0)
			{
				cout << "Enter the positions of the "
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
				cout << "List is empty.";
			}
			if (numNodes > 0)
			{
				cout << "Enter the positions of the "
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
				cout << "List is empty.";
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
			cout << "There are " << numNodes << " nodes in the Linked List";
			cout << endl << endl << endl;
		}

		//Display the Current Linked List
		else if (choice == 12)
		{
			node1.displayList();
			cout << "\n\n";
		}

		//Delete the Entire Linked List
		else if (choice == 13)
		{
			int numNodes = node1.numberOfNodes();
			if (numNodes == 0)
			{
				cout << "List is empty.";
			}
			if (numNodes > 0)
			{
				node1.deleteList();
				cout << "\n\nEntire List Deleted\n";
				node1.displayList();
				cout << endl << endl;
			}
		}
		system("pause");
		system("CLS");
	} while (again != -1);

	return 0;
}