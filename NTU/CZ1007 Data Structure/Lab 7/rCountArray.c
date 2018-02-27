/*
Write a recursive C function rCountArray() that returns the number of times
the integer a appears in the array which has n integers in it.
Assume that n is greater than or equal to 1.
The function prototype is:

    int rCountArray(int array[], int n, int a);

Write a C program to test the function.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter array size:
10
Enter 10 numbers:
1 2 3 4 5 5 6 7 8 9
Enter the target number:
5
rCountArray(): 2

(2) Test Case 2:
Enter array size:
5
Enter 5 numbers:
1 2 3 4 5
Enter the target number:
8
rCountArray(): 0

(3) Test Case 3:
Enter array size:
1
Enter 1 numbers:
5
Enter the target number:
5
rCountArray(): 1

(4) Test Case 4:
Enter array size:
7
Enter 5 numbers:
1 2 3 3 4 3 3
Enter the target number:
3
rCountArray(): 4
*/

#include <stdio.h>
#define SIZE 20
int rCountArray(int array[], int n, int a);
int main()
{
   int array[SIZE];
   int index, count, target, size;

   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d numbers: \n", size);
   for (index = 0; index < size; index++)
      scanf("%d", &array[index]);
   printf("Enter the target number: \n");
   scanf("%d", &target);
   count = rCountArray(array, size, target);
   printf("rCountArray(): %d\n", count);
   return 0;
}
int rCountArray(int array[], int n, int a)
{
   if(n == 1)
   {
       if(array[0] == a)
        return 1;
       else
        return 0;
   }
   else
    return rCountArray(array, n-1, a) + ((array[n-1] == a) ? 1 : 0);
}
