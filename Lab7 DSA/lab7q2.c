#include<stdio.h>
#include<stdlib.h>
#include<stdint.h> 
#include<time.h>  

struct Node
{
    int data;
    struct Node* next;
};


void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

struct Node* sortedMerge(struct Node* a, struct Node* b)
{
    // base cases
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    struct Node* result = NULL;
 
    
    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
 
    return result;
}
void frontBackSplit(struct Node* source, struct Node** frontRef,
                    struct Node** backRef)
{
    
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
 
    struct Node* slow = source;
    struct Node* fast = source->next;
 
    
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    
    
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
 

void mergesort(struct Node** head)
{
    
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
 
    struct Node* a;
    struct Node* b;
 
    
    frontBackSplit(*head, &a, &b);
    mergesort(&a);
    mergesort(&b);
   *head = sortedMerge(a, b);


}

void printList(struct Node *head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
 
     // printf("NULL\n");
}

int main()
{
   struct Node* head = NULL;
   push(&head,19);
   push(&head,17);
   push(&head,5);
   push(&head,13);
   push(&head,24);
   push(&head,16); 
   push(&head,69);

   mergesort(&head); 
   printList(head);
   return 0;

}