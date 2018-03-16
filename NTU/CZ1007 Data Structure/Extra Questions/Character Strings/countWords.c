/*
Write a function countWords() that accepts a string s as its parameter. The string
contains a sequence of words separated by spaces. The function then displays the number of words in the
string. The function prototype is given as follows:

int countWords(char *s);

Write a C program to test the function.

A sample input and output session is given below:
(1) Test Case 1:
Enter the string:
How are you?
countWords(): 3

(2) Test Case 2:
Enter the string:
There are 12 dollars.
countWords(): 4

(3) Test Case 3:
Enter the string:
Oneword?
countWords(): 1
*/

#include <stdio.h>
int countWords(char *s);
int main()
{
 char str[50];
 printf("Enter the string: \n");
 gets(str);
 printf("countWords(): %d", countWords(str));
 return 0;
}
int countWords(char *s)
{
 int count=0;

 while(*s != '\0')
 {
     if(*s != ' ' || *s != '\0')
     {
         if(*(s+1) == ' ' || *(s+1) == '\0')
            ++count;
     }

     ++s;
 }

 return count;
}
