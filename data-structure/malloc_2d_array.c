#include <stdio.h> 
#include <stdlib.h> 

#define r 3
#define c 4
  
int main() 
{
    int *arr[r]; 
    int count = 0;
   
	for (int i = 0; i < r; i++) 
        arr[i] = (int *)malloc(c * sizeof(int)); 
  
    // Note that arr[i][j] is same as *(*(arr+i)+j) 
 
    
	for (int i = 0; i <  r; i++) 
      for (int j = 0; j < c; j++) 
         arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count 
  

    // print
    for (int i = 0; i <  r; i++) {
      for (int j = 0; j < c; j++) 
         printf("%2d ", arr[i][j]);
	  printf("\n"); 
    }

    // free
	for (int i = 0; i < r; i++) 
        free(arr[i]);
    return 0; 
} 


 
