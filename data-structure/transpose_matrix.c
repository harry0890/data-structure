#include <stdio.h> 
  
#define N 3 

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b; 
}

// In-Place for Square Matrix:
void transpose(int A[][N]) 
{ 
    for (int i = 0; i < N; i++) 
        for (int j = i+1; j < N; j++) 
            swap(&A[i][j], &A[j][i]); 
} 

void Print(int A[][N])
{
    printf("Modified matrix is \n");
	for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
           printf("%d ", A[i][j]); 
        printf("\n"); 
    } 
}

int main(void) 
{ 
    int A[N][N] = { {1, 1, 1}, 
                    {2, 2, 2}, 
                    {3, 3, 3} }; 

    transpose(A); 
  
	Print(A);
  
    return 0; 
} 
