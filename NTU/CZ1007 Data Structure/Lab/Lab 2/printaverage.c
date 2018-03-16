/*
Write a C program that reads in several lines of non-negative integer numbers,
computes the average for each line and prints out the average. The value –1 in each line of user
input is used to indicate the end of input for that line.

Sample input and output sessions are given below:

(1) Test Case 1:
Enter number of lines:
2
Enter line 1 (end with -1):
2 4 6 8 -1
Average = 5.00
Enter line 2 (end with -1):
1 3 5 7 9 -1
Average = 5.00

(2) Test Case 2:
Enter number of lines:
1
Enter line 1 (end with -1):
*/

#include<stdio.h>
int main()
{
    int total, count, lines, input;
    double average;
    int i;

    printf("Enter number of lines: \n");
    scanf("%d", &lines);

    for(i=1; i<lines+1; i++)
    {
        count = 1;
        total = 0;

        printf("Enter line %d (end with -1):\n", i);

        for(; ; count++)
        {
            scanf("%d", &input);

            //debugging
            //printf("count%d: %d\n", count, input);

            if(input == -1)
            {
                --count;
                break;
            }else if(input < 0)
            {
                --count;
                continue;
            }

            total += input;
        }

        average = (double)total / count;

        printf("Average = %.2lf\n", average);
    }

    return 0;
}
