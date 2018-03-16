/*
Write a C function stringncpy() that copies not more than n characters (characters that follow a null character are not copied)
from the array pointed to by s2 to the array pointed to by s1.
If the array pointed to by s2 is a string shorter than n characters,
null characters are appended to the copy in the array pointed to by s1,
until n characters in all have been written. The stringncpy() returns the value of s1.
The function prototype:

    char *stringncpy(char *s1, char *s2, int n);

In addition, write a C program to test the stringncpy function.
Your program should read the string and the target n characters from the user and then call the function with the user input.
In this program, you are not allowed to use any functions from the C standard String library.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter the string:
I am a boy.
Enter the number of characters:
7
stringncpy(): I am a

(2) Test Case 2:
Enter the string:
I am a boy.
Enter the number of characters:
21
stringncpy(): I am a boy.
*/

#include <stdio.h>
char *stringncpy(char *s1, char *s2, int n);
int main()
{
   char sourceStr[40], targetStr[40], *target;
   int length;
   printf("Enter the string: \n");
   gets(sourceStr);
   printf("Enter the number of characters: \n");
   scanf("%d", &length);
   target = stringncpy(targetStr, sourceStr, length);
   printf("stringncpy(): %s\n", target);
   return 0;
}
char *stringncpy(char *s1, char *s2, int n)
{
   int i=0;

   while(s2[i] != '\0')
   {
       if(i >= n)
        break;

       s1[i] = s2[i];

       ++i;
   }

   s1[i] = '\0';

   return s1;
}
