#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int data;	
	struct tree *left, *right;
};
typedef struct tree node;
typedef node *btree;

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

/* 
btree search(btree ptr, int val, int *pos)
{
	*pos = 0;
	
	while(1)
	{
		if(ptr==NULL)
			return NULL;
		if(ptr->data==val)
			return ptr;
		else if(ptr->data > val){
			 *pos = -1;
			 ptr=ptr->left;
		}
		else{
			*pos = 1;
			ptr=ptr->right;
		}

	}
}
*/

btree find_parent(btree ptr, int value, int *pos)
{
    btree parent;

    parent = ptr;   // 從ptr開始找
    *pos = 0;
    while (ptr != 0)
    {
        if (ptr->data == value)  // 找到目標
            return parent;          // 回傳此節點之父節點
        else
        {
            parent = ptr;
            if (ptr->data > value)
            {
                *pos = -1;          // ptr在parent左子樹
                ptr = ptr->left; // 往左找
            }
            else
            {
                *pos = 1;           // ptr在parent右子樹
                ptr = ptr->right;// 往右找
            }
        }
    }
    return NULL;   // 找不到
}



btree delete_node(btree root, int value)
{
    btree parent;
    btree ptr;
    btree next;
    int pos;

    parent = find_parent(root, value, &pos); // 從root開始,找value之父節點
    if (parent != NULL) // 有找到, 準備刪除
    {
        switch(pos) // 判斷目前節點在父節點左邊或右邊
        {
            case -1:
                ptr = parent->left;
                break;
            case 1:
                ptr = parent->right;
                break;
            case 0:
                ptr = parent;
                break;
        }
        if (ptr->left == NULL)     // 情況1: 節點沒有左子樹
        {
            if (parent == ptr)  // 如果要刪的是根節點
                root = root->right;
            else                // 其他
            {
                if (pos == 1)
                    //要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的右節點
                    parent->right = ptr->right;
                else
                    //要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的右節點
                    parent->left = ptr->right;
            }
            free(ptr);
        }
        else if (ptr->right == NULL)   // 情況2: 節點沒有右子樹
        {
            if (parent == ptr) // 如果要刪的是根節點
                root = root->left;
            else
            {
                if (pos == 1)
                    //要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的左節點
                    parent->right = ptr->left;
                else
                    //要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的左節點
                    parent->left = ptr->left;
            }
            free(ptr);
        }
        else                        // 情況3: 節點有左右子樹
        {
            parent = ptr;
            next = ptr->left;       // 找取代點next, 從ptr左邊開始找
            while (next->right != 0)// 往左子節點之右子樹找最大值當取代點
            {
                parent = next;      // parent為next之父節點
                next = next->right;
            }
            ptr->data = next->data;     // 取代!!
            parent->right = next->left; // 繞過next節點
            free(next); // 刪除next (注意: 不是刪除ptr)
        }
    }
    return root;    // 回傳此樹
}


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
	int data[]={7,1,4,2,8,13,12,11,15,9,5}; 
	int i,input1,input2,pos=0;

	btree ptr=NULL;
	
	for(i=0; i<11; i++){
		printf(" [%2d]",data[i]);
		ptr=create_btree(ptr,data[i]);
	}
	printf("\n Please Enter a add value\n");
	scanf("%d",&input1);
	
	if((find_parent(ptr,input1,&pos)) != NULL)
		printf("Binary Tree has this node: %d\n",input1);
	else
	{
		ptr=create_btree(ptr,input1);
		inorder(ptr);
	}
	printf("\n=================================\n");
	printf("\n Please Enter a del value\n");
	scanf("%d",&input2);
	

	ptr=delete_node(ptr, input2);
	inorder(ptr);
	
	return 0;	
} 










