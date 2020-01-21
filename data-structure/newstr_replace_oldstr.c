#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replaceWord(const char *s, const char *oldW, 
                                 const char *newW) 
{ 
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
  
    // Counting the number of times old word occur in the string 
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;
            i += oldWlen - 1; // Jumping to index after the old word. 
        } 
    } 

    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1); // Making new string of enough length 
  
    i = 0; 
    while (*s) {
        if (strstr(s, oldW) == s) // compare the substring with the result
        { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; 
    return result; 
} 
 
int main() 
{ 
    char str[] = "xxforxx"; 
    char c[] = "xx"; 
    char d[] = "Geeks"; 
  
    char *result = NULL; 
  
    // oldW string 
    printf("Old string: %s\n", str); 
  
    result = replaceWord(str, c, d); 
    printf("New String: %s\n", result); 
  
    free(result); 
    return 0; 
} 
