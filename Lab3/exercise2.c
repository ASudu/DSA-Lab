/********* File: exercise2.c *********/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "exercise2.h"

int heap_memory_taken = 0;

/* size_t is an unsigned data type defined in stddef.h.It can be further imported by inclusion of stdlib.h as this file internally sub includes stddef.h.
This type is used to represent the size of an object. Library functions that take or return sizes expect them to be of type or have the return type of size_t*/
void *myalloc(size_t size){
	
	void *p = malloc(size);
	heap_memory_taken += size;
	// printf("Amount of heap memory allocated: %d\n", heap_memory_taken);
	
	return p;
	
}

void myfree(void *point, int deallot){
	
	free(point);
	heap_memory_taken -= deallot;
	// printf("After deallocating, amount of heap memory allocted: %d\n", heap_memory_taken);
	
}

void update_file(){

	FILE *f;
	// int temp_size = 0;
	f = fopen("heap_size_taken.txt", "w");
	
	if(!f)
		printf("Failed to open heap_size_take.txt\n");
	
	else{
		
		fprintf(f,"Amount of heap memory allocated: %d", heap_memory_taken);
	
	}	

}
	
