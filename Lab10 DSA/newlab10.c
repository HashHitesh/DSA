#include<stdio.h>
#include<stdlib.h>

int c=0;

void swap(int* A, int i, int j)
{
	c++;
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void min_heapify(int* A,int n,int i) 
{ 
	int smallest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l<n && A[l]<A[smallest]) 
    smallest = l;
  
	if(r<n && A[r]<A[smallest])
		smallest = r;
	if(smallest!=i) 
  {
		swap(A,i,smallest);
		min_heapify(A,n,smallest);
	}
}	

void build_heap(int* A,int n)
{
	for(int i=n/2-1; i>=0; i--)
		min_heapify(A,n,i);
}

void sort(int* A,int n) 
{
	for(int i=1; i<n; i++) 
  {
		swap(A,0,n-i);
		min_heapify(A,n-i,0);
	}
}

void print_first_k_ele(int* A,int n,int k) 
{
	for(int i=1; i<=k; i++) 
  {
		printf("%d ",A[0]);
		swap(A,0,n-i);
		min_heapify(A,n-i,0);
	}
}

int main() 
{
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	int size;
	fp1 = fopen("searchTestCase.txt","r");
	fp2 = fopen("heapList.txt","w");
	fp3 = fopen("sortedList.txt","w");
	for(int i=0; i<18; i++) 
  {
		c=0;
		fscanf(fp1,"%d",&size);
    
		int* A = (int*)calloc(sizeof(int),size);
    
		for(int j=0; j<size; j++)
			fscanf(fp1,"%d",&A[j]);
    
		build_heap(A,size);
		fprintf(fp2,"\n%d ",size); 
    
		for(int j=0; j<size; j++) 
			fprintf(fp2,"%d ",A[j]);
    
		printf("Total swap: %d\n",c);
		sort(A,size);
		fprintf(fp3,"\n%d ",size);
    
		for(int j=0; j<size; j++)
			fprintf(fp3,"%d ",A[j]);
	}
  
	fclose(fp2);
  
	FILE *fp4;
	fp4 = fopen("heapList.txt","r");
	for(int i=0;i<18;i++)
  {
		fscanf(fp4,"%d ",&size);
		int* A = (int*)calloc(sizeof(int),size);
    
		for(int j=0; j<size; j++) 
			fscanf(fp2,"%d ",&A[j]);
    
		int k;
		int r=88;
    
		k = size%100+r > size ? size%100 : size%100+r;
		printf("\nSize %d printing first %d elements:\n",size,k);
		print_first_k_ele(A,size,k);
		printf("\n");
	}
}
