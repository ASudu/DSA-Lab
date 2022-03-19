/*********** File: que.c ***********/

#include <stdio.h>
#include <stdlib.h>
#include "que.h"

// returns an empty Queue
struct Queue* newQ(){
	
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = NULL;
	q->rear = NULL;
	
	return q;
	
}

// tests whether q is empty
Boolean isEmptyQ(struct Queue* q){
	
	if(q == NULL){
	
		return T1;
		
	}
	
	else if(q->front == NULL){
	
		return T2;
		
	}
		
	return F;

}

// deletes the element from the front of the Queue; returns the modified Queue
struct Queue* delQ(struct Queue* q){
	
	struct Queue* temp = malloc(sizeof(struct Queue));
	
	// If queue is empty
	if(isEmptyQ(q) == T2){
		
		return q;
	}
	
	// If single node is there
	else if((isEmptyQ(q) == F) && (q->front == q->rear)){
		
		q->front = q-> rear = NULL;
		return q;
		
	}
	// At least 2 nodes are there in the list
	else{
		
	// The new front will be the 
	temp->front = q->front->next;
	temp->rear = q->rear;
	
	}
	
	return temp;

}

// returns the element from the front of the Queue
int front(struct Queue* q){
	
	return q->front->element;

}

// adds e to the rear of the Queue; returns the modified Queue
struct Queue* addQ(struct Queue* q , int e){
	
	struct Queue* q1 = q;
	struct QNode* temp = malloc(sizeof(struct QNode));
	temp->element = e;
	temp->next = NULL;
	
	// If the queue is empty
	if(isEmptyQ(q1) == T2){
		
		q1->front = q1->rear = temp;
		
	}
	
	// At least one node in queue
	else if(isEmptyQ(q1) == F){
		
		q1->rear->next = temp;
		q1->rear = temp;
		
	}
	
	return q1;

}

// returns the length of the Queue
int lengthQ(struct Queue* q){
	
	//If queue is empty
	if(isEmptyQ(q) == T2){
		
		return 0;
	}
	
	// If single node is there
	else if((isEmptyQ(q) == F) && (q->front == q->rear)){
		
		return 1;
		
	}
	
	// At least 2 nodes
	else if(isEmptyQ(q) == F){
		
		int length = 1; // Initialized to 1 as the while loop runs only till the node before the last
		struct QNode* t = q->front;
		
		while(!t->next){
			
			length++;
			t = t->next;
			
		}
		
		return length;
		
	}
	
}
