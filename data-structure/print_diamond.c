#include<stdio.h> 
  
// Prints diamond pattern with 2n rows 
void printDiamond(int n) 
{ 
    int space = n - 1; 

    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < space; j++) printf(" ");
        for (int j = 0; j <= i; j++)    printf("* "); 
        printf("\n"); 
        space--; 
    } 
  
    // Repeat again in and reverse order 
    space = 0; 

    for (int i = n; i > 0; i--) 
    { 
        for (int j = 0; j < space; j++) printf(" "); 
        for (int j = 0; j < i; j++)     printf("* ");
        printf("\n"); 
        space++;
    } 
} 

int main() 
{ 
    printDiamond(3); 
    return 0; 
} 
