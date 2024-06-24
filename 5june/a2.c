/*1st input is int n, if n is 3, take 3 lines of input, if 4, then 4. in each line, pair of h/m/s
you have to compare each line if the first time is earlier than the second, tell earlier, otherwise later*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define m 30

int main()
{
    
    char s[m], s1[15], s2[15];
    printf("enter: ");
    gets(s);
    
    char *token = strtok(s, " ");
    strcpy(s1,token);
    token = (NULL, " ");
    strcpy(s2,token);
    
    token = strtok(s1,"/");
    char *t = strtok(s2,"/");
    
    if(atoi(token)> atoi(t))
    {
        printf("later");
    }
    else if(atoi(token)< atoi(t))
    {
        printf("earlier");
    }
    else
    {
        token = strtok(NULL,"/");
        t = strtok(NULL,"/");
        if(atoi(token)> atoi(t))
        {
            printf("later");
        }
        else if(atoi(token)< atoi(t))
        {
            printf("earlier");
        }
        else
        {
            token = strtok(NULL,"/");
            t = strtok(NULL,"/");
            if(atoi(token)> atoi(t))
            {
                printf("later");
            }
            else if(atoi(token)< atoi(t))
            {
                printf("earlier");
            }
        }
    }

    return EXIT_SUCCESS;
}
