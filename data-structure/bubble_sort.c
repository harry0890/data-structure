#include <stdio.h>
#include <stdbool.h>

inline void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

// argument use variable to receive
void bubble1(int data[], int size)
{
	int i, j;

	for(i = 0; i < size; i++) {
		for(j = 0; j < size - i -1; j++) {
			if(data[j] > data[j+1])
				swap(&data[j], &data[j+1]);
		}
	}
}

// argument use pointer to receive
void bubble2(int *data, int size)
{
	int i, j;

	for(i = 0; i < size; i++) {
		for(j = 0; j < size - i - i; j++) {
			if( *(data + j) > *(data + j + 1) )
				swap(&data[j], &data[j+1]);
		}
	}

}

// optimize code flow using bool flag
void bubble3(int data[], int size)
{
	int i, j;
	bool swapped;

	for(i = 0; i < size; i++) {
		swapped = false;
		for(j = 0; j < size - i -1; j++) {
			if(data[j] >  data[j+1])
				swap(&data[j], &data[j+1]);
			swapped = true;
		}
		if(swapped == false) // i only run to i = 0, 1. 2; no need to run i = 3, 4,
			break;
	}
}

int main(void)
{
	int input[5] = {50, 20, 30, 10, 40};
	int i;

	bubble3(input, 5);

	for(i = 0; i < 5; i++)
		printf("%d ", input[i]);
	printf("\n");	

	return 0;
}
