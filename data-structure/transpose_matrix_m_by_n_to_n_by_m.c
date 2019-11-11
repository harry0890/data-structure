#include <stdio.h> 

#define M 3 
#define N 4 

void transpose(int A[][N], int B[][M]) 
{
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            B[i][j] = A[j][i]; 
} 

void Print(int B[][M])
{
    printf("Result matrix is \n"); 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < M; j++) 
        	printf("%d ", B[i][j]); 
        printf("\n"); 
    } 	
}

int main() 
{ 
    int A[M][N] = { {1, 1, 1, 1}, 
                    {2, 2, 2, 2}, 
                    {3, 3, 3, 3}}; 
    int B[N][M]; 

    transpose(A, B);
  
    Print(B); 
    return 0; 
} 
