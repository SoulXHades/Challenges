/*
Write a recursive C function rReverseDigits() that takes an non-negative integer
argument num and returns an integer whose digits are obtained by reversing those of the argument
number. The result is passed to the calling function through a pointer variable result. For example, if
num is 1234, then the function should return 4321 through the pointer variable. If num is 10, then the
function should return 1. The function prototype is given below:

void rReverseDigits(int num, int *result);

Write a C program to test the function.

Some sample input and output sessions are given below:
(1) Test Case 1:
Enter a number:
1234
rReverseDigits(): 4321

(2) Test Case 2:
Enter a number:
10
rReverseDigits(): 1

(3) Test Case 1:
Enter a number:
12934
rReverseDigits(): 43921
*/

#include <stdio.h>
void rReverseDigits(int num, int *result);
int main()
{
 int result=0, number;

 printf("Enter a number: \n");
 scanf("%d", &number);
 rReverseDigits(number, &result);
 printf("rReverseDigits(): %d\n", result);
 return 0;
}
void rReverseDigits(int num, int *result)
{
 *result = (*result * 10) + num%10;

 if(num > 9)
    rReverseDigits(num/10, result);
}
