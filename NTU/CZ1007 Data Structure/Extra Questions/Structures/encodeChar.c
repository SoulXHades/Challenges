/*
Write a function encodeChar() that accepts two character strings s and t, and an array
of structures as parameters, encodes the characters in s to t, and passes the encoded string t to the caller
via call by reference. During the encoding process, each source character is converted into the
corresponding code character based on the following rules: 'a'→'d'; 'b'→'z'; 'z'→'a'; and
'd'→'b'. For other source characters, the code will be the same as the source. For example, if the
character string s is "abort", then the encoded string t will be "dzort". The structure Rule is
defined below:

typedef struct {
 char source;
 char code;
} Rule;

The function prototype is given below:

void encodeChar(Rule table[5], char *s, char *t);

Write a C program to test the function.

Some sample input and output sessions are given below:
(1) Test Case 1:
Source string:
abort
Encoded string: dzort

(2) Test Case 2:
Source string:
abort abort
Encoded string: dzort dzort

(3) Test Case 3:
Source string:
fgh
Encoded string: fgh
*/

#include <stdio.h>
typedef struct {
 char source;
 char code;
} Rule;
void encodeChar(Rule table[5], char *s, char *t);
int main()
{
 char s[80],t[80];
 Rule table[5] = {'a','d', 'b','z', 'z','a', 'd','b', '\0','\0' };

 printf("Source string: \n");
 gets(s);
 encodeChar(table,s,t);
 printf("Encoded string: %s\n", t);
 return 0;
}
void encodeChar(Rule table[5], char *s, char *t)
{
 int i;

 while(*s != '\0')
 {
     for(i=0; i<5; i++)
     {
         if(*s == table[i].source)
         {
             *t = table[i].code;
             ++t;
             ++s;
             break;
         }
     }

     *t = *s;
     ++t;
     ++s;
 }

 *t = '\0';
}
