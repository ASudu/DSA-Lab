#include <stdio.h>
#include "driver.h"
#include <stdlib.h>
#include "filesort.h"

void mergeFiles(FILE *f1, FILE *f2){
     FILE * fo = fopen("fout.txt","a");
     REC rec1 = malloc(sizeof(struct record));
     REC rec2 = malloc(sizeof(struct record));
     

     fscanf(f1,"%[^,],%lf\n",rec1->name,&(rec1->cgpa));
     fscanf(f2,"%[^,],%lf\n",rec2->name,&(rec2->cgpa));

     while((!feof(f1))&&(!feof(f2))&&(rec1!=NULL&&rec2!=NULL)){
         if(rec1->cgpa>rec2->cgpa){
             fprintf(fo,"%s,%lf\n",rec2->name,rec2->cgpa);
             fscanf(f2,"%[^,],%lf\n",rec2->name,&(rec2->cgpa));
         }else if(rec2->cgpa>rec1->cgpa){
             fprintf(fo,"%s,%lf\n",rec1->name,rec1->cgpa);
             fscanf(f1,"%[^,],%lf\n",rec1->name,&(rec1->cgpa));
         }else if (rec2->cgpa==rec1->cgpa){
             fprintf(fo,"%s,%lf\n",rec2->name,rec2->cgpa);
             fprintf(fo,"%s,%lf\n",rec1->name,rec1->cgpa);
             fscanf(f1,"%[^,],%lf\n",rec1->name,&(rec1->cgpa));
             fscanf(f2,"%[^,],%lf\n",rec2->name,&(rec2->cgpa));
         }
     }

     if(rec1->cgpa<rec2->cgpa){
          fprintf(fo,"%s,%lf\n",rec1->name,rec1->cgpa);

        
     }else{
          fprintf(fo,"%s,%lf\n",rec2->name,rec2->cgpa);
          
     
          
     }
         while(!feof(f2)){
         fscanf(f2,"%[^,],%lf\n",rec2->name,&(rec2->cgpa));
         fprintf(fo,"%s,%lf\n",rec2->name,rec2->cgpa);
         
         
     }
      while(!feof(f1)){
         fscanf(f1,"%[^,],%lf\n",rec1->name,&(rec1->cgpa));
         fprintf(fo,"%s,%lf\n",rec1->name,rec1->cgpa);
         
         
     }
     


   


     fclose(f1);
     fclose(f2);
     fclose(fo);
      


}

int main(){
    FILE *f = fopen("1024.txt","r");
    filesplit(f,512);
    FILE *f1 = fopen("file1.txt","r");
    FILE *f2 = fopen("file2.txt","r");
    mergeFiles(f1,f2);



}