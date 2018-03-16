/*
Write a recursive C function that counts the number of zeros in a specified positive
number num. For example, if num is 105006, then the function will return 3; and if num is 1357, the
function will return 0. The function rCountZeros2() passes the result through the pointer parameter
result. The function prototype is given as follows:

void rCountZeros2(int num, int *result);

Write a C program to test the function.

Some sample input and output sessions are given below:
(1) Test Case 1:
Enter the number:
10500
rCountZeros2(): 3

(2) Test Case 2:
Enter the number:
23453
rCountZeros2(): 0

(3) Test Case 3:
Enter the number:
0
rCountZeros2(): 1

*/

#include <stdio.h>
void rCountZeros2(int num, int *result);
int main()
{
 int number, result;
 printf("Enter the number: \n");
  scanf("%d", &number);
 rCountZeros2(number,&result);
 printf("rCountZeros2(): %d\n", result);
 return 0;
}
void rCountZeros2(int num, int *result)
{
 if(num < 10)
 {
     if(num == 0)
        *result = 1;
     else
        *result = 0;
 }
 else
 {
     if(num%10 == 0)
     {
         rCountZeros2(num/10, result);
         *result += 1;
     }
     else
        rCountZeros2(num/10, result);
 }
}
