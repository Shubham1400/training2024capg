/*Write a C program to remove from last occurrence of a word in given string
 
Input string: I am a programmer. I learn at Codeforwin.
Input word to remove: I
Output
 
String after removing last occurrence of 'I': 
I am a programmer.  learn at Codeforwin*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 50                  // hello

void reverse(char* s, int len)
{
    char t;
    int l = len - 1;
    
    for(int i=0; i<len/2; i++)
    {
        t = s[i];
        s[i] = s[l];
        s[l--] = t;
    }
}

void Remove(char* s, char* st, char* result)
{
    char *token = strtok(s, " ");
    int count = 0;
    
    printf("%s ", token);
    while(token != NULL)
    {
        if(strcmp(token, st) != 0 || count == 1)
        {
            printf("entered if %s\n", token);
            strcat(result, token);
            strcat(result, " ");
        }
        else if(strcmp(token, st) == 0 && count == 0)
        {
            printf("entered else if\n");
            count = 1;
        }
            //result[strcspn(result, " ")] = '\0';
            token = strtok(NULL, " ");
            printf("open %s ", token);
    }
}

int main()
{
    char s[m], st[10], result[m];
    printf("Enter sentence: \n");
    gets(s);
    printf("enter word to be removed: \n");
    gets(st);
    
    reverse(s, strlen(s));
    reverse(st, strlen(st));
    printf("%s\n",s);
    printf("%s\n",st);
    
    Remove(s, st, result);
    reverse(result, strlen(result));
    
    printf("result: %s", result);

    return EXIT_SUCCESS;
}
