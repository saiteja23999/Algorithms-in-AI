#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a[5][5],i,j,md;
};
struct node *queue[150],*swap;
int no=0,h=0,goal[5][5];
int check(int n);
void operation(int k,int l,int n);
void insert(int n)
{
	int i,i1,j,j1,count=0;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the elements of matrix");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&temp->a[i][j]);
	printf("Enter the elements of Goal matrix");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&goal[i][j]);
	count=0;
	for(i1=0;i1<n;i1++)
	{
		for(j1=0;j1<n;j1++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(temp->a[i1][j1]==goal[i][j])
					{
						if((i1+j1)-(i+j)>0)
						{
							count=count+(i1+j1)-(i+j);
						}
						else
						{
							count=count+(i+j)-(i1+j1);
						}
					}
				}
			}
		}
	}
	temp->md=count;
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
		for(i=no;i<=h;i++)
		{
			for(j=no;j<h;j++)
			{
				if(queue[j]->md > queue[j+1]->md)
				{
					swap=queue[j];
					queue[j]=queue[j+1];
					queue[j+1]=swap;
				}
			}
		}
		h=no;
	}
}
void operation(int k,int l, int n)
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	int i,j,i1,j1,tem,count=0;
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
	count=0;
	for(i1=0;i1<n;i1++)
	{
		for(j1=0;j1<n;j1++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(t->a[i1][j1]==goal[i][j])
					{
						if((i1+j1)-(i+j)>0)
						{
							count=count+(i1+j1)-(i+j);
						}
						else
						{
							count=count+(i+j)-(i1+j1);
						}
					}
				}
			}
		}
	}
	t->md=count;
	h++;
	queue[h]=t;
}
int check(int n)
{
	int i,j,i1,i2,cnt=0,cnt1=0;
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
			return -1;
		}
		cnt1=0;
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
