#include <stdio.h>

#define offsetof(TYPE, MEMBER)     ((size_t) &((TYPE *)0)->MEMBER)
#define my_offsetof(TYPE, MEMBER)  ((size_t) &((TYPE *)1000)->MEMBER)

struct MY_DATA {
	int Data_A;
	int Data_B;
	int Data_C;
	struct MY_DATA *next;
};

typedef struct MY_DATA AAA;

int main(void)
{
	puts("----- offsetof -----");
	printf("---- next  =  %ld-----\n", offsetof(struct MY_DATA, next));
	printf("---- Data_A =  %ld -----\n", offsetof(struct MY_DATA,Data_A));
	printf("---- Data_B =  %ld -----\n", offsetof(struct MY_DATA,Data_B));
	printf("---- Data_C =  %ld -----\n", offsetof(struct MY_DATA,Data_C));	
	puts("\n---- my_offsetof----");
	printf("---- next  =  %ld----\n", my_offsetof(struct MY_DATA, next));
	printf("MY_DATA sizeof = %ld\n", sizeof(struct MY_DATA));
}
