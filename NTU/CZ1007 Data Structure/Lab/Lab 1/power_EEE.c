/*
Write a C program that reads the user input on the current and resistance,
and displays the power loss of the cable on the screen.
The relevant formula is P = I^2 * R, where P is the power loss in watts,
I is the current in amperes and R is the resistance in ohms.

Sample input and output sessions are given below:

(1) Test Case 1:
Enter the current:
12
Enter the resistance:
1.5
The power loss: 216.00

(2) Test Case 2:
Enter the current:
5
Enter the resistance:
0.5
The power loss: 12.50
*/

#include <stdio.h>

int main()
{
    float current, resistance, power;

    printf("Enter the current:\n");
    scanf("%f", &current);

    printf("Enter the resistance:\n");
    scanf("%f", &resistance);

    power = (current * current) * resistance;

    printf("The power loss: %.2f", power);
}
