#include <stdio.h>

/*

sq	1, 4, 9, 16 ...
odd	 +3 +5 +7
sum = 1+4+9+16 = 30
*/

int square_sum(int n)
{
	int i;
	int sum = 1, sq = 1, odd = 3;
	for(i = 0; i < n - 1; i++) { // add 3 times
		sq = sq + odd;
		sum = sum + sq;
		odd = odd + 2;
	}

	return sum;
}

int main(void)
{
	printf("%d\n",square_sum(4));

	return 0;
}
