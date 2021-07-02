#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int x,y;
// stacks
struct node
{
  int data;
  struct node *next;
};

struct node *top1 = NULL;
struct node *top2 = NULL;

int isStack1empty()
{
  if (top1==NULL)
  {return 1;}
  else
  {return 0;}

}

int isStack2empty()
{
  if (top2==NULL)
  {return 1;}
  else
  {return 0;}

}

int push1(int p1)
{
  struct node *newnode1;
  newnode1 = (struct node*)malloc(sizeof(struct node));
  newnode1->data=p1;
  if(top1==NULL)
    {newnode1->next=NULL;}
  else
   newnode1->next = top1;
    top1 = newnode1;
    //printf("Insertion successfull %d",&p1);

}

int push2(int p2)
{
    struct node *newnode2;
  newnode2 = (struct node*)malloc(sizeof(struct node));
    if(isStack2empty())
{ newnode2->data = p2;
  newnode2->next=NULL;
  top2 = newnode2;}
    else
      {newnode2->data = p2;
  newnode2->next = top2;
  top2=newnode2;}
  //printf("Insertion successfull :%d \n",p2);

}

int pop1()
{ int temp;
 if (top1==NULL)
 {
   printf("Empty stack");
 }
 else
 {
  struct node *temp1 = top1;
  temp = temp1->data;
  //printf("deleted element :%d",temp1->data);
  top1=temp1->next;
  //free(temp1);
 } 
 return temp;
}


int pop2()
{ int temp;
 if (top2==NULL)
 {
   printf("Empty stack");
 }
 else
 {
  struct node *temp2 = top2;
  temp = temp2->data;
  //printf("deleted element:%d",temp2->data);
  top2=temp2->next;
  //free(temp2);
 } 
 return temp;
}



int isQueueEmpty()
{
  if(isStack2empty()==1)
  {return 1 ;}
  else
  return 0;

}

int Enqueue(x)
{
  
  push2(x);
  printf("insertion successful : %d \n",x);
  return 1;
}

int DeQueue()
{ int x;
   if(isQueueEmpty())
   {return -1;}

  while (isStack2empty()==0)
  {
    x = pop2();
    push1(x);
  }
  y = pop1();

  while (isStack1empty()==0)
{
 x=pop1();
 push2(x);

}
return y;

}

int main()
{
int o=1;
int n;
int x;
while(o!=3){
printf("Enter 1 for enqueue , 2 for dequeue and 3 for exit \n");
scanf("%d",&o);
switch(o)
  {
    case 1:
      printf("enter the value to be enqueued \n");
      scanf("%d",&n);
      Enqueue(n);
      break;
    case 2:
     x= DeQueue();
     printf("element deleted : %d \n",x);
      break;
  }
}

}

