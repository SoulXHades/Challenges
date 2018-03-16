#include <stdio.h>
int longWordLength(char *s);
int main()
{
    char str[80];
    printf("Enter a string: \n");
    gets(str);
    printf("longWordLength(): %d\n", longWordLength(str));
    return 0;
}
int longWordLength(char *s)
{
   int count=1, max=1;

   while(*s != '\0')
   {
       if((*s > 64) && (*s < 91) || (*s > 96) && (*s < 123))
        ++count;
       else
        count = 1;

       if(count > max)
        max = count;

       ++s;
   }

   //cause WHILE LOOP ends at '\0' so need to -1
   return max-1;
}
