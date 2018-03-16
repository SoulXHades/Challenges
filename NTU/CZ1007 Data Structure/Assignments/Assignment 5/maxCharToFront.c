/*
Write a C function maxCharToFront() that accepts a character string str as parameter,
finds the largest character from the string, and moves it to the beginning of the string.
E.g., if the string is "aedcb", then the string will be "eadcb" after executing the function.
The string will be passed to the caller via call by reference.
If more than one largest character is in the string,
then the  first appearance of the largest character will be moved to the beginning of the string.
For example, if the string is "aedcbe", then the resultant string will be "eadcbe".
The function prototype is given as follows:

    void maxCharToFront(char *str)

Write a C program to test the function.

Some test input and output sessions are given below:

(1) Test Case 1:
Enter a string:
aedbc
maxCharToFront(): eadbc

(2) Test Case 2:
Enter a string:
agfcdeg
maxCharToFront(): gafcdeg

(3) Test Case 3:
Enter a string:
cba
maxCharToFront(): cba

(4) Test Case 4:
Enter a string:
ab
maxCharToFront(): ba
*/

#include <stdio.h>
void maxCharToFront(char *str);
int main()
{
    char str[80];
    printf("Enter a string: \n");
    gets(str);
    printf("maxCharToFront(): ");
    maxCharToFront(str);
    puts(str);
    return 0;
}
void maxCharToFront(char *str)
{
   int count=1, pos=0, temp;

   while(*(str+count) != '\0')
   {
       if(*(str+count) > *(str+pos))
        pos = count;

       ++count;
   }

   for(count=pos; count>0; count--)
   {
       temp = *(str+count);
       *(str+count) = *(str+count-1);
       *(str+count-1) = temp;
   }
}
