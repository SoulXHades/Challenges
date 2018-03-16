/*
Write a C function findMinMax1D() that takes in an one-dimensional array of
integers ar and size as parameters. The function finds the minimum and maximum numbers of the array.
The function returns the minimum and maximum numbers through the pointer parameters min and max
via call by reference. The function prototype is given as follows:

void findMinMax1D(int ar[], int size, int *min, int *max);

Write a C program to test the function.

Some sample input and output sessions are given below:
(1) Test Case 1:
Enter array size:
5
Enter 5 data:
1 2 3 5 6
min = 1; max = 6

(2) Test Case 2:
Enter array size:
1
Enter 1 data:
1
min = 1; max = 1
*/

#include <stdio.h>
void findMinMax1D(int ar[], int size, int *min, int *max);
int main()
{
    int ar[40];
    int i, size;
    int min, max;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
      scanf("%d", &ar[i]);
    findMinMax1D(ar, size, &min, &max);
    printf("min = %d; max = %d\n", min, max);
    return 0;
}
void findMinMax1D(int ar[], int size, int *min, int *max)
{
   int i;

   *max = ar[0];
   *min = ar[0];

   for(i=0; i<size; i++)
   {
       if(ar[i] > *max)
        *max = ar[i];
       else if(ar[i] < *min)
        *min = ar[i];
   }
}
