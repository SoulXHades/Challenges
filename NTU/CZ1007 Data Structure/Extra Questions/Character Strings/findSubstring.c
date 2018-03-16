/*
Write a C function findSubstring() that takes two character string arguments, str
and substr as input and returns 1 if substr is a substring of str (i.e. if substr is contained in str)
and 0 if not. For example, the function will return 1 if substr is "123" and str is "abc123xyz",
but it will return 0 if otherwise. Note that for this question you are not allowed to use any string functions
from the standard C library. The prototype of the function is given below:

int findSubstring(char *str, char *substr);

Write a C program to test the function.

Some test input and output sessions are given below:
(1) Test Case 1:
Enter the string:
abcde
Enter the substring:
abc
findSubstring(): Is a substring

(2) Test Case 2:
Enter the string:
abcde
Enter the substring:
cdef
findSubstring(): Not a substring
*/
#include <stdio.h>
#define INIT_VALUE -1
int findSubstring(char *str, char *substr);
int main()
{
 char str[40], substr[40];
 int result = INIT_VALUE;
 printf("Enter the string: \n");
 gets(str);
 printf("Enter the substring: \n");
 gets(substr);
 result = findSubstring(str, substr);
 if (result == 1)
 printf("findSubstring(): Is a substring\n");
 else if ( result == 0)
 printf("findSubstring(): Not a substring\n");
 else
 printf("findSubstring(): An error\n");
  return 0;
}
int findSubstring(char *str, char *substr)
{
 int i;

 while(*str != '\0')
 {
     i = 0;

     while(substr[i] != '\0')
     {
         if(substr[i] != str[i])
            break;
         else if(substr[i+1] == '\0')
            return 1;

         ++i;
     }

     ++str;
 }

 return 0;
}
