#include <stdio.h>
#include <string.h>

inline void swap(char *a, char *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main(void)
{
	int i = 0, j = 0;
	char str1[8] = "hello";
	int size = strlen(str1);

	for(i = 0; i < size/2; i++)
		swap(&str1[i], &str1[4-i]);

	while(str1[j] != '\0') {
		printf("%c", str1[j]);
		j++;
	}

	printf("\n");

	return 0;
}
