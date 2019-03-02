#include <iostream>
#include "LinkedList.h"

using namespace std;

//Constructor
LinkedList::LinkedList()
{
	listNode * head = nullptr;

};

//Function inserts a new node at the beginning of the list
void LinkedList::reAppend(int num)
{
	listNode * newNode;
	listNode * nodePtr;

	newNode = new listNode;
	newNode->value = num;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else
	{
		nodePtr = new listNode;
		nodePtr->value = num;
		nodePtr->next = head;
		head = nodePtr;
	}
	cout << "\nThe list now is:\n";
	displayList();
};

//Function appends a new node to the list
void LinkedList::appendNode(int num)
{
	listNode * newNode;
	listNode * nodePtr;

	newNode = new listNode;
	newNode->value = num;
	newNode->next = nullptr;
	
	if (!head)
		head = newNode;

	else
	{
		nodePtr = head;
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
	}
	cout << "\nThe list now is:\n";
	displayList();
};

//Function inserts a new node immediately after the first node with lower value
//*If first original node has higher value than new node the new node becomes the
// new first node*
void LinkedList::insertNodeInSortedOrder(int num)
{
	listNode * newNode;
	listNode * nodePtr;
	listNode * previousNode;
	int next;

	newNode = new listNode;
	newNode->value = num;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;
		previousNode = nullptr;
		next = 0;
		while (nodePtr != nullptr && nodePtr->value < num && next < 1)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			if (nodePtr->value < num)
				next++;
		}
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
	cout << "\nThe list now is:\n";
	displayList();
};

//Function inserts a new node before the first node of higher value
void LinkedList::insertNodeInSortedOrder2(int num)
{
	listNode * newNode;
	listNode * nodePtr;
	listNode * previousNode;
	int next;

	newNode = new listNode;
	newNode->value = num;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;
		previousNode = nullptr;
		next = 0;
		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
	cout << "\nThe list now is:\n";
	displayList();
};

//Function deletes the first occurance of a node with user-specified value
void LinkedList::deleteNodeOfValue(int num)
{
	listNode * nodePtr;
	listNode * previousNode = nullptr;
	
	
	if (!head)
	{
		cout << "List is empty.\n";
		return;
	}
	if (head->value == num)
	{
		cout << "Deleting head value.\n";
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		displayList();
	}
	else
	{
		nodePtr = head;
		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
		displayList();
	}
};

//Function deletes the node a the user-specified position
void LinkedList::deleteNodeAtLocation(int num)
{
	listNode * nodePtr = head;
	listNode * previousNode = nullptr;
	int listCounter = 0;

	if (!head)
	{
		cout << "\nThe list is emtpy.\n";
		return;
	}
	
	if (num == 1)
	{
		head = nodePtr->next;
		delete nodePtr;
		cout << "The list now is:\n";
		displayList();
		return;
	}
	while (nodePtr->next != nullptr && listCounter != num-1)
	{
		
		listCounter++;
		previousNode = nodePtr;
		nodePtr = nodePtr->next;
	}
	if (num-1 > listCounter)
	{
		cout << "Position does not exist.\n";
		return;
	}
	if (nodePtr)
	{
		previousNode->next = nodePtr->next;
		delete nodePtr;
	}
	cout << "\nThe list now is:\n";
	displayList();
};

//Function returns the value of a node at a user-specified position
int LinkedList::getNodeValueAtLocation(int num)
{
	listNode * nodePtr;
	nodePtr = head;
	int listCounter = 0;

	while (nodePtr != nullptr)
	{
		listCounter++;
		if (listCounter == num)
			return nodePtr->value;
		nodePtr = nodePtr->next;
	}
	if (nodePtr == nullptr)
	{
		return -1;
	}
};

