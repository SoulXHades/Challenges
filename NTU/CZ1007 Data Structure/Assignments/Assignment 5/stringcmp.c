#include <stdio.h>
#define INIT_VALUE 999
int stringcmp(char *s1, char *s2);
int main()
{
    char source[80], target[80];
    int result = INIT_VALUE;
       printf("Enter a source string: \n");
       gets(source);
       printf("Enter a target string: \n");
       gets(target);
       result = stringcmp(source, target);
       if (result == 1)
        printf("stringcmp(): greater than");
       else if (result == 0)
        printf("stringcmp(): equal");
       else if (result == -1)
        printf("stringcmp(): less than");
       else
        printf("stringcmp(): error");
       return 0;
}
int stringcmp(char *s1, char *s2)
{
    while(1)
    {
        //check for termination of strings
        if(*s1 == '\0')
        {
            if(*s2 == '\0')
                return 0;
            else
                return -1;
        }
        else if(*s2 == '\0')
            return 1;

        if(*s1 > *s2)
            return 1;
        else if(*s1 < *s2)
            return -1;

        //move to next address
        ++s1;
        ++s2;
    }
}
