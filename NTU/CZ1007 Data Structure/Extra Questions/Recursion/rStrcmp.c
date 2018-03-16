/*
The recursive C function rStrcmp() compares the string pointed to by s1 to the string
pointed to by s2. If the string pointed to by s1 is greater than, equal to, or less than the string pointed to
by s2, then it returns 1, 0 or –1 respectively. Write the code for the function without using any of the
standard string library functions. The function prototype is given as follows:

int rStrcmp(char *s1, char *s2);

Write a C program to test the function.

Some sample input and output sessions are given below:
(1) Test Case 1:
Enter a source string:
abc
Enter a target string:
abc
rStrcmp(): 0

(2) Test Case 2:
Enter a source string:
abcdef
Enter a target string:
abc123
rStrcmp(): 1

(3) Test Case 3:
Enter a source string:
abc123
Enter a target string:
abcdef
rStrcmp(): -1

(4) Test Case 4:
Enter a source string:
abc123
Enter a target string:
abc123f
rStrcmp(): -1
*/

#include <stdio.h>
#define INIT_VALUE 10
int rStrcmp(char *s1, char *s2);
int main()
{
 char source[40], target[40];
 int result=INIT_VALUE;

 printf("Enter a source string: \n");
 gets(source);
 printf("Enter a target string: \n");
 gets(target);
 result = rStrcmp(source, target);
  printf("rStrcmp(): %d", result);
 return 0;
}
int rStrcmp(char *s1, char *s2)
{
 if(*s1 == *s2)
 {
     if(*s1 != '\0')
        rStrcmp(s1+1, s2+1);
     else
        return 0;
 }
 else if(*s1 > *s2)
    return 1;
 else
    return -1;
}
