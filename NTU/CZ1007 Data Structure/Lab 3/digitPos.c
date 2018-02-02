/*
Write the function digitPos1() that returns the position of the first appearance of a specified digit in a positive number.
The position of the digit is counted from the right and starts from 1.
If the required digit is not in the number, the function should return 0.
For example, digitPos1(12315, 1) returns 2 and digitPos1(12, 3) returns 0.
The function prototype is given below:

    int digitPos1(int num, int digit);

Write another function digitPos2() that passes the result through the pointer parameter, result.
For example, if num = 12315 and digit = 1, then *result = 2 and if num=12 and digit = 3, then *result = 0.
The function prototype is given below:

    void digitPos2(int num, int digit, int *result);

Some sample input and output sessions are given below:

(1)     Test Case 1:
Enter the number:
234567
Enter the digit:
6
digitPos1(): 2
digitPos2(): 2

(2)     Test Case 2:
Enter the number:
234567
Enter the digit:
8
digitPos1(): 0
digitPos2(): 0
*/

#include <stdio.h>
int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);
int main()
{
   int number, digit, result=0;

   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("Enter the digit: \n");
   scanf("%d", &digit);
   printf("digitPos1(): %d\n", digitPos1(number, digit));
   digitPos2(number, digit, &result);
   printf("digitPos2(): %d\n", result);
   return 0;
}
int digitPos1(int num, int digit)
{
   int count=0;

   if(num == digit)
    return 1;

   while(num != 0)
   {
       ++count;

       if((num % 10) == digit)
        return count;

       num /= 10;
   }

   return 0;
}
void digitPos2(int num, int digit, int *result)
{
   if(num == digit)
   {
       *result = 1;
       return;
   }

   while(num != 0)
   {
       ++*result;

       if((num % 10) == digit)
        return;

       num /= 10;
   }

   *result = 0;
}
