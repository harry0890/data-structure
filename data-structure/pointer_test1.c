#include <stdio.h>


int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	int *p = (int *)&a;
	int *t = a;

	int ival = 10;
	int *ptr1;
	int **ptr2;
	ptr1 = &ival;
	ptr2 = &ptr1;

	printf("*(p-1) = %d\n", *(p-1));
	printf("*(t-1) = %d\n", *(t-1));
	printf("%d\n", **ptr2);

	return 0;
}
