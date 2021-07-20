#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
	int data,loc;
	struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;
struct node *t;
bool isempty()
{
	if(front==NULL&&rear==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void enqueue(int d,int l)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->loc=l;
	temp->link=NULL;
	if(front==NULL || front->loc <= temp->loc)
	{
		temp->link=front;
		front=temp;
	}
	else
	{
		t=front;
		while(t->link!=NULL&&t->link->loc > temp->loc)
		{
			t=t->link;
		}
		temp->link=t->link;
		t->link=temp;
	}
}
void display()
{
	if(isempty())
	{
		printf("Queue is empty");
	}
	else
	{
		struct node *ptr=front;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->link;
		}
	}
}
void showfront()
{
	if(isempty())
	{
		printf("Queue is empty");
	}
	else
	{
		printf("%d",front->data);
	}
}
void dequeue()
{
	if(isempty())
	{
		printf("Queue is empty");
	}
	else if(front==rear)
	{
		free(front);
		front=rear=NULL;
	}
	else
	{
		struct node *ptr=front;
		front=front->link;
		free(ptr);
	}
}
main()
{
	int choice,val,p;
	while(1)
	{
		printf("\n1.Insertion");
		printf("\n2.Deletion");
		printf("\n3.Display");
		printf("\n4.Show Front");
		printf("\n5.Exit");
		printf("\nEnter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter the value");
					scanf("%d",&val);
					printf("Enter the priority");
					scanf("%d",&p);
					enqueue(val,p);
					break;
			case 2: dequeue();
					break;
			case 3: display();
					break;
			case 4: showfront();
					break;
			default: exit(1);
		}
		
	}
}

