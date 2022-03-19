/************* File: main.c *************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "exercise2.h"
#include "cycle.h"
extern int heap_memory_taken;

int main(){

	clock_t t1, t2;
	double elapsed_time1, elapsed_time2, elapsed_time3;
	
	// Open file in append mode
	FILE *f = fopen("detect_cycle.txt", "a");
	
	if(!f){
	
		printf("Can't access file!\n");
	}
	
	else{	
	
		// Random number for size of list
		srand(time(0));
		long int N = (rand() % 200001) + 1000000;
		
		t1 = clock();
		LinkedList l = createList(N); // Create Linked List
		t2 = clock();
		elapsed_time1 = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
		
		t1 = clock();
		l = createCycle(l); // Create cycle or leave it linear
		t2 = clock();
		elapsed_time2 = ((double) (t2 - t1)) / CLOCKS_PER_SEC;	
		
		
		t1 = clock();
		int cyclic = testCyclic(l); // Detect cycle
		t2 = clock();
		elapsed_time3 = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
		
		// Writing the stats to text file
		fprintf(f, "%ld,%lf,%lf,%lf,%d.\n", N, elapsed_time1, elapsed_time2, elapsed_time3, heap_memory_taken);
		
	}
	
	fclose(f);
	
	return 0;
	
}
	
	
