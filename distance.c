/*
The distance between two points (x1, y1) and (x2, y2) is given by 
distance = qrt(pow((x1 - x2), 2) + pow((y1 - y2), 2))
Write a C program that reads the (x, y) coordinates for two points, 
computes the distance between the two points.  
*/

#include <stdio.h>
#include <math.h>
int main()
{
    float x1, x2, y1, y2, distance;

    printf("Enter first point x1 y1:\n");
    scanf("%f %f", &x1, &y1);

    printf("Enter first point x2 y2:\n");
    scanf("%f %f", &x2, &y2);

    distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

    printf("The distance is %.2f", distance);

    return 0;
}
