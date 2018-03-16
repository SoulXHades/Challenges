/*
Cipher text is a popular encryption technique. What we do in cipher text is that we can
encrypt each apha (English) character with +1. For example, "Hello" can be encrypted with +1 Cipher
to "Ifmmp". If a character is 'z' or 'Z', the corresponding encrypted character will be 'a' or 'A'
respectively. We use call by reference in the implementation. Write the C functions cipher() and
decipher() with the following function prototypes:

void cipher(char *s);
void decipher(char *s);

Write a C program to test the cipher() and decipher() functions.

Some sample input and output sessions are given below:
(1) Test Case 1:
Enter the string:
123a
To cipher: 123a -> 123b
To decipher: 123b -> 123a

(2) Test Case 2:
Enter the string:
abcxyz
To cipher: abcxyz -> bcdyza
To decipher: bcdyza -> abcxyz

(3) Test Case 3:
Enter the string:
HELLO Hello
To cipher: HELLO Hello -> IFMMP Ifmmp
To decipher: IFMMP Ifmmp -> HELLO Hello

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void cipher(char *s);
void decipher(char *s);
int main()
{
 char str[80];

 printf("Enter the string: \n");
 gets(str);
 printf("To cipher: %s -> ", str);
 cipher(str);
 printf("%s\n", str);
 printf("To decipher: %s -> ", str);
 decipher(str);
 printf("%s\n", str);
 return 0;
}
void cipher(char *s)
{
 int i=0;

 while(s[i] != '\0')
 {
     if(!isdigit(s[i]) && s[i] != ' ')
     {
         if(s[i] != 'Z' && s[i] != 'z')
            ++s[i];
         else
            s[i] -= 25;
     }

     ++i;
 }
}
void decipher(char *s)
{
 int i=0;

 while(s[i] != '\0')
 {
     if(!isdigit(s[i]) && s[i] != ' ')
     {
         if(s[i] != 'A' && s[i] != 'a')
            --s[i];
         else
            s[i] += 25;
     }

     ++i;
 }
}
