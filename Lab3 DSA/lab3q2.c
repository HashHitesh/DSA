#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h> /* for uint64 definition */ 
#include<time.h> /* for clock_gettime */ 

#define BILLION 1000000000L




int*queue;//the array that holds the queue
int queue_size;//size of the queue[] array
int opCode;
int front=0, rear=0;//queue index variables
int stack1[8]; //memory allotted for stack1
int top1=-1;// index of the topmost variable in stack1
int stack2[8]; //memory allotted for stack2
int MAXSIZE = 8;
int top2=-1; // index of the topmost variable in stack2
int x,y;
int isStack2Full()// returns 1 if stack2[] is full and 0 otherwise
{
   if(top2 == MAXSIZE)
      return 1;
   else
      return 0;
}
int isStack2Empty()//returns 1 if stack2[] is empty and 0 otherwise
{
  if(top2 == -1)
      return 1;
   else
      return 0;
}
int isStack1Full()// returns 1 if stack1[] is full and 0 otherwise
{
   if(top1 == MAXSIZE)
      return 1;
   else
      return 0;
}
int isStack1Empty()//returns 1 if stack1[] is empty and 0 otherwise
{
  if(top1 == -1)
      return 1;
   else
      return 0;
}
int pop2() //pops and returns an element from stack2
{
  int data;
	
   if(!isStack2Empty()) {
      data = stack2[top2];
      top2 = top2 - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}
int push2(int p)//pushes an element to stack2
{
  if(!isStack2Full()) {
      top2 = top2 + 1;   
      stack2[top2] = p;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}
int pop1()//pops an element from stack1
{
  int dat;
	
   if(!isStack1Empty()) {
      dat = stack1[top1];
      top1 = top1 - 1;   
      return dat;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}
int push1(int l)//pushes an element to stack1
{
  if(!isStack1Full()) {
      top1 = top1 + 1;   
      stack1[top1] = l;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int isQueueEmpty()//returns 1 if Queue is empty and 0 otherwise
{
  if (isStack2Empty() == 1)
return 1;
else
return 0;
}

int isQueueFull()//returns 1 if Queue is full and 0 otherwise
{
if (isStack2Full() == 1)
return 1;
else
return 0;
}

int enQueue(int x)//returns -1 if Queue is full and 1 otherwise
{
if(isQueueFull())
return -1;
push2(x); //push to the second stack
return 1;
}

int deQueue()//returns -1 if Queue is empty and the value otherwise
{
   int y;
  if(isQueueEmpty())
   {return -1;}
while (isStack2Empty() == 0) //stack2 is not empty
{
  x=pop2();
  push1(x);
}
y=pop1();
return y;

while (isStack1Empty() == 0)  //stack2 is not empty
{
  
x=pop1();
push2(x);
}
return y;
}

int main()
{ 
  int n,y;
  int o;
  while(n!=3) {
 printf("enter 1 for enqueue 2 for dequeue 3 for exit");
 scanf("%d",&n);
  switch(n)
  {
    case 1:
      printf("enter the value to be enqueued \n");
      scanf("%d",&o);
      enQueue(o);
      break;
    case 2:
      y=deQueue();
      break;
    case 3:
      exit(0);
  }

  }
}



