#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int *arr;
int size;

void func()
{  

   arr[0]= -1;
   arr[1]=  1;

     
   for(int i=size-1;i>1;i--)
   {    
        
        if(arr[i]>0)
        {       
            arr[i/2]=rand();
        }

        else
        { arr[i]=-1; }

   }  

}

int main()
{
    size = 10;
    arr = (int*)malloc(sizeof(int)*size);

    for(int i=0;i<size;i++)
    {
        arr[i]=0;
    }

    arr[2]=-4;
    arr[3]=-6;
    arr[4]=20;
    arr[5]=-10;
    arr[6]=12;
    arr[7]=-14;
    arr[8]=16;
    arr[9]=18;
    
    
   func();
   
   arr[1]=1;

  /* for(int j=0;j<size;j++)
   {
       printf("%d ",arr[j]);
   } */

   for(int j=0;j<size;j++)
   {
      if(arr[j]>0)
      { printf("%d ",arr[j]); }
      else
      continue;


   } 

   return 0;
   


}




