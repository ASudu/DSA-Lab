/*********** File: testMultiQ.c ***********/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "multiq.h"

//reads from f a list of pairs (task_id, priority) and adds each item to a MultiQ appropriately
struct MultiQ* loadData(FILE* f){

	struct MultiQ* mq = createMQ(10);
		
	if(!f){
	
		printf("File doesn't exist\n");
		
	}
	
	else{
		
		while(!feof(f)){
		
			int taskid=0, p =0;
			struct Task t;
			fscanf(f,"%d,%d\n",&taskid,&p);
			t.TaskID = taskid;
			t.pr = p;
			mq = addMQ(mq,t);
			
			//printf("hello\n");
			
		}
	}
	
	fclose(f);
	
	return mq;
	
}

//performs num of delNextMQ operations
struct MultiQ* testDel(struct MultiQ* mq,int num){

	
	
	while(num > 0){
	
		mq = delNextMQ(mq);
		num--;
		
	}
	
	return mq;
	
}

int main(){

	FILE* f = fopen("input10.txt", "r");
	
	int inp = 10;
	clock_t time1,time2;
	double time_elapse1, time_elapse2;
	FILE *fptr = fopen("Multiqueue.txt","a");
	
	// calculation for load data
	time1 = clock();	
	struct MultiQ* mq = loadData(f);
	time2 = clock();
	time_elapse1 = ((double)(time2-time1))/CLOCKS_PER_SEC;
	
	// random number generation to delete num values
	srand(time(0));
	int num = (rand() % (inp + 1)) + 1;
	
	// calculation for delete fn
	time1 = clock();	
	mq = testDel(mq,num);
	time2 = clock();
	time_elapse2 = ((double)(time2-time1))/CLOCKS_PER_SEC;
	
	if(!fptr)
		printf("File access error!\n");
	
	else{
	
		fprintf(fptr,"%d,%lf,%lf,%d\n",inp,time_elapse1,time_elapse2,num);
	}
		
	return 0;
	
}
	
