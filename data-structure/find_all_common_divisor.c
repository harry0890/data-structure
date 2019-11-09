#include <stdio.h> 
#include <math.h>

int gcd(int a, int b)
{
	return (a % b == 0) ? b : gcd(b, a%b);
}

void print_all_common_Divisors(int a, int b) 
{
	int max = gcd(a, b);

    for (int i = 1; i <= sqrt(max); i++) 
    {
		if(max % i == 0)
            printf("%d %d ", i, max/i);
    }   
} 

int main(void) 
{ 
    printf("The common divisors of 56 and 42 are: \n"); 
    print_all_common_Divisors(56, 42); 
    return 0; 
} 
