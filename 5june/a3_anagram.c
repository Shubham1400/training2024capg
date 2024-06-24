#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define m 30                // this is me is

bool anagram(char* s, char* st){
    int a[26] = {};
    
    for(int i = 0; s[i] != '\0'; i++){
        a[s[i]-97]++;
    }
    
    for(int i = 0; st[i] != '\0'; i++){
        a[st[i]-97]--;
    }
    
    for(int i = 0; i<26; i++){
        if(a[i] != 0)
            return false;
    }
    return true;
}

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
            if(strcmp(d2[i],to) == 0 || anagram(d2[i], to))
            {
                c++;
            }
            to = strtok(NULL, " ");
        }
        if(c<2)
            printf("\nans - %s", d2[i]);
    }
    return 0;
}
