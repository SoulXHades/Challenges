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
