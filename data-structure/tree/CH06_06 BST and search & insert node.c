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

    parent = ptr;   // �qptr�}�l��
    *pos = 0;
    while (ptr != 0)
    {
        if (ptr->data == value)  // ���ؼ�
            return parent;          // �^�Ǧ��`�I�����`�I
        else
        {
            parent = ptr;
            if (ptr->data > value)
            {
                *pos = -1;          // ptr�bparent���l��
                ptr = ptr->left; // ������
            }
            else
            {
                *pos = 1;           // ptr�bparent�k�l��
                ptr = ptr->right;// ���k��
            }
        }
    }
    return NULL;   // �䤣��
}



btree delete_node(btree root, int value)
{
    btree parent;
    btree ptr;
    btree next;
    int pos;

    parent = find_parent(root, value, &pos); // �qroot�}�l,��value�����`�I
    if (parent != NULL) // �����, �ǳƧR��
    {
        switch(pos) // �P�_�ثe�`�I�b���`�I����Υk��
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
        if (ptr->left == NULL)     // ���p1: �`�I�S�����l��
        {
            if (parent == ptr)  // �p�G�n�R���O�ڸ`�I
                root = root->right;
            else                // ��L
            {
                if (pos == 1)
                    //�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I���k�`�I
                    parent->right = ptr->right;
                else
                    //�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I���k�`�I
                    parent->left = ptr->right;
            }
            free(ptr);
        }
        else if (ptr->right == NULL)   // ���p2: �`�I�S���k�l��
        {
            if (parent == ptr) // �p�G�n�R���O�ڸ`�I
                root = root->left;
            else
            {
                if (pos == 1)
                    //�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I�����`�I
                    parent->right = ptr->left;
                else
                    //�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I�����`�I
                    parent->left = ptr->left;
            }
            free(ptr);
        }
        else                        // ���p3: �`�I�����k�l��
        {
            parent = ptr;
            next = ptr->left;       // ����N�Inext, �qptr����}�l��
            while (next->right != 0)// �����l�`�I���k�l���̤j�ȷ���N�I
            {
                parent = next;      // parent��next�����`�I
                next = next->right;
            }
            ptr->data = next->data;     // ���N!!
            parent->right = next->left; // ¶�Lnext�`�I
            free(next); // �R��next (�`�N: ���O�R��ptr)
        }
    }
    return root;    // �^�Ǧ���
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










