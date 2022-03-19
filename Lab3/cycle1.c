/************** File: cycle1.c *******************/

#include <stdio.h>
#include <time.h>
#include "cycle.h"
#include "exercise2.h"

int testCyclic(LinkedList l){

	struct Node* head = l.first; 
	struct Node* fast = head;
	struct Node* slow = head;
	int c_flag = -1;
	
	// Empty list
	if(!head)
		return -1;
	
	// Single or two node(s)
	else if(!head->next || !head->next->next)
		return 0;
		
	// Single and Two node(s) circular
	else if(head->next == head || head->next->next  == head)
		return 1;
	
	// At least 3 nodes
	else{
	
		while(1){
			
			fast = fast->next->next;
			slow = slow->next;
			
			// Fast should not encounter null unless list is linear
			if(!fast->next || !fast->next->next){
			
				c_flag = 0;
				break;
				
			}
			
			// Fast and slow meet only if there is cycle
			else if(fast == slow){
			
				c_flag = 1;
				break;
				
			}
			
		}
	}
	
	return c_flag;

}
	


