#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define M 50

void removeConsecutive(char* str, int len)    //ibcjd - d
{
    char st[len],s[len];bool check = true;
    strcpy(s,str);
    while(check)
    {
        int count = 0, l = strlen(s);
        check = false;
        for(int i=0; i<l; i++)
        {   
            if((s[i]+1) != s[i+1])
            {
                st[count++] = s[i];
            }
            else
            {
                i++;
                check = true;
            }
        }
        st[count] = '\0';
        strcpy(s,st);
        //s[count] = '\0';
        printf("%s_", st);
        printf("(%s)", s);
        
    }
    printf("\noutside while\n");
    printf("%s()\n",st);
    printf("%s[]",s);
}

int main()
{
    char s[M];
    gets(s);
    
    removeConsecutive(s, strlen(s));

    return 0;
}
