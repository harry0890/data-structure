#include <stdio.h>

#define offsetof(TYPE, MEMBER)     ((size_t) &((TYPE *)0)->MEMBER)
#define my_offsetof(TYPE, MEMBER)  ((size_t) &((TYPE *)1000)->MEMBER)

struct MY_DATA {
	int Data_A; // offset = 0
	int Data_B; // offset = 4
	int Data_C; // offset = 8
	struct MY_DATA *next; // offset = 16 ( 8 + 8(x86 pointer))
};

typedef struct MY_DATA AAA;

int main(void)
{
	int *ptr;

	puts("----- offsetof -----");
	printf("---- next  =  %ld-----\n", offsetof(struct MY_DATA, next));
	printf("---- Data_A =  %ld -----\n", offsetof(struct MY_DATA,Data_A));
	printf("---- Data_B =  %ld -----\n", offsetof(struct MY_DATA,Data_B));
	printf("---- Data_C =  %ld -----\n", offsetof(struct MY_DATA,Data_C));	
	puts("\n---- my_offsetof----");
	printf("---- next  =  %ld----\n", my_offsetof(struct MY_DATA, next));
	printf("MY_DATA sizeof = %ld\n", sizeof(struct MY_DATA)); // 4*3 + 4*3 = 24
	
	printf("ptr = %ld\n", sizeof(ptr));  // pointer type = 8
	printf("ptr type = %ld\n", sizeof(*ptr)); // pointer to int type = 4
}
