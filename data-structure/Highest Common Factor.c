// C program to find GCD of two numbers 
#include <stdio.h> 
  
// Recursive function to return gcd of a and b 
int gcd(int a, int b) 
{ 
    if (a == 0 || b == 0) 
        return a == 0 ? b : a;
	else if (a == b)
		return a;
 
    return gcd(a % b, b % a);  
} 
  
// Driver program to test above function 
int main() 
{ 
    int a = 98, b = 56; 
    printf("GCD of %d and %d is %d ", a, b, gcd(a, b)); 
    return 0; 
} 
