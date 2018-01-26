/*
Write a C program that computes the volume and surface area of a cylinder.
The program reads the user input on the radius and height of the cylinder,
and then computes the volume and surface area of the cylinder.
The relevant formulas are volume = πr2h and surface area = 2πrh + 2πr2,
where r is the radius and h is the height.

Sample input and output sessions are given below:

(1) Test Case 1:
Enter the radius:
5
Enter the height:
8
The volume is: 628.32
The surface area is: 408.41

(2) Test Case 2:
Enter the radius:
1
Enter the height:
5
The volume is: 15.71
The surface area is: 37.70
*/

#include <stdio.h>
#define PI 3.1416
int main()
{
    float radius, height, volume, SA;

    printf("Enter the radius:\n");
    scanf("%f", &radius);

    printf("Enter the height:\n");
    scanf("%f", &height);

    volume = PI * (radius * radius) * height;
    SA = (2 * PI * radius * height) + (2 * PI * (radius * radius));


    printf("The volume is: %.2f\n", volume);
    printf("The surface area is: %.2f", SA);

    return 0;
}
