/*
Write a C program that computes the solutions for x and y in the linear system of equations:
(a1 * x) + (b1 * y) = c1
(a2 * x) + (b2 * y) = c2

The solutions for x and y are given by:
x = (b2*c1 - b1*c2) / (a1*b2 - a2*b1)
y = (a1*c2 - a2*c1) / (a1*b2 - a2*b1);

The program reads in a1, b1, c1, a2, b2 and c2, and prints the solutions.
In your program,
you may assume that the denominator (a1*b2 - a2*b1) of the above equations is not zero.
Therefore, there is no need to check whether the denominator is zero or not.

Sample input and output sessions are given below:

(1) Test Case 1:
Enter the values for a1, b1, c1, a2, b2, c2:
1 1 1 5 7 9
x = -1.00 and y = 2.00

(2) Test Case 2:
Enter the values for a1, b1, c1, a2, b2, c2:
1 1 2 2 3 3
x = 3.00 and y = -1.00
*/

#include <stdio.h>
#include <math.h>
int main()
{
    //Declaration of variables
    float a1, b1, c1, a2, b2, c2, x, y;

    do
    {
        printf("Enter the values for a1, b1, c1, a2, b2, c2:\n");
        scanf("%f %f %f %f %f %f", &a1, &b1, &c1, &a2, &b2, &c2);

    }while(((a1*b2) - (a2*b1)) == 0);   //Check if division error

    //Obtain x and y axis
    x = ((b2*c1) - (b1*c2)) \
    / ((a1*b2) - (a2*b1));

    y = ((a1*c2) - (a2*c1)) \
    / ((a1*b2) - (a2*b1));

    printf("x = %.2f and y = %.2f", x, y);

    return 0;
}
