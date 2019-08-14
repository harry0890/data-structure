#include <stdio.h>
#include <math.h>


/* Recursion method */
// Time Complexity: O(2^n)
// Space Complexity: O(n)
int fib_1(int n)
{
    if(n <= 1)
	return n;
    else
	return fib_1(n-1) + fib_1(n-2);
}


/* DP method */
// Time Complexity: O(n)
// Space Complexity: O(1) ~ O(n)
int fib_2(int n)
{
    int i, fib[n+2];

    fib[0] = 0; // fib[0] [1] [2] [3] [4] [5] [6]
    fib[1] = 1; //     0   1   1   2   3   5   8

    for(i = 2; i<=n; i++)
	fib[i] = fib[i-1] + fib[i-2];

    return fib[n];
}

/* Space Optimized Method */
int fib_3(int n)
{
    int a = 0, b = 1, c, i;

    for(i = 2; i<=n; i++){
	c = a + b;
	a = b;
	b = c;
    }
    return c;
}

/* math formula method*/
int fib_4(int n) { 
    double phi = (1 + sqrt(5)) / 2; 
    return round(pow(phi, n) / sqrt(5)); 
} 

int main(void)
{
    printf("result = %d\n", fib_1(0));
    printf("result = %d\n", fib_2(6));
    printf("result = %d\n", fib_3(6));
    printf("result = %d\n", fib_4(6));
}
