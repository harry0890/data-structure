#include <stdio.h> 

#define N 3 

void multiply(int mat1[][N], int mat2[][N], int res[][N]) 
{
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 

			res[i][j] = 0; 

			for (int k = 0; k < N; k++) 
                res[i][j] += mat1[i][k] * mat2[k][j]; 
        } 
    } 
} 

int main(void) 
{
    int mat1[N][N] = { {1, 1, 1}, 
                       {2, 2, 2}, 
                       {3, 3, 3} }; 
  
    int mat2[N][N] = { {1, 1, 1}, 
                       {2, 2, 2}, 
                       {3, 3, 3} };
  
    int res[N][N]; // To store result

	multiply(mat1, mat2, res); 
  
    printf("Result matrix is \n"); 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
           printf("%02d ", res[i][j]); 
        printf("\n"); 
    } 
  
    return 0; 
} 
