//#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	char rollNo[20];
	char emailId[35];
	char lecture[3];
	char tutorial[3];
	char practical[3];
	struct student*next;
};


struct student*createNode(struct student buffer)
{
	struct student*ptr=(struct student*)malloc(sizeof(struct student));
	
	strcpy(ptr->rollNo,buffer.rollNo);
	strcpy(ptr->emailId,buffer.emailId);
	strcpy(ptr->lecture,buffer.lecture);
	strcpy(ptr->tutorial,buffer.tutorial);
	strcpy(ptr->practical,buffer.practical);
	
	ptr->next=NULL;
	return ptr;
}


struct student*StackTop=NULL;

int isEmpty(struct student**top) {
	return *top == NULL;
}

struct student* pop(struct student**top)
{
	if(isEmpty(top))
	{
		return NULL;
	}
	struct student* temp = *top;
	*top = (*top)->next;
	return temp;
}

int push(struct student**top, struct student* temp)
{
	temp->next = (*top);
	(*top) = temp;
	printf("%s pushed\n", temp->rollNo);
	return 0;
}

int main()
{
	FILE*fp1;
	int i;
	int op;
	struct student buffer;
	struct student*nodeCopy;
	
	fp1=fopen("testcaseForStack.txt","r");
	if(fp1==NULL){printf("\nFile read error\n");exit(0);}
	for(i=0;i<138;i++)
	{
		fscanf(fp1,"%d",&op);
		if(op==1)
		{
			fscanf(fp1,"%s",buffer.rollNo);
			fscanf(fp1,"%s",buffer.emailId);
			fscanf(fp1,"%s",buffer.lecture);
			fscanf(fp1,"%s",buffer.tutorial);
			fscanf(fp1,"%s",buffer.practical);
			
			nodeCopy=createNode(buffer);
			push(&StackTop, nodeCopy);
		}
		else
		{
			struct student* popped = pop(&StackTop);
			if(popped) {
				printf("%s %s\n", popped->rollNo, popped->emailId);
			}
			else {
				printf("Underflow!\n");
			}
		}
	}
	
	fclose(fp1);
}
