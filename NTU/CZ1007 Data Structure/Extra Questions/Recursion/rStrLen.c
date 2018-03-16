/*
The recursive function rStrLen() accepts a character string s as parameter,
and returns the length of the string.
For example, if s is "abcde", then the function rStrLen() will return 5.
The function prototype is:

int rStrLen(char *s);

Write a C program to test the function.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter the string:
abcde
rStrLen(): 5

(2) Test Case 2:
Enter the string:
a
rStrLen(): 1
*/

#include <stdio.h>
int rStrLen(char *s);
int main()
{
 char str[80];
 printf("Enter the string: \n");
 gets(str);
 printf("rStrLen(): %d\n", rStrLen(str));
 return 0;
}
int rStrLen(char *s)
{
 if(*s != '\0')
    return 1 + rStrLen(s+1);
}
