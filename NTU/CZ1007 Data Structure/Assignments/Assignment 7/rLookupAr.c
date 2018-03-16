/*
Write a recursive C function called rLookupAr() takes in three parameters, array, size and target,
and returns the subscript of the last appearance of a number in the array.
The parameter size indicates the size of the array.
For example, if array is {2,1,3,2,4} and target is 3, it will return 2.
With the same array, if target is 2, it will return 3.
If the required number is not in the array, the function will return –1.
The function prototype is given below:

    int rLookupAr(int array[], int size, int target);

Write a C program to test the function.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter array size:
5
Enter 5 numbers:
2 1 3 2 4
Enter the target number:
2
rLookupAr(): 3

(2) Test Case 2:
Enter array size:
5
Enter 5 numbers:
2 1 3 2 4
Enter the target number:
5
rLookupAr(): -1

(3) Test Case 3:
Enter array size:
7
Enter 7 numbers:
7 9 10 1 2 3 4
Enter the target number:
3
rLookupAr(): 5

(4) Test Case 4:
Enter array size:
10
Enter 10 numbers:
7 9 1 1 2 3 4 1 2 3
Enter the target number:
1
rLookupAr(): 7
*/

#include <stdio.h>
int rLookupAr(int array[], int size, int target);
int main()
{
   int numArray[80];
   int target, i, size;

   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d numbers: \n", size);
   for (i=0; i < size; i++)
      scanf("%d", &numArray[i]);
   printf("Enter the target number: \n");
   scanf("%d", &target);
   printf("rLookupAr(): %d", rLookupAr(numArray, size, target));
   return 0;
}
int rLookupAr(int array[], int size, int target)
{
   if(size == 0)
    return -1;
   else
   {
       if(array[size-1] == target)
        return size-1;

       rLookupAr(array, size-1, target);
   }
}
