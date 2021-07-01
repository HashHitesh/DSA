#include <stdio.h>
int MAX = 10;       
int stack[10];     
int top = -1; 
int isStackFull() {

   if(top == MAX)
      return 1;
   else
      return 0;
}

int push(int data) {

   if(!isStackFull()) {
      top = top + 1;   
      stack[top] = data;
   } 
}

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } 
}

int main()
{
    int A[10];
    printf("enter the integer array 10 numbers");
    for(int i=0; i<10; i++)
    {
        scanf("%d", &A[i]);
    }
    for(int i=0;i<10;i++)
    {
        if(isStackFull())
        printf("Stack Full");
        else
        push(A[i]);
    }
int i=0;
while(!isempty()){
    A[i]=pop();
    i++;
}
printf(" reversed array  :-");
for(int i=0;i<10;i++){
    printf(" %d", A[i]);
}
}