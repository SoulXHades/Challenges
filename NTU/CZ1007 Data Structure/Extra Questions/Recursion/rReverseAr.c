/*
Write a recursive function whose arguments are an array of integers ar and an integer
size specifying the size of the array and whose task is to reverse the contents of the array. The result is
returned to the caller through the array parameter. The code should not use another, intermediate, array.
The function prototype is given as follows:

void rReverseAr(int ar[], int size);

Write a C program to test the function.
Some sample input and output sessions are given below:
(1) Test Case 1:
Enter size:
5
Enter 5 numbers:
1 2 3 4 5
rReverseAr(): 5 4 3 2 1

(2) Test Case 2:
Enter size:
1
Enter 1 numbers:
3
rReverseAr(): 3
*/

#include <stdio.h>
void rReverseAr(int ar[], int size);
int main()
{
 int array[80];
 int size, i;
 printf("Enter size: \n");
 scanf("%d", &size);
 printf("Enter %d numbers: \n", size);
 for (i = 0; i < size; i++)
 scanf("%d", &array[i]);
 printf("rReverseAr(): ");
 rReverseAr(array, size);
 for (i = 0; i < size; i++)
 printf("%d ", array[i]);
 printf("\n");
 return 0;
}
void rReverseAr(int ar[], int size)
{
 int temp;

 if(size < 1)
    return;
 else
 {
     temp = ar[0];
     ar[0] = ar[size-1];
     ar[size-1] = temp;

     rReverseAr(ar+1, size-2);
 }
}