//Function sums the values of two nodes, inserts the value into the first node
// and deletes the second node
void LinkedList::mergeTwoNodes(int num1, int num2)
{
	listNode * primaryNode = head;
	listNode * secondaryNode = head;
	listNode * previousNode1 = nullptr;
	listNode * previousNode2 = nullptr;
	int listCounter1 = 1, listCounter2 = 1, mergeValue;

	while (primaryNode != nullptr && listCounter1 != num1)
	{
		previousNode1 = primaryNode;
		if (listCounter1 == num1)
			primaryNode = primaryNode->next;
		if (listCounter1 != num1)
			primaryNode = primaryNode->next;
		listCounter1++;
	}
	while (secondaryNode != nullptr && listCounter2 != num2)
	{
		
		previousNode2 = secondaryNode;
		if (listCounter2 == num2)
			secondaryNode = secondaryNode->next;
		if (listCounter2 != num2)
			secondaryNode = secondaryNode->next;
		listCounter2++;
	}
	if ((primaryNode == nullptr || num1 == 0) &&
		(secondaryNode == nullptr || num2 == 0))
	{
		cout << "Both positions entered do not exist.\n";
		return;
	}
	else if (primaryNode == nullptr || num1 == 0)
	{
		cout << "The first position entered does not exist.\n";
		return;
	}
	else if (secondaryNode == nullptr || num2 == 0)
	{
		cout << "The second position entered does not exist.\n";
		return;
	}
	else if (primaryNode != nullptr && secondaryNode != nullptr)
	{
		mergeValue = primaryNode->value + secondaryNode->value;
			if (num2 == 1)
			{
				primaryNode->value = mergeValue;
				head = secondaryNode->next;
				delete secondaryNode;
			}
			if (num2 > 1)
			{
				primaryNode->value = mergeValue;
				previousNode2->next = secondaryNode->next;
				delete secondaryNode;
			}	
		cout << "\nValues have merged into the first position";
		cout << "\nThe list now is:\n";
		displayList();
	}
};

//Function swaps the values of two nodes at user-specified positions
void LinkedList::swapNodes(int num1, int num2)
{
	listNode * primaryNode;
	listNode * secondaryNode;
	int tempNode;
	int listCounter1 = 0, listCounter2 = 0;

	primaryNode = head;
	secondaryNode = head;
	while (primaryNode != nullptr && listCounter1 != num1)
	{
		listCounter1++;
		if(listCounter1 != num1)
			primaryNode = primaryNode->next;
	}
	while (secondaryNode != nullptr && listCounter2 != num2)
	{
		listCounter2++;
		if (listCounter2 != num2)
			secondaryNode = secondaryNode->next;
	}
	if ((primaryNode == nullptr || num1 == 0) && 
		(secondaryNode == nullptr || num2 == 0))
	{
		cout << "Both positions entered do not exist.\n";
		return;
	}
	else if (primaryNode == nullptr || num1 ==0)
	{
		cout << "The first position entered does not exist.\n";
		return;
	}
	else if (secondaryNode == nullptr || num2 == 0)
	{
		cout << "The second position entered does not exist.\n";
		return;
	}
	else if (primaryNode != nullptr && secondaryNode != nullptr)
	{
		tempNode = primaryNode->value;
		primaryNode->value = secondaryNode->value;
		secondaryNode->value = tempNode;
	}
	cout << "\nValues have been swapped";
	cout << "\nThe list now is:\n";
	displayList();
};

//Function deletes all nodes with duplicate values
//After this function runs the list will contain only singular values
void LinkedList::removeAllDuplicates()
{
	listNode * nodePtr, *nodePtr2, *temp;
	nodePtr = head;
	while (nodePtr != nullptr && nodePtr->next != nullptr)
	{
		nodePtr2 = nodePtr;
		while (nodePtr2->next != nullptr)
		{
			if (nodePtr->value == nodePtr2->next->value)
			{
				temp = nodePtr2->next;
				nodePtr2->next = nodePtr2->next->next;
				delete temp;
			}
			else
				nodePtr2 = nodePtr2->next;
		}
		nodePtr = nodePtr->next;
	}
	displayList();

};

//Function returns the current number of nodes in the list
int LinkedList::numberOfNodes()
{
	listNode * nodePtr;
	int listCounter = 1;
	nodePtr = head;
	if (nodePtr == nullptr)
	{
		listCounter = 0;
		return listCounter;
	}
	while (nodePtr->next != nullptr)
	{
		listCounter++;
		nodePtr = nodePtr->next;
	}
	
	return listCounter;
};

//Function displays the current linked list
void LinkedList::displayList() const
{
	listNode * nodePtr;

	nodePtr = head;
	int listCounter = 0;
	while (nodePtr != nullptr)
	{
		listCounter++;
		cout << "Position: " << listCounter << "\t";
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
	if (head == nullptr)
		cout << "List is empty.\n";
};

//Function deletes the entire Linked List
//Can also be considered the Destructor for the class
void LinkedList::deleteList()
{
	listNode * nodePtr;
	listNode * nextNode;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	head = nullptr;
};