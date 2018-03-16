/*
The recursive function rAllEvenDigits2() returns either 1 or 0, via the pointer parameter result,
according to whether or not all the digits of the positive integer argument number num are even.
For example, if the argument num is 2468, then the function should return 1;
and if the argument num is 1234, then 0 should be returned.
The function prototype is given below:

    void rAllEvenDigits2(int num, int *result);

Write a C program to test the function.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter a number:
2468
rAllEvenDigits2(): yes

(2) Test Case 2:
Enter a number:
2345
rAllEvenDigits2(): no

(3) Test Case 3:
Enter a number:
4
rAllEvenDigits2(): yes

(4) Test Case 4:
Enter a number:
1
rAllEvenDigits2(): no
*/

#include <stdio.h>
#define INIT_VALUE -1
void rAllEvenDigits2(int num, int *result);
int main()
{
   int number, result=INIT_VALUE;

   printf("Enter a number: \n");
   scanf("%d", &number);
   rAllEvenDigits2(number, &result);
   if (result == 1)
      printf("rAllEvenDigits2(): yes\n");
   else if (result == 0)
      printf("rAllEvenDigits2(): no\n");
   else
      printf("rAllevenDigits2(): error\n");
   return 0;
}
void rAllEvenDigits2(int num, int *result)
{
   if(num == 0)
    return;
   else
   {
       if(((num % 10) % 2) == 0)
       {
           *result = 1;
           rAllEvenDigits2(num/10, result);
       }
       else
       {
           *result = 0;
           return;
       }
   }
}
