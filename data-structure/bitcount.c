#include <stdio.h>

int bitcount(unsigned int a)
{
	unsigned int cnt = 0;
	while(a != 0) 
	{
		if(a & 0x01) // n += (a & 1);
			cnt++;
		a = a >> 1;
	}
	return cnt;
}


int main(void)
{
	unsigned int a = 1023;
	printf("bit count = %d\n", bitcount(a));

	return 0;
}
