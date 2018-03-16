/*
Write a C function findMinMax2D() that takes a 5x5 two-dimensional array of
integers ar as a parameter. The function returns the minimum and maximum numbers of the array to the
caller through the two pointer parameters min and max respectively. The function prototype is given as
follows:

void findMinMax2D(int ar[SIZE][SIZE], int *min, int *max);

Write a C program to test the function.

Some sample input and output sessions are given below:
(1) Test Case 1:
Enter the matrix data (5x5):
1 2 3 4 5
2 3 4 5 6
4 5 6 7 8
5 4 23 1 2
1 2 3 4 5
min = 1
max = 23

(2) Test Case 2:
Enter the matrix data (5x5):
1 2 3 4 5
2 3 4 5 6
4 5 6 7 8
5 4 23 1 2
1 2 3 4 5
min = 1
max = 23
*/

#include <stdio.h>
#define SIZE 5
void findMinMax2D(int ar[SIZE][SIZE], int *min, int *max);
int main()
{
    int A[5][5];
    int i,j,min,max;
    printf("Enter the matrix data (%dx%d): \n", SIZE, SIZE);
    for (i=0; i<5; i++)
        for (j=0; j<5; j++)
         scanf("%d", &A[i][j]);
    findMinMax2D(A, &min, &max);
    printf("min = %d\nmax = %d", min, max);
    return 0;
}
void findMinMax2D(int ar[SIZE][SIZE], int *min, int *max)
{
   int i, j;

   *max = ar[1][1];
   *min = ar[1][1];

   for(i=0; i<SIZE; i++)
   {
       for(j=0; j<SIZE; j++)
       {
           if(ar[i][j] > *max)
            *max = ar[i][j];
           else if(ar[i][j] < *min)
            *min = ar[i][j];
       }
   }
}
