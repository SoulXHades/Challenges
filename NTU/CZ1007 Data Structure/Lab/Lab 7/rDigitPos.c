/*
Write a recursive function that returns the position of the first appearance of a specified digit in a positive number.
The position of the digit is counted from the right and starts from 1.
If the required digit is not in the number, the function should return 0.
Write two versions of the function. The function rDigitPos1() returns the result.
The function rDigitPos2() returns the result through the parameter result.
The function prototypes are:

    int rDigitPos1(int num, int digit);
    void rDigitPos2(int num, int digit, int *pos);

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter the number:
1234567
Enter the digit:
6
rDigitPos1(): 2
rDigitPos2(): 2

(2) Test Case 2:
Enter the number:
1234567
Enter the digit:
8
rDigitPos1(): 0
rDigitPos2(): 0
*/

#include <stdio.h>
int rDigitPos1(int num, int digit);
void rDigitPos2(int num, int digit, int *pos);
int main()
{
   int number, digit, result=0;

   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("Enter the digit: \n");
   scanf("%d", &digit);
   printf("rDigitPos1(): %d\n", rDigitPos1(number, digit));
   rDigitPos2(number, digit, &result);
   printf("rDigitPos2(): %d\n", result);
   return 0;
}
int rDigitPos1(int num, int digit)
{
   if(num%10 == digit)
    return 1;
   else if(num == 0)
    return 0;
   else
   {
       if(rDigitPos1(num/10, digit) > 0)
        return rDigitPos1(num/10, digit) + 1;

       return 0;
   }
}
void rDigitPos2(int num, int digit, int *pos)
{
   if(num%10 == digit)
   {
       ++*pos;
       return;
   }
   else if(num == 0)
   {
       *pos = 0;
       return;
   }
   else
   {
       ++*pos;
       rDigitPos2(num/10, digit, pos);
   }
}
