#include <stdio.h>

// Method 1; T = O(n^2)
int sum_1(int n)
{
	int sum = 0, total = 0, k = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < (n - k); j++)
			sum = sum + (n - k);
		total += sum;
		sum = 0;
		k++;
	}
	return total;
}

// Method 2; T = O(n) 
int sum_2(int n)
{
	int sum = 0, total = 0, i = 0;
	while(i < n) {
		sum = sum + n;
		i++;
		if(i == n) {
			total += sum;
			sum = 0;
			n--;
			i = 0;
		}
	}
	return total;
}

int main(void)
{
	printf("%d\n", sum_2(10));	
	return 0;
}
