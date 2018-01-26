/*
Write a C program that reads in character by character from an input source, until
‘#’ is entered. The output of the program is the number of English letters and the number of digits
that appear in the input.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter your characters (# to end):
happy 34567 fans#
The number of digits: 5
The number of letters: 9

(2) Test Case 2:
Enter your characters (# to end):
1a2b3c#
The number of digits: 3
The number of letters: 3
*/

#include <stdio.h>
int main()
{
 int ccount = 0, dcount = 0;
 char ch;
 printf("Enter your characters (# to end): \n");

 ch = getchar();

 while(ch != '#')
 {
     if(isdigit(ch))
        dcount += 1;
     else if(ch != ' ')
        ccount += 1;

     ch = getchar();
 }

 printf("The number of digits: %d\n", dcount);
 printf("The number of letters: %d\n", ccount);
 return 0;
}
