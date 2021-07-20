#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a[5][5],i,j;
};
struct node *queue[150];
int no=0,h=0;
void check(int n);
void operation(int k,int l,int n);
void insert(int n)
{
	int i,j;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the elements of matrix");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&temp->a[i][j]);
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
		check(n);
		if(no==20)
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
}
void check(int n)
{
	int i,j,i1,i2,cnt=0;
	for(i1=0;i1<h;i1++)
	{
		for(i2=i1+1;i2<h;i2++)
		{
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
}
void display(int n)
{
	printf("Matrices:\n");
	int j,k,l;
	for(j=0;j<no;j++)
	{
		for(k=0;k<n;k++)
		{
			for(l=0;l<n;l++)
			{
				printf("%d\t",queue[j]->a[k][l]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
main()
{
	int n=3;
	insert(n);
	display(n);
}
