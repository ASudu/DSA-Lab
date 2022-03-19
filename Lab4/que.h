/*********** File: que.h ***********/

#include <stdio.h>

// Declaration of enum
typedef enum { F, T1, T2 } Boolean;

struct QNode{
	
	int element;
	struct QNode* next;
	
};

struct Queue{
	
	struct QNode* front;
	struct QNode* rear;
	
};


struct Queue* newQ(); // returns an empty Queue
Boolean isEmptyQ(struct Queue* q); // tests whether q is empty
struct Queue* delQ(struct Queue* q); // deletes the element from the front of the Queue; returns the modified Queue
int front(struct Queue* q); // returns the element from the front of the Queue;
struct Queue* addQ(struct Queue* q , int e); // adds e to the rear of the Queue; returns the modified Queue
int lengthQ(struct Queue* q); // returns the length of the Queue
