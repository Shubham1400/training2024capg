#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void capital(char* s, int len)
{
    char st[len];// = (char*)malloc(len);
    
    if((int)s[0]>96 && (int)s[0]<123)
        st[0] = (char)(s[0]-32);
    else
        st[0] = (char)(s[0]);
    
    for(int i = 1; i<len; i++){
        if(s[i-1] == ' ')
        {
        char c = s[i];
        int a = c-32;
        //printf("-%c- ", a);
        st[i] = (char)a;   
        }
        else
        {//printf("%c ", s[i]);
            st[i] = s[i];
        }
    }
    //st[len-1] = s[len-1];
    st[len] = '\0';
    strcpy(s, st);
    //printf("__%s",st);
    //return st;
}

int main()
{
    char s[20];

    printf("Enter a string: ");
    gets(s);
    //getchar();
    //char *str = 
    capital(s, strlen(s));

    printf("\n:%s",s);
    //free(str);
    return EXIT_SUCCESS;
}
