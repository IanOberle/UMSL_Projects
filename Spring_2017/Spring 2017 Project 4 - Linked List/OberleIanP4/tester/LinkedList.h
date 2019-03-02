#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Class Declation and Function Prototypes
class LinkedList
{
	private:
		struct listNode
		{
			listNode * next;
			int value;
		};

		listNode * head;
	public:
		LinkedList();
		void reAppend(int);
		void appendNode(int);
		void insertNodeInSortedOrder(int);
		void insertNodeInSortedOrder2(int);
		void deleteNodeOfValue(int);
		void deleteNodeAtLocation(int);
		int getNodeValueAtLocation(int);
		void mergeTwoNodes(int a, int b);
		void swapNodes(int a, int b);
		void removeAllDuplicates();
		int numberOfNodes();
		void displayList() const;
		void deleteList();
};
#endif


