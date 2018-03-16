/*
Write a recursive function that computes the power of a number num. The power p may be
any integer value. The function rPower1() returns the computed result.
The function prototype is given as follows:

float rPower1(float num, int p);

Write a C program to test the function.

Some sample input and output sessions are given below:
(1) Test Case 1:
Enter the number and power:
2 3
rPower1(): 8.00

(2) Test Case 2:
Enter the number and power:
2 -4
rPower1(): 0.06

(3) Test Case 3:
Enter the number and power:
2 0
rPower1(): 1.00
*/

#include <stdio.h>
float rPower1(float num, int p);
int main()
{
 int power;
 float number;

 printf("Enter the number and power: \n");
 scanf("%f %d", &number, &power);
 printf("rPower1(): %.2f\n", rPower1(number, power));
 return 0;
}
float rPower1(float num, int p)
{
 if(p == 0)
    return 1;
 else if(p > 0)
    return num * rPower1(num, p-1);
 else
    return (1/num) * rPower1(num, p+1);
}
