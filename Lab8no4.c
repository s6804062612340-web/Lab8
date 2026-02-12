#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random1to100();
void printAr(int numAr[],int numArSize);
int checkNum(int numAr[],int numArSize);
int searchNum(int numAr[],int numArSize,int target);
void swap(int *i,int *j);
void bublesort(int ar[],int sizear);

int main() {
    int N,i;
    int A[100];
    scanf("%d",&N);
    if (N>100) 
        N=100;

    srand(time(NULL));
    
    for (i=0;i<N;i++)
        A[i]=checkNum(A,i);
       
    printf("\n********\n");

    bublesort(A,N);  //sort เลขดูว่าซ้ำกันไหม
    printAr(A,N);
    printf("\n3 Best scores are :");
    for(int i=N-3;i < N ; i++){
        printf(" %d",A[i]);
    }
    
    return 0;
}
void printAr(int numAr[],int numArSize) {
    int i;
    for (i=0;i<numArSize;i++)
        printf("%d ",numAr[i]);
} 

int checkNum(int numAr[],int numArSize) {
    int rnum;
    rnum=random1to100();
    while (searchNum(numAr,numArSize,rnum)) {
        rnum=random1to100();
    }
    return rnum;
}

int searchNum(int numAr[],int numArSize, int target) {

        //sol1* use Linear search
        //sol2 use binary search  see.Lab6no9-10 
        int found=0;
        for (int i=0 ; i <=numArSize ; i++)
            if(numAr[i]==target)found=1;
        // your code here 

        return found;
}

int random1to100() {
    int random_num = (rand() % 100) + 1;
    printf("%d ", random_num);
    return random_num;
}

void swap(int *i,int *j){
    int temp=*i;
    *i=*j;
    *j=temp;
}

void bublesort(int ar[],int sizear){
    for(int j=0 ; j < sizear ; j++){
    for(int i=0 ; i < sizear-1 ; i++){
        if(ar[i] > ar[i+1]){ 
            swap(&ar[i],&ar[i+1]);    
            }
        }
    }
}
