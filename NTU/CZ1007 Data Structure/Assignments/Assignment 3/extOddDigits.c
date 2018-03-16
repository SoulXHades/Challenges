/*
Write a function extOddDigits1() that extracts the odd digits from a positive number,
and combines the odd digits sequentially into a new number.
The new number is returned to the calling function.
If the input number does not contain any odd digits,
then the function returns -1. For example, if the input number is 1234567,
then 1357 will be returned; and if the input number is 28, then –1 will returned.
Write the function in two versions.
The function extOddDigits1() returns the result to the caller,
while the function extOddDigits2() returns the result through the pointer parameter, result.
The function prototype is given as follows:

    int extOddDigits1(int num);
    void extOddDigits2(int num, int *result);

Write a C program to test the functions.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter a number:
1234
extOddDigits1(): 13
extOddDigits2(): 13

(2) Test Case 2:
Enter a number:
2468
extOddDigits1(): -1
extOddDigits2(): -1

(3) Test Case 3:
Enter a number:
1357
extOddDigits1(): 1357
extOddDigits2(): 1357

(4) Test Case 4:
Enter a number:
7
extOddDigits1(): 7
extOddDigits2(): 7
*/

#include <stdio.h>
#define INIT_VALUE 0
int extOddDigits1(int num);
void extOddDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extOddDigits1(): %d\n", extOddDigits1(number));
    extOddDigits2(number, &result);
    printf("extOddDigits2(): %d\n", result);
    return 0;
}
int extOddDigits1(int num)
{
   int i=1, newValue=0;

   while(num != 0)
   {
       if((num % 10) % 2 != 0)
       {
           newValue += (num % 10) * i;
           i *= 10;
       }

       num /= 10;
   }

   return (newValue != 0) ? newValue : -1;
}
void extOddDigits2(int num, int *result)
{
   int i=1, newValue=0;

   while(num != 0)
   {
       if((num % 10) % 2 != 0)
       {
           *result += (num % 10) * i;
           i *= 10;
       }

       num /= 10;
   }

   if(*result == 0)
    *result = -1;
}
