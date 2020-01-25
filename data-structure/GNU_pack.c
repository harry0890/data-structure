#include <stdio.h>
#include <stdbool.h>
struct student1
{
    char name[7];
    int id;
    char subject[5];
} __attribute__ ((aligned(4)));

struct student2
{
    char name[7];
    int id;
    char subject[5];
} __attribute__ ((packed));


int main(void)
{
	printf("%d\n", sizeof(struct student1));
	printf("%d\n", sizeof(struct student2));
	
	return 0;
}
