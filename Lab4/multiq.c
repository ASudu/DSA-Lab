/*********** File: multiq.c ***********/

#include <stdio.h>
#include <stdlib.h>
#include "multiq.h"

// creates a list of num Queues, each of which is empty
struct MultiQ* createMQ(int num){

	struct MultiQ* mq = malloc(sizeof(struct MultiQ));
	mq->priorities = malloc(num * sizeof(struct Queue));
	mq->size = num;
	
	return mq;
	
}

// tests whether all the Queues in mq are empty
Boolean isEmptyMQ(struct MultiQ* mq){

	if(mq == NULL)
		return T1;
	else{
	int hp = mq->size;
	while(hp > 0){
	
		if(isEmptyQ(mq->priorities[hp - 1]) == T2 || isEmptyQ(mq->priorities[hp - 1]) == T1)
			hp-=1;
		
		else if(isEmptyQ(mq->priorities[hp - 1]) == F)
			return F;
	}
	
	return T2; // return T if all queues are empty
	}
}

// adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
struct MultiQ* addMQ(struct MultiQ* mq, struct Task t){

	mq->priorities[t.pr - 1] = addQ(mq->priorities[t.pr - 1], t.TaskID);
	
	return mq;
	
}

// returns the front of the non-empty Queue in mq with the highest priority.
struct Task nextMQ(struct MultiQ* mq){

	struct Task t;
	if(isEmptyMQ(mq) != T1){
		int hp = mq->size;
		
		while(hp > 0){
		
			if(isEmptyQ(mq->priorities[hp - 1]) == T2 || isEmptyQ(mq->priorities[hp - 1]) == T1)
				hp--;
			
			else if(isEmptyQ(mq->priorities[hp - 1]) == F){
			
				t.TaskID = mq->priorities[hp - 1]->front->element;
				t.pr = hp;
			
			}
		}
	}
	
	return t;
	
}

// deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ	
struct MultiQ* delNextMQ(struct MultiQ* mq){

	int hp = mq->size;
	while(hp > 0){
	
		if(isEmptyQ(mq->priorities[hp - 1]) == T2 || isEmptyQ(mq->priorities[hp - 1]) == T1)
			hp--;
		
		else if(isEmptyQ(mq->priorities[hp - 1]) == F){
		
			mq->priorities[hp - 1] = delQ(mq->priorities[hp - 1]);
		
		}
	}
	
	return mq;
	
}

// returns the total number of items in the MultiQ
int sizeMQ(struct MultiQ* mq){

	int total = 0;
	int  hp = mq->size;
	
	do{
	
			total += lengthQ(*(mq->priorities + hp - 1));
			hp--;
			
	}while(hp > 0);
	
	return total;
	
}

// returns the number of items in mq with the priority p
int sizeMQbyPriority(struct MultiQ* mq, int p){
	
	return lengthQ(mq->priorities[p - 1]);

}

// returns the Queue with priority p
struct Queue* getQueueFromMQ(struct MultiQ* mq, int p){

	return mq->priorities[p - 1];
	
}
