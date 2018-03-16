/*
Write a C function compareStr() that takes in two parameters s and t, and compares
the two character strings s and t according to alphabetical order. If s is greater than t, then it will return
a positive value. Otherwise, it will return a negative value. For example, if s is "boy" and t is "girl", then
the function will return -5 which is the difference between the ASCII values of ‘b’ and ‘g’. If s is "car"
and t is "apple", then it will return 2 which is the difference between the ASCII values of ‘c’ and ‘a’. You
should not use any string functions from the standard C library in this function. The function prototype is
given as follows:

int compareStr(char *s, char *t);

Write a C program to test the function.

Some test input and output sessions are given below:
(1) Test Case 1:
Enter the first string:
boy
Enter the second string:
girl
compareStr(): -5

(2) Test Case 2:
Enter the first string:
car
Enter the second string:
apple
compareStr(): 2

(3) Test Case 3:
Enter the first string:
abc
Enter the second string:
abcD
compareStr(): -68
*/

#include <stdio.h>
int compareStr(char *s, char *t);
int main()
{
 char a[80],b[80];
 printf("Enter the first string: \n");
 gets(a);
 printf("Enter the second string: \n");
 gets(b);
 printf("compareStr(): %d\n", compareStr(a,b));
 return 0;
}
int compareStr(char *s, char *t)
{
 while(*s != '\0')
 {
     if(*s != *t)
        return *s - *t;

     ++s;
     ++t;
 }

 if(*s != *t)
    return *s - *t;

 return 0;
}
