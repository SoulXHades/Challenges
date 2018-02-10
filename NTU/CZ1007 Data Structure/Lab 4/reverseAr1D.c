/*
Write a C function printReverse() that prints an array of integers in reverse order.
For example, if ar[5] = {1,2,3,4,5}, then the output 5, 4, 3, 2, 1 will be printed after applying the function printReverse().
The function prototype is given as follows:

    void printReverse(int ar[], int size);

where size indicates the size of the array.

Write two versions of printReverse().
One version (printReverse1) uses the index notation and the other version (printReverse2)
uses the pointer notation for accessing the element of each index location.

In addition, Write a C function reverseAr1D() that takes in an array of integers ar and an integer size as parameters.
The parameter size indicates the size of the array to be processed.
The function converts the content in the array in reverse order and
passes the array to the calling function via call by reference.

    void reverseAr1D(int ar[ ], int size);

Write a C program to test the functions.

Some sample input and output sessions are given below:

(1)     Test Case 1:
Enter array size:
5
Enter 5 array:
1 2 3 6 7
printReverse1(): 7 6 3 2 1
printReverse2(): 7 6 3 2 1
reverseAr1D(): 7 6 3 2 1

(2)     Test Case 2:
Enter array size:
1
Enter 1 array:
5
printReverse1(): 5
printReverse2(): 5
reverseAr1D(): 5
*/

#include <stdio.h>
void printReverse1(int ar[], int size);
void printReverse2(int ar[], int size);
void reverseAr1D(int ar[], int size);
int main()
{
   int ar[10];
   int size, i;

   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d data: \n", size);
   for (i=0; i <= size-1; i++)
      scanf("%d", &ar[i]);
   printReverse1(ar, size);
   printReverse2(ar, size);
   reverseAr1D(ar, size);
   printf("reverseAr1D(): ");
   if (size > 0) {
      for (i=0; i<size; i++)
         printf("%d ", ar[i]);
   }
   return 0;
}
void printReverse1(int ar[], int size)
{
   int i;

   printf("printReverse1(): ");

   //print in reverse using index notation
   for(i=size-1; i>=0; i--)
    printf("%d ", ar[i]);

   //new line
   putchar('\n');
}
void printReverse2(int ar[], int size)
{
	int i;

   printf("printReverse2(): ");

   //print in reverse using index notation
   for(i=size-1; i>=0; i--)
    printf("%d ", *(ar+i));

   //new line
   putchar('\n');
}
void reverseAr1D(int ar[ ], int size)
{
   int i, temp;

   //reverse Array
   //size/2 as after the middle point, 1 and n-1, etc will swap back to original space
   for(i=0; i<size/2; i++)
   {
       temp = ar[size-1-i];
       ar[size-1-i] = ar[i];
       ar[i] = temp;
   }
}
