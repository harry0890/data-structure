#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
typedef struct tree node;
typedef node *btree;

btree root;
btree root2;

btree create(char seq[100], int index, int size)
{
	btree temp;
	if(seq[index] == 0 || index >= size)
		return NULL;
	else{
		temp=(btree)malloc(sizeof(tree));
		temp->data=(int)seq[index];
		temp->left=NULL;
		temp->right=NULL;
		
		temp->left=create(seq, 2*index, size);
		temp->right=create(seq, 2*index+1, size);
		return temp;
	}
	
}

void preOrder(btree ptr)
{
	if(ptr!=NULL)
	{
		printf("%c",(char)ptr->data);
		preOrder(ptr->left);
		preOrder(ptr->right);	
	}	
}

void inOrder(btree ptr)
{
	if(ptr!=NULL)
	{
		inOrder(ptr->left);
		printf("%c",(char)ptr->data);
		inOrder(ptr->right);
	}
}

void postOrder(btree ptr)
{
	if(ptr!=NULL)
	{
		printf("%c",(char)ptr->data);
		postOrder(ptr->left);
		postOrder(ptr->right);
	}
}




int main()
{
	char info1[] = {' ','+','*','%','6','3','9','5' };
	char info2[] = {' ','+','+','+','*','%','/','*',
                	'1','2','3','2','6','3','2','2' };
	
	root=(btree)malloc(sizeof(node));
	root2=(btree)malloc(sizeof(node));
	
	
	root = create(info1,1,8);
	printf("====�G���B���ƭȹB��d�� 1: ====\n");
    inOrder(root);     
    preOrder(root);    
    postOrder(root);
	
	
	printf("\n���G���B���,�g�L�p���ұo�쪺���G��: ");
    printf("%d",answer(root));
	
	root2 = create(info2,1,16);
    printf("\n\n");
    printf("====�G���B���ƭȹB��d�� 2: ====\n");
    inOrder(root2);     
    preOrder(root2);    
    postOrder(root2);   
	
	printf("\n���G���B���,�g�L�p���ұo�쪺���G��: ");
    printf("%d\n",answer(root2));
	
	
	
	
	
	return 0;
}






