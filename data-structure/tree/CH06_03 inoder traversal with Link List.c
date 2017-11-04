#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int data;
	struct node *left, *right;	
};

typedef struct tree node;
typedef node *btree;

btree create_btree(btree,int);

void inorder(btree ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("[%2d] ",ptr->data);
		inorder(ptr->right);
	}
}


int main()
{
	int data[]={5,6,24,8,12,3,17,1,9};
	int i;
	btree ptr=NULL;
	btree root=NULL;
	
	/*build binary tree*/
	for(i=0;i<9;i++){
		ptr = create_btree(ptr,data[i]);
	}
	
	
	
	printf("================\n");
	printf("sorting complete: \n");
	
	inorder(ptr);
	printf("\n");
	
	return 0;
}

btree create_btree(btree root, int val)
{
	btree current, newnode, backup;
	
	newnode=(btree)malloc(sizeof(node));
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
			if(current->data > val)
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






