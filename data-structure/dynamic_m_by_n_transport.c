#include <stdio.h> 
#include <stdlib.h>
#define M 3 
#define N 4 

void transpose(int **A, int **B) 
{
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            B[i][j] = A[j][i]; 
} 

void Print(int **arr, int m, int n)
{
    printf("Result matrix is \n"); 
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) 
        	printf("%2d ", arr[i][j]); 
        printf("\n"); 
    } 	
}

int main(void) 
{ 	
	int cnt;
	int **A = (int **)malloc(M * sizeof(int *));
	int **B = (int **)malloc(N * sizeof(int *));

	for(int i = 0; i < M; i++)
		A[i] = (int *)malloc(N * sizeof(int)); 
	for(int i = 0; i < N; i++)
		B[i] = (int *)malloc(M * sizeof(int));

	cnt = 0;
	
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			A[i][j] = ++cnt;
	Print(A, M, N);
	
    transpose(A, B);
 	
	printf("After transport \n"); 
    Print(B, N, M); 
    return 0; 
}
