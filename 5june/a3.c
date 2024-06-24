//input sequence of space separated words and find the unique words.
//also consider anagram as duplicate too.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define m 30                // this is me is

int main()
{
    char s[m], st[m], d2[10][10], str[m];
    int count = 0;
    gets(s);
    strcpy(str,s);
    char *t = strtok(s, " ");
    
    while(t != NULL)
    {
        strcpy(d2[count++],t);
        t = strtok(NULL, " ");
    }
        
    for(int i=0; i<count; i++)
    {
        int c = 0;
        strcpy(st, str);
        char *to = strtok(st, " ");
        while(to!=NULL)
        {
            if(strcmp(d2[i],to) == 0)
            {
                c++;
            }
            to = strtok(NULL, " ");
        }
        if(c<2)
            printf("\nans - %s", d2[i]);
    }
    return EXIT_SUCCESS;
}
