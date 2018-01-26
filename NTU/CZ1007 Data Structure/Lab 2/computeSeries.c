/*
Write a C program that computes the value of ex according to the following formula:

e^x = 1 + x/1! + (x^2)/2! + (x^3)/3! + ... + (10^10)/10!

Sample input and output sessions are given below:

(1) Test Case 1:
Enter x:
0.9
Result = 2.46

(2) Test Case 2:
Enter x:
0
Result = 1.00

(3) Test Case 3:
Enter x:
-0.9
Result = 0.41
*/

#include <stdio.h>
int main()
{
    int n, denominator = 1;
    float x, result = 1.0, numerator = 1.0;
    printf("Enter x: \n");
    scanf("%f", &x);

    for(n=1; n<11; n++)
    {
        numerator *= x;
        denominator *= n;

        result += numerator/denominator;
    }

    printf("Result = %.2f\n",  result);
    return 0;
}
