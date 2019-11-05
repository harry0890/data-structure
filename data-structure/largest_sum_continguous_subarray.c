#include <stdio.h> 
#include <stdlib.h> 
  
int maxSubArraySum(int a[], int size) 
{ 
    int max = INT_MIN;
	int tmp = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        tmp = tmp + a[i];
        if (tmp > max) 
            max = tmp; 
  
        if (tmp < 0)
            tmp = 0; 
    } 
    return max; 
} 

int main(void) 
{ 
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum = maxSubArraySum(a, n);
 
    printf("Maximum contiguous sum is %d \n", max_sum); 
    return 0; 
}
