/*
Write a C program that reads the user input on temperature in degrees Fahrenheit,
and then converts the temperature from degrees Fahrenheit into degrees Celsius. The relevant
formula is given as follows: Celsius = (5/9)*(Fahrenheit – 32).

Sample input and output sessions are given below:

(1) Test Case 1:
Enter the temperature in degree F:
45
Converted degree in C: 7.22

(2) Test Case 2:
Enter the temperature in degree F:
-12
Converted degree in C: -24.44
*/

#include <stdio.h>

int main()
{
    float fahrenheit, celsius;  // declare variables

    printf("Enter the temperature in degree F:\n");
    scanf("%f", &fahrenheit);

    celsius = ((float)5/9)*(fahrenheit - 32);

    printf("Converted degree in C: %.2f\n", celsius);

    return 0;
}
