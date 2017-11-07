#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define MAX 10 
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

int partition(int[], int, int); 
void quickSort(int[], int, int); 

int main(void) 
{ 
    srand(time(NULL)); 
    int number[MAX] = {0}; 

    printf("排序前："); 
    int i;
    for(i = 0; i < MAX; i++) { 
        number[i] = rand() % 100; 
        printf("%d ", number[i]); 
    } 

    quickSort(number, 0, MAX-1); 

    printf("\n排序後："); 
    for(i = 0; i < MAX; i++) 
        printf("%d ", number[i]); 
    
    printf("\n"); 

    return 0; 
} 

int partition(int number[], int left, int right) { 
    int i = left - 1;                                         // 2
    int j;
    for(j = left; j < right; j++) {       // j=0; j<9         
        if(number[j] <= number[right]) {  // n[8] <= n[9]     // 8-9
            i++; 						  // i=1              // 7
            SWAP(number[i], number[j]);   // n[1]-n[8]        // 7-8
        } 
    } 

    SWAP(number[i+1], number[right]);     // n[1+1]-n[9]      // 7+1-9
	 
    return i+1; // return = 2  8
} 

void quickSort(int number[], int left, int right) { 
    if(left < right) { 
        int q = partition(number, left, right); 
        
        quickSort(number, left, q-1); 
        quickSort(number, q+1, right); 
    } 
} 
