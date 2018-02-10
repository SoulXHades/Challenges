/*
Write a function findAr1D() that returns the subscript of the first appearance of a
target number in an array. For example, if ar = { 3,6,9,4,7,8 }, then findAr1D(6,ar,3) will return 0
where 6 is the size of the array and 3 is the number to be found, and findAr1D(6,ar,9) will return
2. If the required number is not in the array, the function will return -1. The function prototype is
given as follows:
int findAr1D(int size, int ar[ ], int target);

Write a C program to test the function.
Some sample input and output sessions are given below:

(1) Test Case 1:
Enter array size:
5
Enter 5 data:
1 2 3 4 5
Enter the target number:
3
findAr1D(): 2

(2) Test Case 2:
Enter array size:
1
Enter 1 data:
5
Enter the target number:
5
findAr1D(): 0

(3) Test Case 3:
Enter array size:
Enter 7 data:
1 3 5 7 9 11 15
Enter the target number:
15
findAr1D(): 6

(4) Test Case 4:
Enter array size:
Enter 7 data:
1 3 5 7 9 11 15
Enter the target number:
findAr1D(): Not found
*/

#include <stdio.h>
#define INIT_VALUE -1000
int findAr1D(int size, int ar[], int target);
int main()
{
 int ar[20];
 int size, i, target, result = INIT_VALUE;

 printf("Enter array size: \n");
 scanf("%d", &size);
 printf("Enter %d data: \n", size);
 for (i=0; i<=size-1; i++)
 scanf("%d", &ar[i]);
 printf("Enter the target number: \n");
 scanf("%d", &target);
 result = findAr1D(size, ar, target);
 if (result == -1)
 printf("findAr1D(): Not found\n");
 else
 printf("findAr1D(): %d", result);
 return 0;
 }
int findAr1D(int size, int ar[], int target)
{
 int i;

 for(i=0; i<size; i++)
 {
     if(ar[i] == target)
        return i;
 }

 return -1;
}
