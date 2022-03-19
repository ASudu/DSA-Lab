/********* File: driver.c *********/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bank.h"

int* top_of_stack = NULL;
typedef struct bank* BANK;

BANK insertInOrder(unsigned long long key, BANK b, long size){
	
	long i = size - 1;
	while(i>0 && (b + i)->card_no > key){
		
		(b + i + 1)->card_no = (b + i)->card_no;
		i--;
	}
	
	(b + i + 1)->card_no = key;
	
	return b;

}

BANK insertSort(BANK b, long n){
	
	if(n > 1){
		
		b = insertSort(b, n-1);
		b = insertInOrder((b + n - 1)->card_no, b, n - 1);
	
	}
	
	else if(n <= 1){
		
		int top;
		top_of_stack = &top;
	}
	
		

	return b;
	
}

BANK readData(FILE* f){
	
	BANK arr = malloc(sizeof(struct bank));
	long i = 0;
	long  size = 0;
	
	if(!f)
		printf("File access error\n");
	
	else{
		
		clearerr(f);
		while(fscanf(f,"\"%llu,%[^,],%[^,],%[^,],%[^\"]\"\n", &(arr[i].card_no), arr[i].bank_code, arr[i].date, arr[i].first_name, arr[i].last_name) != EOF){
			
			i++;
			arr = (BANK)realloc(arr,(i+1)*sizeof(struct bank));
			
		}
		 
		printf("%ld lines stored into the array of structures\n", i);
	
	}
	
	fclose(f);
	return arr;
	
}

int main(int argc, char *argv[]){

	FILE* f1 = fopen(argv[1],"r");	
	long inp = atoi(argv[2]);
	int bottom;
	int* bottom_of_stack = &bottom;
	clock_t t1,t2;
	double time_elapse;
	
	// Loading data
	BANK b = readData(f1);
	
	// Time taken for sorting
	t1 = clock();
	b = insertSort(b,inp);
	t2 = clock();
	time_elapse = ((double)(t2-t1))/CLOCKS_PER_SEC;
	
	// Approximate stack size used
	int stack_size = top_of_stack - bottom_of_stack;
	
	FILE* f = fopen("out.txt", "a");
	
	if(!f)
		printf("File access error!\n");
	
	else{
	
		fprintf(f,"%ld,%lf,%d\n",inp,time_elapse,-stack_size);
	}
	
	fclose(f);
		
	return 0;

}
	
	
	
