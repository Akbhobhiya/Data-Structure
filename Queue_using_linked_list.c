#include <stdio.h>
#include <stdlib.h>
struct new
{
	int data;
	struct new* link;	
} *rear=NULL,*front=NULL;
void push(void);
void pop(void);
int main()
{
	int i;
	while(1)
	{
		printf("Enter a number(1-3)\n1 for push\n2 for pop\n3 for exit the prog.\n\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3:exit(0);
			default: printf("Wrong choice!!\n\n");
		}
	}

}
void push()
{
	struct new* temp;
	temp=(struct new*)malloc(sizeof(struct new*));
	int num;
	printf("enetr a number that you want to push\n");
	scanf("%d",&num);
	temp->data=num;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->link=temp;
		rear=temp;
	}
}
void pop()
{
	if(front==NULL)
	{
		printf("the queue is empty!!\n");
	}
	else
	{
		struct new* dummy =front;
		front=front->link;
		printf("deleted element is %d\n",dummy->data);
		free(dummy);
	}
}
