/*
Write a C function longestStrInAr() that takes in an array of strings str and
size (>0) as paramters, and returns the longest string and also the length of the longest string via the
pointer parameter length. If two or more strings have the same longest string length, then the first
appeared string will be retruned to the calling function. For example, if size is 5 and the array of strings
is {"peter","john","mary","jane","kenny"}, then the longest string is "peter" and the
string length is 5 will be returned to the calling function. The function prototype is:

char *longestStrInAr(char str[N][40], int size, int *length);

Write a C program to test the function.

Some sample input and output sessions are given below:
(1) Test Case 1:
Enter array size:
4
Enter string 1:
Kenny
Enter string 2:
Mary
Enter string 3:
Peter
Enter string 4:
Sun
longest: Kenny
length: 5

(2) Test Case 2:
Enter array size:
2
Enter string 1:
Sun
Enter string 2:
Mary
longest: Mary
length: 4

*/

#include <stdio.h>
#include <string.h>
#define N 20
char *longestStrInAr(char str[N][40], int size, int *length);
int main()
{
 int i, size, length;
 char str[N][40], first[40], last[40], *p;
 char dummychar;

 printf("Enter array size: \n");
 scanf("%d", &size);
 scanf("%c", &dummychar);
 for (i=0; i<size; i++) {
 printf("Enter string %d: \n", i+1);
 gets(str[i]);
 }
 p = longestStrInAr(str, size, &length);
 printf("longest: %s \nlength: %d\n", p, length);
 return 0;
}
char *longestStrInAr(char str[N][40], int size, int *length)
{
 int len=0, i, j=0, longestname;

 *length = 0;

 for(i=0; i<size; i++)
 {
     j = 0;

     while(str[i][j] != '\0')
        ++j;

     if(j > *length)
     {
         *length = j;
         longestname = i;
     }
 }

 return str[longestname];
}
