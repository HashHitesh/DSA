#include<stdio.h>
#include<string.h>
#include<malloc.h>
char expr[100];
#define max 50    
char s[max];  
int top = -1;
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}   
void push(char data) {
      top = top + 1;   
      s[top] = data;
}
char pop() {
  char a;
      a = s[top];
      top = top - 1;   
      return a;
}
  
struct node
{
    char data;
    struct node* l;
    struct node* r;
};
struct node* head = NULL;

struct node * create(char temp)
{  struct node* new;
   struct node* current;
   new =(struct node*)malloc(sizeof(struct node));
   new->data = temp;
   new->r = NULL;
   new->l = NULL;
   if(head == NULL) {
      head = new;
   } 
   return new;
    
}

char* constructTree(char s[])
{   char x;
    struct node* t;
    if(isempty())
    printf("Stack is empty");
    else
    {
        x = pop();
        t = create(x);
        if(x=='*' || x=='/' || x=='+' || x=='-' || x=='^')
        {
             t->r = constructTree(s);
             t->l = constructTree(s); 
        }
    }
}

void inorder_traversal(struct node* head) {
   if(head != NULL) {
      inorder_traversal(head->l);
      printf("%c",head->data);          
      inorder_traversal(head->r);
   }
}
void main()
{int len,i;
printf("Enter Postfix Expression\n");
  gets(expr);
  len=strlen(expr);
  for(i=0;i<len;i++)
  {   push(expr[i]);
  }
  constructTree(s);
  printf("The Inorder Traversal : \n");
  inorder_traversal(head);
}