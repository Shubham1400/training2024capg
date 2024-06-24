/*1. You are given a string, str.
 
You need to find the score of str as per the following rules:
1) For each palindrome of length 4 in str, add 5 to the score
2) For each palindrome of length 5 in str, add 10 to the score
 
It is given that palindromes can overlap within str. However, the characters of the palindrome must be continuous and must NOT be circular (i.e. they must NOT wrap around the end of the string.
 
Output the final value of score.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define m 50

void substring(char* s, char* subs, int start, int len)
{
    for(int i=0; i<len; i++)
    {
        subs[i] = s[start + i];
    }
    subs[len] = '\0';
    printf(" subs func: %s\n", subs);
}

int main()
{
    char s[m], subs[6];
    int sum4 = 0, sum5 = 0;
    gets(s);
    
    for(int i=0; i<strlen(s); i++)
    {
        substring(s, subs, i, 4);
        int len = strlen(subs), count = 1;
        
        for(int j=0; j<strlen(subs)/2; j++)
        {
            if(strlen(subs) < 4 || subs[j] != subs[len-1-j])
            {
                printf("if %s| ", subs);
                count = 0;
                break;
            }
        }
        
        if(count == 1)
        {
            printf(" count increment\n");
            sum4 += 5;
        }
    }
    
    for(int i=0; i<strlen(s); i++)
    {
        substring(s, subs, i, 5);
        int len = strlen(subs), count = 1;
        
        for(int j=0; j<strlen(subs)/2; j++)
        {
            if(strlen(subs) < 5 || subs[j] != subs[len-1-j])
            {
                count = 0;
                break;
            }
        }
        
        if(count == 1)
        {
            sum5 += 10;
        }
    }
    
    printf("%d,%d", sum4-5, sum5-10);

    return EXIT_SUCCESS;
}
