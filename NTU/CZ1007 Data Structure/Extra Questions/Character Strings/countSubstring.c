/*
Write a C function countSubstring() that takes in two parameters str and
substr, and counts the number of substring substr occurred in the character string str. If the
substr is not contained in str, then it will return 0. Please note that you do not need to consider test
cases such as str = "aooob" and substr = "oo". The function prototype is given as follows:

int countSubstring(char str[], char substr[]);

Write a C program to test the function.

Some test input and output sessions are given below:
(1) Test Case 1:
Enter the string:
abcdef
Enter the substring:
dd
countSubstring(): 0

(2) Test Case 2:
Enter the string:
abababcdef
Enter the substring:
ab
countSubstring(): 3
*/

#include <stdio.h>
int countSubstring(char str[], char substr[]);
int main()
{
 char str[80],substr[80];

 printf("Enter the string: \n");
 gets(str);
 printf("Enter the substring: \n");
 gets(substr);
 printf("countSubstring(): %d\n", countSubstring(str, substr));
 return 0;
}
int countSubstring(char str[], char substr[])
{
 int count=0, i;

 while(*str != '\0')
 {
     i = 0;

     while(substr[i] != '\0')
     {
         if(substr[i] != str[i])
            break;
         else if(substr[i+1] == '\0')
            ++count;

         ++i;
     }

     ++str;
 }

 return count;
}
