/************ File: cycle.c ************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cycle.h"
#include "exercise2.h"

//int heap_memory_taken = 0;
// Tests if a given linked list is cyclic or linear
/*void testCyclic(struct Node* head){

	printf("True");

}*/

// Creates a linear linked list of size N
LinkedList createList(long int N){

	LinkedList l;
	
	int upper = 10000, lower = 0;
	srand(time(0));
	struct Node* head = (struct Node*)myalloc(sizeof(struct Node));
	
	l.first = head;
	l.count++;
	
	head -> data = ( rand() % (upper - lower + 1)) + lower;
	struct Node* temp = head;

	for(int i = 2; i <= N; i++){
	
		temp -> next = (struct Node*)myalloc(sizeof(struct Node));
		l.count++;
		temp = temp -> next;
		temp -> data = ( rand() % (upper - lower + 1)) + lower;
		
	}
	
	temp -> next = NULL;
	update_file();
	
	return  l;

}

// Gets count of given linked list
/*long int getCount(struct Node* head){

	// If linked list is empty
	if(head == NULL)
		return 0;
	
	// Count this node and rest of list
	else
		return 1 + getCount(head->next);

}*/

// Creates cycle or leaves a linked list to be line based on coin toss
LinkedList createCycle(LinkedList ls){

	srand(time(0));
	int coin_toss = rand() % 2;
	struct Node* head = ls.first;
	// If coin_toss = 1, then list is cyclic
	if(coin_toss){
	
		long int N = ls.count;
		long int r = (rand() % N) + 1;
		
		// Single node
		if(head -> next == NULL)
			return ls;
		
		// At least 2 nodes
		else{
		
			long int traversed = 0;
			struct Node* temp = head;
			struct Node* r_temp = head;
			
			while(temp -> next != NULL){
			
				traversed++;
				
				// Checking if we reached rth node
				if(traversed == r)
					r_temp = temp;
				
				// Else we move to next node
				else
					temp = temp -> next;
			}
			
			// Making last node reach
			temp -> next = r_temp;
		}
	
	}
	
	return ls;

}
	
	
