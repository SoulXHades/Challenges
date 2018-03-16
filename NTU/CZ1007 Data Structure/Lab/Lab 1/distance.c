/*
The distance between two points (x1, y1) and (x2, y2) is given by
distance = qrt(pow((x1 - x2), 2) + pow((y1 - y2), 2))
Write a C program that reads the (x, y) coordinates for two points,
computes the distance between the two points.

Sample input and output sessions are given below:

(1) Test Case 1:
Enter first point x1 y1:
1 5
Enter second point x2 y2:
2 7
The distance is 2.24

(2) Test Case 2:
Enter first point x1 y1:
1 1
Enter second point x2 y2:
5 5
The distance is 5.66
*/

#include <stdio.h>
#include <math.h>
int main()
{
    float x1, x2, y1, y2, distance;

    printf("Enter first point x1 y1:\n");
    scanf("%f %f", &x1, &y1);

    printf("Enter second point x2 y2:\n");
    scanf("%f %f", &x2, &y2);

    distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

    printf("The distance is %.2f", distance);

    return 0;
}
