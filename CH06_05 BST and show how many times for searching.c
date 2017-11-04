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


btree btree_search(btree ptr,int search_val)
{
	int count=1;
	while(1)
	{
		if(ptr==NULL)
		{
			printf("total search times = %d\n",count);
			printf("No founded it !!");
			return NULL;
		}
		if(ptr->data==search_val)
		{
			printf("total search times = %d\n",count);
			printf("Have founded it !!");
			return ptr;
		}
		else if(ptr->data > search_val)
			ptr=ptr->left;
		else
			ptr=ptr->right;	
		count++;	
	}
}



int main()
{
	int data[]={7,1,4,2,8,13,12,11,15,9,5};
	int i,num;
	
	btree ptr=NULL;
	btree root=NULL;
	
	printf("[Original Content of Matrix]\n");
	for(i=0; i<11; i++)
		printf(" [%2d]",data[i]);
	
	printf("\nPlease enter a search number: ");
	scanf("%d",&num);
	printf("%d\n",num);	

	for(i=0; i<11; i++)
		ptr=create_btree(ptr,data[i]);
	
	ptr=btree_search(ptr,num);
	
	//


	return 0;
} 


btree create_btree(btree root,int val)
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







