#include <stdio.h>
#include "driver.h"
#include <stdlib.h>
#include <string.h>

int size_array;


void createFile(FILE *fptr, REC rec,int K){
    for(int i=0;i<K;i++){
        fprintf(fptr,"%s,%lf\n",rec[i].name,rec[i].cgpa);
    }
    

}

void filesplit(FILE *fptr, int K){
    REC rec = malloc(K*sizeof(struct record));
    int size = 0;
    int file  = 1;
    size_array=K;
    int flag=1;
    while(flag){
        if(feof(fptr)){
            flag=0;
        }
       if(size<K){
           char c;
           fscanf(fptr,"%[^,],%lf",rec[size].name,&(rec[size].cgpa));
           fscanf(fptr,"%c",&c);
           size++;
       }else{
           rec = mergeSort(rec,0,K-1);
           char buffer[32]; 
           snprintf(buffer, sizeof(char) * 32, "file%i.txt", file);
           FILE* fptr2;
           fptr2 = fopen(buffer,"w");
           createFile(fptr2,rec,K);
           fclose(fptr2);
           file++;
           size=0;
           free(rec);
           rec = malloc(K*sizeof(struct record));
       }
    }
    fclose(fptr);
}


REC merge(REC r, int st, int mid, int en){
    REC temp = malloc((size_array)*sizeof(struct record));
    for(int i=0;i<size_array;i++){
        temp[i]=r[i];
    }
    int s1 = st;
    int s2 = mid;
    int i=st;

    while(s1<(mid) && s2 <(en+1)){
        if(r[s1].cgpa < r[s2].cgpa){
            temp[i].cgpa = r[s1].cgpa;
            strcpy(temp[i].name, r[s1].name);
            i++;
            s1++;
        }else{
            temp[i].cgpa = r[s2].cgpa;
            strcpy(temp[i].name, r[s2].name);
            i++;
            s2++;
        }
    }
    while(s1<(mid)){
            temp[i].cgpa = r[s1].cgpa;
            strcpy(temp[i].name, r[s1].name);
            i++;
            s1++;
    }
    while(s2<(en+1)){
            temp[i].cgpa = r[s2].cgpa;
            strcpy(temp[i].name, r[s2].name);
            i++;
            s2++;
    }
    for(int i=st;i<en+1;i++){
        r[i]=temp[i];
    }
    // free(temp);
    return r;

}

REC mergeSort(REC r,int st, int en){
    int st2;
    int st1;
    int en2;
    for(int slsz=1;slsz<=size_array/2;slsz*=2){
        for( st1=st; st1<size_array; st1 += 2*slsz ){
             st2 = st1 + slsz;
             en2 = st2+slsz-1;
            if(st2>en){
                en2 = en;
            }
            if(st2-1>en){st2 = en+1;}
            r = merge(r,st1,st2,en2);
        }
        
        
    }
    return r;
}

