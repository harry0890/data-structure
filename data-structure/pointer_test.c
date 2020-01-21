#include <stdio.h>
#include <stdlib.h>

int main(void)
{
/* 
	int arr[] = {10, 20, 30, 40, 50};
	int *ptr = arr;
	
	*ptr++;
	//printf("%d\n", *ptr++);
	printf("%d\n", ++*(ptr)); // 11
	printf("%d\n", *ptr++);
	printf("%d\n", *ptr);
	*++ptr;
	printf("%d\n", *ptr);
	*(++ptr);
	printf("%d\n", *ptr);

	//printf("%d\n", ++*ptr);
	printf("%d\n", ++(*ptr));
	printf("%d\n", *ptr);
*/

	int A=2 , AA=0;
	int B=2 , BB=0;

	AA = (A++) + (A++);
	BB = (++B) + (B++);
 
	printf("AA = %d, BB = %d, A = %d, B = %d\n",AA ,BB, A, B);

	return 0;	
} 
