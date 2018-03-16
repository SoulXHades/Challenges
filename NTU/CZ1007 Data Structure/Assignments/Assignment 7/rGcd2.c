/*
Write a recursive C function rGcd2() that computes the greatest common divisor and
returns the result to the calling function via call by reference.
For example, if num1=4 and num2=7, then result=1;
and if num1=4 and num2=32, then result=4.
The function prototype is given as follows:

    void rGcd2(int num1, int num2, int *result);

Write a C program to test the function.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter 2 numbers:
4 7
rGcd2(): 1

(2) Test Case 2:
Enter 2 numbers:
32 4
rGcd2(): 4

(3) Test Case 3:
Enter 2 numbers:
4 38
rGcd2(): 2

(4) Test Case 4:
Enter 2 numbers:
32 38
rGcd2(): 2
*/

#include <stdio.h>
void rGcd2(int num1, int num2, int *result);
int main()
{
   int n1, n2, result;

   printf("Enter 2 numbers: \n");
   scanf("%d %d", &n1, &n2);
   rGcd2(n1, n2, &result);
   printf("rGcd2(): %d\n", result);
   return 0;
}
void rGcd2(int num1, int num2, int *result)
{
   if((*result > num1) && (*result > num2))
   {
       *result = (abs(num1) > abs(num2)) ? abs(num2) : abs(num1);
   }

   if(num1 % *result == 0 && num2 % *result == 0)
        return;
   else
   {
       --(*result);
       rGcd2(num1, num2, result);
   }
}
