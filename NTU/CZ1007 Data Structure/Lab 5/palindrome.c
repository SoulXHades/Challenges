/*
Write a function palindrome() that reads a character string and determines whether or not it is a palindrome.
A palindrome is a sequence of characters that reads the same forwards and backwards.
For example, "abba" and "abcba" are palindromes, but "abcd" is not.
The function returns 1 if it is palindrome, or 0 if otherwise.
The function prototype is given as follows:

    int palindrome(char *str);

Write a C program to test the function.

Some test input and output sessions are given below:

(1) Test Case 1:
Enter a string:
abcba
palindrome(): A palindrome

(2) Test Case 2:
Enter a string:
abba
palindrome(): A palindrome

(3) Test Case 3:
Enter a string:
abcde
palindrome(): Not a palindrome

(4) Test Case 4:
Enter a string:
abb a
palindrome(): Not a palindrome
*/

#include <stdio.h>
#define INIT_VALUE -1
int palindrome(char *str);
int main()
{
   char str[80];
   int result = INIT_VALUE;

   printf("Enter a string: \n");
   gets(str);
   result = palindrome(str);
   if (result == 1)
      printf("palindrome(): A palindrome\n");
   else if (result == 0)
      printf("palindrome(): Not a palindrome\n");
   else
      printf("An error\n");
   return 0;
}
int palindrome(char *str)
{
   int i=0, count;

   while(str[i] != '\0')
    i++;

   for(count=0; count<i/2; count++)
   {
       if(str[count] != str[i-count-1])
        return 0;
   }

   return 1;
}
