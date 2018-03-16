/*
The recursive function rAllOddDigits1() returns either 1 or 0 according to
whether or not all the digits of the positive integer argument number num are odd. For example, if the
argument num is 1357, then the function should return 1; and if the argument num is 1234, then 0 should
be returned. The function prototype is given below:

int rAllOddDigits1(int num);

Write a C program to test the function.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter a number:
3579
rAllOddDigits1(): 1

(2) Test Case 2:
Enter a number:
3578
rAllOddDigits1(): 0
*/

#include <stdio.h>
int rAllOddDigits1(int num);
int main()
{
 int number;
 printf("Enter a number: \n");
 scanf("%d", &number);
 printf("rAllOddDigits1(): %d\n", rAllOddDigits1(number));
 return 0;
}
int rAllOddDigits1(int num)
{
 if(num < 10)
 {
     if(num % 2 != 0)
        return 1;
     else
        return 0;
 }
 else
 {
     if(num % 2 != 0)
        return rAllOddDigits1(num/10);
     else
        return 0;
 }
}
