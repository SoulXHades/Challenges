/*
Write two versions of a C function that remove all the blank spaces in a sentence.
The first version sweepSpace1() will use array notation for processing the string,
while the other version sweepSpace2() will use pointer notation. The function prototypes are given below:

    char *sweepSpace1(char *sentence);
    char *sweepSpace2(char *sentence);

Write a C program to test the functions.

A sample input and output session is given below:

(1) Test Case 1:
Enter the string:
i am a boy
sweepSpace1(): iamaboy
sweepSpace2(): iamaboy

(2) Test Case 2:
Enter the string:
anybody
sweepSpace1(): anybody
sweepSpace2(): anybody
*/

#include <stdio.h>
char *sweepSpace1(char *sentence);
char *sweepSpace2(char *sentence);
int main()
{
   char str[80];

   printf("Enter the string: \n");
   gets(str);
   printf("sweepSpace1(): %s\n", sweepSpace1(str));
   printf("sweepSpace2(): %s\n", sweepSpace2(str));
   return 0;
}
char *sweepSpace1(char *sentence)
{
   int i, j, len;

   i=0; len=0;
   while (sentence[i]!='\0'){
      len++;
      i++;
   }
   j = 0;
   for (i=0; i < len; i++)
   {
      	if (sentence[i] != ' ')
      	{
           sentence[j] = sentence[i];
           j++;
        }
    }
    sentence[j] = '\0'; // add a null character
    return sentence;
}
char *sweepSpace2(char *sentence)
{
   int i, j, len;

   i=0; len=0;
   while (*(sentence+i)!='\0'){
      len++;
      i++;
   }
   j = 0;
   for (i=0; i < len; i++)
   {
      	if (*(sentence+i) != ' ')
      	{
           *(sentence+j) = *(sentence+i);
           j++;
        }
    }
    *(sentence+j) = '\0'; // add a null character
    return sentence;
}
