#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

int partition(int *, int, int);
void quicksort(int *, int, int);

int main(void)
{
	srand(time(NULL));
	int array[MAX] = {0};
	int i;
	
	printf("Before sorting:\n");
	for(i=0; i<MAX; i++){
		array[i] = rand() % 100; // // get random number 0~100
		printf("[%2d] ", array[i]);
	}
	printf("\n");
	
	printf("\nAfter sorting:\n");
	quicksort(array, 0, MAX-1);
	
	for(i=0; i<MAX; i++){
		printf("[%2d] ", array[i]);
	}
	printf("\n");
	return 0;
}

int partition(int *array, int front, int end)
{
	int pivot = array[end];
	int i = front-1;
	int j;
	for(j=front; j<end; j++){
		if(array[j] < pivot){
			i++;
			SWAP(array[i],array[j]); // i change with smaller than pivot;
		}	
	}
	i++;
	SWAP(array[i],array[end]); // i change with pivot of sub-array
	return i;
}

void quicksort(int *array, int front, int end)
{
	int pivot;
	if(front < end){
		pivot = partition(array, front, end);
		quicksort(array, front, pivot-1);
		quicksort(array, pivot+1, end);
	}
}







