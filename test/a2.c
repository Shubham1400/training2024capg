#include <stdio.h>
#include <stdlib.h>    //01234567
#include <string.h>   // aaabcccd - bd

void adjuscent(char* s, int len)
{
    char st[len];
    int count = 0;
    for(int i = 0; i<len; i++)
    {
        char c = s[i];
        
        if(s[i-1] == c)
        {
           printf("  (%c)  ",c);
            c = s[i];
            st[--count] = '\0';
        }
        for(int j = i+1; j<len; j++)    //aabbcd
        {
            if(c == s[j])
            {
                continue;
            }
            else //if(s[j] != s[j+1])
            {
                printf("\nvalue entered in st at index %d is %c",count,s[j]);
                st[count++] = s[j];
                i = j;
                break;
            }//else
        }// j for
    }// i for
    st[count]='\0';
    printf("    %s", st);
}

int main()
{
    char s[20];

    printf("Enter a string: ");
    gets(s);
    //getchar();
    adjuscent(s, strlen(s));

    return EXIT_SUCCESS;
}
