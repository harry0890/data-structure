#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATALEN 9
#define BTREELEN 16

void Btree_create(int *btree,int *data,int length)
{
	int i,level;
	
	for(i=1; i<length; i++) // 1
	{
		for(level=1; btree[level]!=0;) // compare the root
		{
			if(data[i]>btree[level]) 
				level = level*2 + 1; 
			else
				level = level*2;	 	
		}
		btree[level]=data[i]; 
	}
}
/*
i=1, level=1, btree[1]=data[1]=6

i=2, level=1->2    btree[2]=0, btree[2]=data[2]=3
i=3, level=1->2->5             btree[5]=data[3]=5
i=4, level=1->2->5->10	       btree[10]=data[4]=4
i=5, level=1->3                btree[3]=data[5]=7
i=6, level=1->3->7             btree[7]=data[6]=8
i=7, level=1->3->7->15         btree[15]=data[7]=9
i=8, level=1->2->4             btree[4]=data[8]=2
*/

int main()
{
	int data[]={0,6,3,5,4,7,8,9,2};
	int btree[16]={0};
	int i;
	
	/*before binary tree created */
	printf("Original array: \n");
	for(i=0; i<DATALEN; i++)
		printf("[%2d]",data[i]);
	printf("\n");
	
	Btree_create(btree,data,DATALEN);
	
	
	/*After binary tree created */
	printf("Binary Tree: \n");
	for(i=1; i<BTREELEN; i++)
		printf("[%2d]",btree[i]);
	printf("\n");
	
	
	
	return 0;	
}
