#include<stdio.h>
#include<stdlib.h>
#include<stdint.h> /* for uint64 definition */ 
#include<time.h> /* for clock_gettime */ 

#define BILLION 1000000000L

int A[5000000];
int B[5000000];
int C[5000000];

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(A[l1] <= A[l2])
         B[i] = A[l1++];
      else
         B[i] = A[l2++];
   }
   
   while(l1 <= mid)    
      B[i++] = A[l1++];

   while(l2 <= high)   
      B[i++] = A[l2++];

   for(i = low; i <= high; i++)
      A[i] = B[i];
}

void mergesort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      mergesort(low, mid);
      mergesort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to partition the array on the basis of pivot element
int partition( int low, int high) {
  
  // Select the pivot element
  int pivot = C[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left 
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (C[j] <= pivot) {
      i++;
      swap(&C[i], &C[j]);
    }
  }

  swap(&C[i + 1], &C[high]);
  return (i + 1);
}

void quickSort(int low, int high) {
  if (low < high) {
    
    // Select pivot position and put all the elements smaller 
    // than pivot on left and greater than pivot on right
    int pi = partition( low, high);
    
    // Sort the elements on the left of pivot
    quickSort( low, pi - 1);
    
    // Sort the elements on the right of pivot
    quickSort( pi + 1, high);
  }
}

int main()
{

    FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	int i,j;
	int x,val;
    int size;

    fp1=fopen("SearchTestcase.txt","r");
    fp2=fopen("MergeSortTime.txt","w");
    fp3=fopen("QuickSortTIme.txt","w");

   uint64_t diff;
   struct timespec startM,endM,startQ,endQ;
  for(i=0;i<18;i++)
{
    fscanf(fp1,"%d",&size);
     for(j=0;j<size;j++)
      {
          fscanf(fp1,"%d",&val);
          A[j]=val;
          C[j]=val;
      }


  

clock_gettime(CLOCK_MONOTONIC, &startM); 
mergesort(0,size-1);		
clock_gettime(CLOCK_MONOTONIC, &endM);
diff = BILLION * (endM.tv_sec - startM.tv_sec) + endM.tv_nsec - startM.tv_nsec; 
fprintf(fp2,"%llu\n", (long long unsigned int) diff);



clock_gettime(CLOCK_MONOTONIC, &startQ); 
quickSort(0,size-1);		
clock_gettime(CLOCK_MONOTONIC, &endQ);
diff = BILLION * (endQ.tv_sec - startQ.tv_sec) + endQ.tv_nsec - startQ.tv_nsec; 
fprintf(fp3,"%llu\n", (long long unsigned int) diff);



}

fclose(fp3);
fclose(fp2); 
fclose(fp1);





}

