#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdint.h>

#define size 10
int top=-1;
char stack[size];

int Size()
{
    if(top!=-1){return top;}
    else 
    return 0;
}

bool empty()
{
    if(top<0){return true;}
    else 
    return false;
}

bool full()
{
    if(top== size-1){return true;}
    else
    return false;
    
}

char top_s()
{
    if(!empty())
    {return stack[top];}
    else 
    return -1;
}

void push(char x)
{
    if(!full())
    {
        top++;
        stack[top]=x;
    }
    else 
    {
        printf("Stack full");
    }
}

char pop()
{
    if(!empty())
    {
        int temp = stack[top];
        top--;
        return temp;
    }
    else
    return -1;
}

void Balance(char arr[], int n)
{
  char ck;
  for(int i =0;i<n;i++)
  {
      if (arr[i]=='['||arr[i]=='{'||arr[i]=='(')
     {
         push(arr[i]);
     }
  
  else if(arr[i]==']')
  {
   ck = pop();
   if(ck!='[')
    {printf("Unbalanced");}
  }
  
   else if(arr[i]=='}')
  {
   ck = pop();
   if(ck!='{')
    {printf("Unbalanced");}
  }
  
   else if(arr[i]==')')
  {
   ck = pop();
   if(ck!='(')
    {printf("Unbalanced");}
  }
    
}

if(!empty())
{printf("Unbalanced");}
else
{printf("Balanced");}
}


int main()
{
    char arr[]={'[','(',')',']'};
    Balance(arr,6);

    return 0;
}