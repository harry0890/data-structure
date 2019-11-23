#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *RemovePrefix(const char *s, const char *search) 
{
    int i = 0;
    int searchlen = strlen(search);
    char *result = (char *)malloc(strlen(s) * sizeof(char));

    while (*s) {
        if (strstr(s, search) == s)
            s += searchlen;
        else
            result[i++] = *s++;
	}
    result[i] = '\0';
    return result; 
}

int main(void)
{
    /************ test case**********/ 
    char str[] = "8591abcdefg";
    //char str[] = "8888dfs1sde";
    //char str[] = "85919293949";
    //char str[] = "8591ds1fe5d3sa";
    //char str[] = "8558f1s1d1f1a1";
    /********************************/

    char prefix[] = "8591";
    char *result = NULL;

    printf("Old string: %s\n", str); 
  
    result = RemovePrefix(str, prefix); 
    printf("New String: %s\n", result); 
  
    free(result); 
    return 0; 
} 
