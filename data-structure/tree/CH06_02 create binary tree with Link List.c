#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int data;
	struct tree *left, *right;
};

typedef struct tree node;
typedef node *btree;

btree create_btree(btree,int);



int main()
{
	int data[]={5,6,24,8,12,3,17,1,9};
	int i;
	
	btree ptr = NULL;
	btree root = NULL;	

	
	printf("-----Create Binary Tree------\n");
	for(i=0; i<9; i++)
		ptr = create_btree(ptr,data[i]);
	
	printf("-----------Leaf Tree---------\n");
	
	root = ptr->left;
	
	while(root != NULL)
	{
		printf("%d\n",root->data);
		root=root->left;
	}
	
	printf("------------------------------\n");
	printf("----------Right Tree----------\n");
	
	root = ptr->right;
	
	while(root != NULL)
	{
		printf("%d\n",root->data);
		root=root->right;
	}
	
	printf("\n");
	return 0;	
} 

btree create_btree(btree root, int val)
{
	btree newnode, current, backup;
	
	newnode = (btree)malloc(sizeof(node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	
	if(root==NULL)
	{
		root=newnode;
		return root;
	}
	else
	{
		for(current=root; current!=NULL;)
		{
			backup=current;
			if(current->data > val) // root > node
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data > val)
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root;
}























