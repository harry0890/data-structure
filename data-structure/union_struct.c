// mtk

#include <stdio.h> 

struct S
{
	char c;
	int a;
	struct S *p;
	union
	{
		short b;
		unsigned int d;
	};
};



int main()  
{ 
#if 0
   unsigned int i = 1; 
   char *c = (char*)&i; 
   
   if (*c)     
       printf("Little endian"); 
   else
       printf("Big endian"); 

   return 0; 
#endif

	printf("%d\n", sizeof(struct S));
} 


