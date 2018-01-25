/*
Write a C program to read the time (in seconds) and distance (in kilometers) covered by a moving object, 
calculate the speed in kilometers per second, and display the speed on the screen. 
The relevant formula is: speed = distance/time. 
The output should be in the following format:  
“The speed is [the speed value] km/sec.”
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
