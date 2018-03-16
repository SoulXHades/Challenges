/*
The number of consecutive array elements in an array that contains the same integer value
forms a ‘platform’. Write a C function platform() that takes in an array of integers ar and size as
parameters, and returns the length of the maximum platform in ar to the calling function. The function
prototype is given as follows:

int platform(int ar[], int size);

Write a C program to test the function.
Some sample input and output sessions are given below:
(1) Test Case 1:
Enter array size:
5
Enter 5 data:
1 2 2 2 3
platform1D(): 3

(2) Test Case 2:
Enter array size:
10
Enter 10 data:
1 2 3 4 5 6 7 8 9 0
platform1D(): 1
*/

#include <stdio.h>
int platform1D(int ar[], int size);
int main()
{
 int i,b[50],size;

 printf("Enter array size: \n");
 scanf("%d", &size);
 printf("Enter %d data: \n", size);
 for (i=0; i<size; i++)
    scanf("%d",&b[i]);
 printf("platform1D(): %d\n", platform1D(b,size));
 return 0;
}
int platform1D(int ar[], int size)
{
 int i, count=1;

 for(i=0; i<size-1; i++)
 {
     if(ar[i] == ar[i+1])
        ++count;
 }

 return count;
}
