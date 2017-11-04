#include <stdio.h>
#include <stdlib.h>
// hint: First Step: 

struct tree
{
	int data;
	struct tree *left, *right;
};

typedef struct tree node;
typedef node *btree;


void preorder(btree ptr)
{
	if(ptr!=NULL)
	{
		printf("[%2d ]", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void inorder(btree ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
	    printf("[%2d ]", ptr->data);
		inorder(ptr->right);
	}
}

void postorder(btree ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("[%2d ]", ptr->data);
	}
}

btree creat_tree(btree,int);

int main()
{
	int data[]={7,4,1,5,16,8,11,12,15,9,2};
	int i;
	
	btree ptr=NULL;
	btree root=NULL;
	
	for(i=0; i<11; i++)
		ptr = creat_tree(ptr,data[i]);
			
	printf("============================\n");
	printf("preorder:\n");
	preorder(ptr);
	printf("\n");
	
	printf("============================\n");
	printf("inorder:\n");
	inorder(ptr);
	printf("\n");
	
	printf("============================\n");
	printf("postorder:\n");
	postorder(ptr);
	printf("\n");
	
	
	return 0;
}

btree creat_tree(btree root,int val)
{
	btree newnode, current, backup;
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





