/*
Write a recursive function that counts the number of digits for a non-negative integer.
For example, 1234 has 4 digits. Write two versions of the function.
The function rNumDigits1() returns the result.
The function rNumDigits2() returns the result through the parameter result.
The function prototypes are:

    int rNumDigits1(int num);
    void rNumDigits2(int num, int *result);

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter the number:
5
rNumDigits1(): 1
rNumDigits2(): 1

(2) Test Case 2:
Enter the number:
13579
rNumDigits1(): 5
rNumDigits2(): 5
*/

#include <stdio.h>
int rNumDigits1(int num);
void rNumDigits2(int num, int *result);
int main()
{
   int number, result=0;

   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("rNumDigits1(): %d\n", rNumDigits1(number));
   rNumDigits2(number, &result);
   printf("rNumDigits2(): %d\n", result);
   return 0;
}
int rNumDigits1(int num)
{
   if(num == 0)
    return 0;
   else
    return 1 + rNumDigits1(num/10);
}
void rNumDigits2(int num, int *result)
{
   if(num == 0)
    return;
   else
   {
       ++*result;
       rNumDigits2(num/10, result);
   }
}
