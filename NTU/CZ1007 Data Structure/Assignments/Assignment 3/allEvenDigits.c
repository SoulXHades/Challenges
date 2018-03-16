/*
The function allEvenDigits() returns either 1 or 0 according to whether or not
all the digits of the positive integer argument number are even.
For example, if the input argument is 2468,
then the function should return 1; and if the input argument is 1234,
then 0 should be returned. Write the function in two versions.
The function allEvenDigits1() returns the result to the caller,
while allEvenDigits2() passes the result through the pointer parameter result.
    The function prototypes are given below:

    int allEvenDigits1(int num);
    void allEvenDigits2(int num, int *result);

Write a C program to test the function.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter a number:
1234
allEvenDigits1(): Not All Even
allEvenDigits2(): Not All Even

(2) Test Case 2:
Enter a number:
2468
allEvenDigits1(): All Even
allEvenDigits2(): All Even

(3) Test Case 3:

Enter a number:
1357
allEvenDigits1(): Not All Even
allEvenDigits2(): Not All Even

(4) Test Case 4:

Enter a number:
0
allEvenDigits1(): All Even
allEvenDigits2(): All Even
*/

#include <stdio.h>
#define INIT_VALUE -1
int allEvenDigits1(int num);
void allEvenDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("allEvenDigits1(): ");
    result = allEvenDigits1(number);
    if (result == 1)
      printf("All Even\n");
    else if (result == 0)
      printf("Not All Even\n");
    else
      printf("Error\n");
    allEvenDigits2(number, &result);
    printf("allEvenDigits2(): ");
    if (result == 1)
      printf("All Even\n");
    else if (result == 0)
      printf("Not All Even\n");
    else
      printf("Error\n");
    return 0;
}
int allEvenDigits1(int num)
{
   while(num != 0)
   {
       if((num % 10) % 2 != 0)
        return 0;

       num /= 10;
   }

   return 1;
}
void allEvenDigits2(int num, int *result)
{
   *result = 1;

   while(num != 0)
   {
       if((num % 10) % 2 != 0)
        *result = 0;

       num /= 10;
   }
}
