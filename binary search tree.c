#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int d;
	struct Node *l;
	struct Node *r;
}*root=NULL,*temp;
struct Node * insert(struct Node *root,int x)
{
	if(root==NULL)
	{
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->d=x;
		temp->l=temp->r=NULL;
		root=temp;
	}
	else if (x<root->l)
	    root->l=insert(root->l,x);
	else
	    root->r=insert(root->r,x);
	return root;
}
void search(struct Node *root, int s)
{
	if(root==NULL)
	printf("Search element not found");
	else if(s==root->d)
	printf("Search element found");
	else if (s<root->d)
	search(root->l,s);
	else if(s>root->d)
	search (root->r,s);
}
struct Node *del(struct Node *root, int n)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return NULL;
	}
	else if(n<root->d)
	    root->l=del(root->l,n);
	else if(n>root->d)
	    root->r=del(root->r,n);
	else if(root->l==NULL && root->r==NULL)
	    {
	    	temp=root->d;
	    	free(temp);
	    	return root;
		}
	else if(root->l==NULL)
	{
		temp=root->d;
		free(temp);
		return root->r;
	}
	else if(root->r==NULL)
	{
		temp=root->d;
		free(temp);
		return root->l;
	}
}
main()
{
	int n,data,s,de,ch;
	while(1)
	{
		printf("Enter your choice 1. Insert 2. Search 3. Delete 4. Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter data to insert: ");
			        scanf("%d",&data);
			        root=insert(root,data);
			        break;
			case 2: printf("enter element to search: ");
			        scanf("%d",&s);
			        search(root,s);
			        break;
			case 3: printf("Enter data to delete");
			        scanf("%d",&de);
			        del(root,de);
			        break;
			case 4: exit(0);
		}
	}
}
