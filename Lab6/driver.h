typedef struct record* REC;

struct record{
char name[11];
double cgpa;
};

REC mergeSort(REC r,int st, int en);
REC merge(REC r, int st, int mid, int en);
void filesplit(FILE *fptr, int K);
void createFile(FILE *fptr, REC rec,int K);