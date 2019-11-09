#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    if (n <= 1 ) 
		return false;
    
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}


int main(void)
{
	int n = 121;
	if(isPrime(n) == true)
		printf("It's a Prime\n");
	else
		printf("It's not a Prime\n");
	
	return 0;
}
