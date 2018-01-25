/*
Write a C program that reads the user input on the current and resistance, 
and displays the power loss of the cable on the screen. 
The relevant formula is P = I^2 * R, where P is the power loss in watts, 
I is the current in amperes and R is the resistance in ohms. 
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
