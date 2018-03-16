/*
Write a recursive C function rFindMaxAr() that finds the index position of the
maximum number in an array of integer numbers. In the function, the parameter ar accepts an array
passed in from the calling function. The pointer parameter index is used for passing the maximum
number’s index position to the caller via call by reference.
The function prototype is given as follows:

void rFindMaxAr(int *ar, int size, int i, int *index);

Write a C program to test the function.

Some sample input and output sessions are given below:
(1) Test Case 1:
Enter array size:
5
Enter 5 numbers:
1 2 3 4 5
Max number: 5
Index position: 4

(2) Test Case 2:
Enter array size:
7
Enter 7 numbers:
2 5 4 7 9 10 1
Max number: 10
Index position: 5
*/

#include <stdio.h>
void rFindMaxAr(int *ar, int size, int i, int *index);
int main()
{
 int ar[50],i,maxIndex=0,size;
 printf("Enter array size: \n");
 scanf("%d", &size);
 printf("Enter %d numbers: \n", size);
 for (i=0; i < size; i++)
    scanf("%d", &ar[i]);
 rFindMaxAr(ar,size,0,&maxIndex);
 printf("Max number: %d\n", ar[maxIndex]);
 printf("Index position: %d\n", maxIndex);
 return 0;
}
void rFindMaxAr(int *ar, int size, int i, int *index)
{
 if(size == 0)
    return;
 else
 {
     if(ar[i] > ar[*index])
        *index = i;
     rFindMaxAr(ar, size-1, i+1, index);
 }
}
