/*
Write a function that counts the number of digits for a non-negative integer.
For example, 1234 has 4 digits. The function numDigits1() returns the result. The function prototype is given below:

        int numDigits1(int num);

Write another function numDigits2() that passes the result through the pointer parameter, result.
The function prototype is given below:

        void numDigits2(int num, int *result);

Some sample input and output sessions are given below:

(1)     Test Case 1:
Enter the number:
5
numDigits1(): 1
numDigits2(): 1

(2)     Test Case 2:
Enter the number:
13579
numDigits1(): 5
numDigits2(): 5
*/

#include <stdio.h>
int numDigits1(int num);
void numDigits2(int num, int *result);
int main()
{
   int number, result=0;

   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("numDigits1(): %d\n", numDigits1(number));
   numDigits2(number, &result);
   printf("numDigits2(): %d\n", result);
   return 0;
}
int numDigits1(int num)
{
   int count=0;

   while(num != 0)
   {
       num /= 10;
       ++count;
   }

   return count;
}
void numDigits2(int num, int *result)
{
   while(num != 0)
   {
       num /= 10;
       ++*result;
   }
}
