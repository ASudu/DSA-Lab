/**************** File: cycle.h ****************/

struct Node{

	int data;
	struct Node *next;
};

typedef struct LinkedList{

	long int count;
	struct Node* first;

}LinkedList;

// Function to test if the linked list has a cycle
int testCyclic(LinkedList l);

// Function to crete list with N random numbers 
LinkedList createList(long N);

// Function to make linked list cyclic or linear depending on coin toss
LinkedList createCycle(LinkedList l);
