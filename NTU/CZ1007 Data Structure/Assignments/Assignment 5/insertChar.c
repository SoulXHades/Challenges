/*
Write the C function insertChar() that takes in a string str1 as an argument,
copies the contents of character string str1 into character string str2. In addition, the function
also has a character parameter ch. For every three characters copied from str1 to str2, the
character ch is inserted into str2. The function returns the resultant string to the calling
function via call by reference. For example, if the string str1 is "abcdefg", and the inserted
character ch is ‘#’, then the resultant string str2 = "abc#def#g" will be returned to the
calling function. The function prototype is:

void insertChar(char *str1, char *str2);

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter a string:
abc de
Enter a character to be inserted:
#
insertChar(): abc# de#

(2) Test Case 2:
Enter a string:
abc
Enter a character to be inserted:
#
insertChar(): abc#

(3) Test Case 3:
Enter a string:
I am a boy.
Enter a character to be inserted:
$
insertChar(): I a$m a$ bo$y.

(4) Test Case 4:
Enter a string:
hi
Enter a character to be inserted:
$
insertChar(): hi
*/

#include <stdio.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
 char a[80],b[80];
 char ch;

 printf("Enter a string: \n");
 gets(a);
 printf("Enter a character to be inserted: \n");
 ch = getchar();
 insertChar(a,b,ch);
 printf("insertChar(): ");
 puts(b);
 return 0;
}
void insertChar(char *str1, char *str2, char ch)
{
 int count=1;

 while(*str1 != '\0')
 {
     *str2++ = *str1++;
     ++count;

     if(count == 4)
     {
         *str2++ = ch;
         count = 1;
     }
 }

 *str2 = '\0';
}
