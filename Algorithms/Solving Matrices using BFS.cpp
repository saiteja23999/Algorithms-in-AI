#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a[5][5],i,j;
	struct node *link;
};
struct node *queue[150];
int no=0,h=0,goal[5][5],target;
int check(int n);
void operation(int k,int l,int n);
void insert(int n)
{
	int i,j;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->link=NULL;
	printf("Enter the elements of Initial matrix");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&temp->a[i][j]);
	printf("Enter the elements of Goal matrix");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&goal[i][j]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(temp->a[i][j]==0)
			{
				temp->i=i;
				temp->j=j;
			}
		}
	}
	int k,l;
	queue[no]=temp;
	while(1)
	{
		if(check(n)==-1)
		{
			break;
		}
		
		k=queue[no]->i;
		l=queue[no]->j;
		if(++k<n && l<n)
		{
			operation(k,l,n);
		}
		k=queue[no]->i;
		l=queue[no]->j;
		if(--k<n && l<n && (k>=0 && l>=0))
		{
			operation(k,l,n);
		}
		k=queue[no]->i;
		l=queue[no]->j;
		if(k<n && ++l<n)
		{
			operation(k,l,n);
		}
		k=queue[no]->i;
		l=queue[no]->j;
		if(k<n && --l<n && (k>=0 && l>=0))
		{
			operation(k,l,n);
		}
		no++;
	}
}
void operation(int k,int l, int n)
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	int i,j,i1,j1,tem;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			t->a[i][j]=queue[no]->a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(t->a[i][j]==0)
			{
				i1=i;
				j1=j;
			}
		}
	}
	tem=t->a[i1][j1];
	t->a[i1][j1]=t->a[k][l];
	t->a[k][l]=tem;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(t->a[i][j]==0)
			{
				t->i=i;
				t->j=j;
			}
		}
	}
	h++;
	queue[h]=t;
	t->link=queue[no];
}
int check(int n)
{
	int i,j,i1,i2,cnt=0,cnt1=0;
	for(i1=0;i1<h;i1++)
	{
		for(i2=i1+1;i2<h;i2++)
		{
			cnt=0;
			for(i=0;i<n;i++)	
			{
				for(j=0;j<n;j++)
				{
					if(queue[i1]->a[i][j]==queue[i2]->a[i][j])
					{
						cnt++;
					}
				}
			}
			if(cnt==9)
			{
				for(i1=i2;i1<h;i1++)
				{
				queue[i1]=queue[i1+1];
				}
			h--;
			cnt=0;
			}
			cnt=0;
		}
	}
	cnt1=0;
	for(i1=0;i1<no;i1++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(queue[i1]->a[i][j]==goal[i][j])
				{
					cnt1++;
				}
			}
		}
		if(cnt1==9)
		{
			target=i1;
			return -1;
		}
		cnt1=0;
	}
}
void display(int n)
{
	int i,j;
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	printf("Matrices:\n");
	t=queue[target];
	while(t!=NULL)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d  ",t->a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("  /\\  ");
		printf("\n");
		printf("  ||  ");
		printf("\n");
		t=t->link;
	}
}
main()
{
	int n=3;
	insert(n);
	display(n);
}