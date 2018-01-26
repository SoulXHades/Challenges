/*
Write a C program that accepts a positive number height between 1 and 10 as its
parameter value, and prints a triangular pattern according to height. Note that only 1, 2 and 3 are
used to generate the patterns. A sample input and output session when the program is called is
given below. For example, pattern(2) will print the following pattern:
1
22
333
while pattern(7) will print the following pattern:
1
22
333
1111
22222
333333
1111111
Sample input and output sessions are given below:
(1) Test Case 1:
Enter the height:
3
Pattern:
1
22
333
(2) Test Case 2:
Enter the height:
7
Pattern:
1
22
333
1111
22222
333333
1111111
*/

#include <stdio.h>
int main()
{
    int row, col, height;
    int num = 0;
    printf("Enter the height: \n");
    scanf("%d", &height);
    printf("Pattern: \n");

   for(row=1; row<height+1; row++)
   {
       for(col=1; col<row+1; col++)
       {
           printf("%d", row-num);
       }

       if(row%3 == 0)
            num += 3;

       putchar('\n');
   }

   return 0;
}
