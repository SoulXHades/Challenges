/*
Write a C function mergeStr() that merges two alphabetically ordered character strings a
and b into character string c according to alphabetical order. For example, if a is "agikmpq" and b is
"bcdefhjlnr", then the string c will be "abcdefghijklmnpqr". The string c will be passed to
the caller via call by reference. The function prototype is given as follows:

void mergeStr(char *a, char *b, char *c);

Write a C program to test the function.

Some test input and output sessions are given below:
(1) Test Case 1:
Enter the first string:
ace
Enter the second string:
bdg
mergeStr(): abcdeg

(2) Test Case 2:
Enter the first string:
agikmpq
Enter the second string:
bcdefhjlnr
mergeStr(): abcdefghijklmnpqr

(3) Test Case 3:
Enter the first string:
afkm
Enter the second string:
bbbggg
mergeStr(): abbbfgggkm
*/

#include <stdio.h>
#include <string.h>
void mergeStr(char *a, char *b, char *c);
int main()
{
 char a[80],b[80];
 char c[80];
 printf("Enter the first string: \n");
 gets(a);
 printf("Enter the second string: \n");
 gets(b);
 mergeStr(a,b,c);
 printf("mergeStr(): ");
 puts(c);
 return 0;
}
void mergeStr(char *a, char *b, char *c)
{
 int i=0;
 char temp;

 *c = '\0';
 strcat(c, a);
 strcat(c, b);

 while(c[i] != '\0')
 {
     if(c[i] > c[i+1] && c[i+1] != '\0')
     {
         temp = c[i];
         c[i] = c[i+1];
         c[i+1] = temp;

         i = 0;
         continue;
     }

     ++i;
 }
}
