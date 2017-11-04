#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 11

struct Node
{
	int value, left_thread, right_thread;
	struct Node *left_Node, *right_Node;	
};
typedef struct Node ThreadNode;
typedef ThreadNode *ThreadBinaryTree;

ThreadBinaryTree rootNode=NULL;

void add_node_to_tree(int value)
{
	ThreadBinaryTree newnode, previous, current, parent;
	int pos=0;
	
	newnode=(ThreadBinaryTree)malloc(sizeof(ThreadNode));
	newnode->value=value;					/* ------------------------------------ */
	newnode->left_thread=0;					/* |  0  |  NULL |  value  | NULL | 0 | */
	newnode->right_thread=0;				/* ------------------------------------ */
	newnode->left_Node=NULL;
	newnode->right_Node=NULL;
	
	

	previous=(ThreadBinaryTree)malloc(sizeof(ThreadNode));
	
#if 0 // 1: option memcpy API	
	memcpy(previous, newnode, sizeof(ThreadNode));
else
	previous->value=value;					/* ------------------------------------ */
	previous->left_thread=0;					/* |  0  |  NULL |  value  | NULL | 0 | */
	previous->right_thread=0;				/* ------------------------------------ */
	previous->left_Node=NULL;
	previous->right_Node=NULL;
#endif

	if(rootNode==NULL)
	{
		rootNode=newnode;
		rootNode->left_Node=rootNode;		/* ------------------------------------ */
		rootNode->right_Node=NULL;			/* | 0 | rootNode |	newnode | NULL | 1 |*/
		rootNode->left_thread=0;			/* ------------------------------------ */
		rootNode->right_thread=1; // read pointer
		return;
	}

	current=rootNode->right_Node;
	if(current == NULL)
	{
		rootNode->right_Node=newnode;
		newnode->left_Node=rootNode;
		newnode->right_Node=rootNode;
		return;
	}
	
	parent=rootNode;
	while(current!=NULL){
		if(current->value >value){
			if(pos!=-1){
				pos=-1;
				previous=parent;
			}
			parent=current;
			if(current->left_thread == 1)
				current=current->left_Node;
			else
				current=NULL;
		}
		else{
			if(pos!=1){
				pos=1;
				previous=parent;
			}
			parent=current;
			if(current->right_thread == 1)
				current=current->right_Node;
			else
				current=NULL;
		}
	}
	if(parent->value > value){
		parent->left_thread=1;
		parent->left_Node=newnode;
		newnode->left_Node=previous;
		newnode->right_Node=parent;
	}
	else{
		parent->right_thread=1;
		parent->right_Node=newnode;
		newnode->left_Node=parent;
		newnode->right_Node=previous;
	}
	return;
}

void trace()
{
	ThreadBinaryTree tempNode;
	tempNode=rootNode;
	do{
		if(tempNode->right_thread == 0)
			tempNode=tempNode->right_Node;
		else{
			tempNode=tempNode->right_Node;
			while(tempNode->left_thread!=0)
				tempNode=tempNode->left_Node;
		}
		if(tempNode!=rootNode)
			printf("[%d]\n",tempNode->value);
	}while(tempNode!=rootNode); 
}

ThreadBinaryTree insucc(ThreadBinaryTree tree)
{
	ThreadBinaryTree temp;
	temp=tree->right_Node;
	if(!tree->right_thread)
		while(!temp->left_thread)
			temp=temp->left_Node;
	return temp;
}

void tinorder(ThreadBinaryTree tree)	// Time Complexity = O(n)
{
	ThreadBinaryTree temp = tree;
	for(;;){
		temp=insucc(temp);
		if(temp == tree) break;
		printf("[%2d]\n", temp->value);
	}
	
}

// Insert a Node in Binary Threaded Tree
ThreadBinaryTree insert(ThreadBinaryTree root, int ikey)
{
    // Searching for a Node with given value
    ThreadBinaryTree ptr = root;
    ThreadBinaryTree par = NULL; // Parent of key to be inserted
    while (ptr != NULL)
    {
        // If key already exists, return
        if (ikey == (ptr->info))
        {
            printf("Duplicate Key !\n");
            return root;
        }
 
        par = ptr; // Update parent pointer
 
        // Moving on left subtree.
        if (ikey < ptr->info)
        {
            if (ptr -> lthread == false)
                ptr = ptr -> left;
            else
                break;
        }
 
        // Moving on right subtree.
        else
        {
            if (ptr->rthread == false)
                ptr = ptr -> right;
            else
                break;
        }
    }
 
    // Create a new node
    ThreadBinaryTree tmp = mallic(sizeof(ThreadNode));
    tmp -> info = ikey;
    tmp->left_thread = true;
    tmp->right_thread= true;
 
    if (par == NULL)
    {
        root = tmp;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    else if (ikey < (par -> info))
    {
        tmp -> left = par -> left;
        tmp -> right = par;
        par -> lthread = false;
        par -> left = tmp;
    }
    else
    {
        tmp -> left = par;
        tmp -> right = par -> right;
        par -> rthread = false;
        par -> right = tmp;
    }
 
    return root;
}

int main()
{
	int i, data1[]={0,10,20,30,100,399,453,43,237,373,655}; 	
	for(i=0; i<SIZE; i++)
		add_node_to_tree(data1[i]);
	
	printf("===============================\n");
	printf("example1\n");
	printf("the result of number sorted from smaller to bigger is: \n");
	//trace();
	tinorder(rootNode);
	return 0;
}



 
