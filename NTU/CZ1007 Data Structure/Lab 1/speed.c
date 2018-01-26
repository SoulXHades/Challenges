/*
Write a C program to read the time (in seconds) and distance (in kilometers) covered by a moving object,
calculate the speed in kilometers per second, and display the speed on the screen.
The relevant formula is: speed = distance/time.
The output should be in the following format:
“The speed is [the speed value] km/sec.”

Sample input and output sessions are given below:

(1) Test Case 1:
Enter distance (in km):
1
Enter time (in sec):
10
The speed is 0.10 km/sec

(2) Test Case 2:
Enter distance (in km):
10
Enter time (in sec):
5
The speed is 2.00 km/sec
*/

#include <stdio.h>

int main()
{
    int time;
    float distance;

    printf("Enter distance (in km):\n");
    scanf("%f", &distance);

    printf("Enter time (in sec):\n");
    scanf("%d", &time);

    printf("The speed is %.2f km/sec", distance/time);

    return 0;
}
