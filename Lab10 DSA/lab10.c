#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

long int array[50000];
int a[50000];
int count;

void swap(int *a,int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void min_heapify(int array[],long int n,int i)
{ 
  if (n == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && array[l] < array[smallest])
      smallest = l;
    if (r < n && array[r] < array[smallest])
      smallest = r;
    if (smallest != i)
    {
      swap(&array[i],&array[smallest]);
      count++;
      min_heapify(array,n,smallest);
    }
    
  }
  
}

void build_heap(int array[],long int n)
{ count=0;
  int firstIndex = (n/2) - 1 ;

  for(int i=firstIndex;i>=0;i--)
  {
    min_heapify(array,n,i);
  }
printf("%d \n",count);
}

void sort(int a[],int n)
{
  build_heap(a,n);

  for(int i =0;i<=n-1;i++)
  {
    swap(&a[1],&a[n+1-i]);
    min_heapify(a,n,i);
  }

}

void print_First_K_Smallest(int array[],int n,int k)
{
    for(int i=0;i<=k;i++)
    {
        printf("%d",array[1]);
        swap(&array[1],&array[n-1+i]);
        min_heapify(array,n-i,1);
    }
}

int main()
{
  FILE *fp1;
  FILE *fp2;
  FILE *fp3;

  int i;
  int j;
  long int size;
  long int val;

    fp1=fopen("SearchTestcase.txt","r");
    fp2=fopen("heapLists.txt","w");
    fp3=fopen("sortedLists.txt","w");

    uint64_t diff[50000];
    uint64_t desc[50000];

  for(int i=0;i<20;i++)
  {
    fscanf(fp1,"%ld",&size);
    for(long int j=0;j<size;j++)
    {
      fscanf(fp1,"%ld",&val);
      array[j]=val;
      //diff[j]=array[j];
    }

  build_heap(array,size);
  fprintf(fp2,"%d) ",i+1);
  for(long int j=0;j<size;j++)
  {
    diff[j]=array[j];
    
    fprintf(fp2,"%llu ", (long long unsigned int) diff[j]);
  }
  printf("test- %d \n",i);
  fprintf(fp2,"\n");
  }
    
  
  //fprintf(fp2,"%llu\n", (long long unsigned int) diff);
  /*for(i=0;i<18;i++)
  {
    fscanf(fp1,"%d",&size);
    for(int j=0;j<size;j++)
    {
      fscanf(fp1,"%d",&val);
      array[j]=val;
      //diff[j]=array[j];
    }

  sort(array,size);
  fprintf(fp3,"%d) ",i+1);
  for(int j=0;j<size;j++)
  {
    desc[j]=array[j];
    
    fprintf(fp3,"%llu ", (long long unsigned int) desc[j]);
  }
  fprintf(fp3,"\n");
  }*/
  



fclose(fp3);
fclose(fp2); 
fclose(fp1);

     


}