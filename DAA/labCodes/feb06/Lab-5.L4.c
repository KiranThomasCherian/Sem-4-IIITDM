#include<stdio.h>
#include<stdlib.h>
struct node
{	int data;
	struct node *lptr;
	struct node *rptr;
};
struct node *tptr=NULL;
void insert(int x)
{	struct node *temp=(struct node *)malloc((sizeof(struct node)));
	temp->data=x;
	temp->lptr=temp->rptr=NULL;
	if(tptr==NULL)
		tptr=temp;
	else
	{	struct node *ptr=tptr;
		struct node *pptr=NULL;
		while(ptr!=NULL)
		{	pptr=ptr;
			if(x<ptr->data)
				ptr=ptr->lptr;
			else
				ptr=ptr->rptr;
		}
		if(x<pptr->data)
			pptr->lptr=temp;
		else
			pptr->rptr=temp;
	}
}
void inorder(struct node *ptr)
{	if(ptr!=NULL)
		{	inorder(ptr->lptr);
			printf("%d  ",ptr->data);
			inorder(ptr->rptr);
		}
}
void main ( )
{	int m,n,a[10][100],x[10];
	printf("Enter the number of arrays:");
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{	printf("Enter the size of array %d:",i+1);
		scanf("%d",&x[i]);
		printf("Enter the array:");
		for(int j=0;j<x[i];j++)
		{	scanf("%d",&a[i][j]);
			insert(a[i][j]);
		}
	}
	inorder(tptr);
}
