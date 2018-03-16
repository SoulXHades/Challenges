/*
Write a recursive function that returns the value of the kth digit (k>0) from the right of a non-negative integer num.
For example, if num=1234567 and k=3, the function will return 5 and if num=1234 and k=8, the function will return 0.
Write the function rDigitValue1() will return the result.
The prototype of the function is given below:

    int rDigitValue1(int num, int k);

Write a C program to test the function.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter a number:
234567
Enter k position:
3
rDigitValue1(): 5

(2) Test Case 2:
Enter a number:
123
Enter k position:
4
rDigitValue1(): 0

(3) Test Case 3:
Enter a number:
12345
Enter k position:
1
rDigitValue1(): 5

(4) Test Case 4:
Enter a number:
12345
Enter k position:
5
rDigitValue1(): 1
*/

#include <stdio.h>
int rDigitValue1(int num, int k);
int main()
{
   int k, number;

   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("Enter k position: \n");
   scanf("%d", &k);
   printf("rDigitValue1(): %d\n", rDigitValue1(number, k));
   return 0;
}
int rDigitValue1(int num, int k)
{
   if(num == 0)
    return 0;
   else if(k == 1)
    return num%10;
   else
    return rDigitValue1(num/10, k-1);
}
