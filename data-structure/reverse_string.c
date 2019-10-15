#include <stdio.h>
#include <string.h>

#define XOR
#define SIZE 5
#define SWAP(a,b,t) do{ (t) = (a); \
			(a) = (b); \
			(b) = (t); \
		    }while(0)

#define BITWISE_SWAP(a,b) {a ^= b, b ^= a, a ^= b;}

void reverse(char *p_str)
{
    int i;
    int n = SIZE - 1;
    int m = 0;
    char temp;

    for(i=0; i<SIZE; i++){
	m = n - i; // 4, 3, 2
	if(i != m)
	    SWAP(*(p_str+i), *(p_str+m), temp); // (0,4), (1,3)
	else
	    break;
    }
}

void reverse2(char *ptr)
{
    int i;
    int len = strlen(ptr);
    int n = len/2;
    char temp;

    for(i=0; i<n; i++){
#ifdef XOR
	if(i == 2)
	    break;
	else
	    BITWISE_SWAP(*(ptr+i), *(ptr+(SIZE-1-i)) );
#else
	SWAP(*(ptr+i), *(ptr+(SIZE-1-i)), temp);
#endif
    }
}

int main(void)
{
    int i;
    char str[SIZE] = "apple"; // elppa

    reverse2(str);

    for(i=0; i<SIZE; i++)
	printf("%c",str[i]);
    printf("\n");
    
    return 0;
}
