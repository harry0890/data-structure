#include <stdio.h>

/*
	1^2 = 1
	2^2 = 2+2 = 4
	3^2 = 3+3+3 = 9
	4^2 = 4+4+4+4 = 16
*/

int square(int n)
{
	n = abs(n);
	int i, sum = 0;
	for(i = 0; i < n; i++)
	   sum = sum + n;
	return sum;
}	

int main(void)
{
	printf("%d\n", square(8));

	return 0;
}
