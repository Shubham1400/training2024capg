#include <stdio.h>
#include<string.h>

int main()
{
    char s[] = "abbeerdjjskvv";
    int a[26] = {0};// initializes all elements of array as 0, a[26]={} also works the same
    int len = strlen(s);
    /*for(int i = 0; i<26;i++)
    {
        a[i] = 0;
    }*/
    for(int i = 0; i<len; i++)
    {
        a[((int)(s[i])) - 97]++;
    }
    int counter = 0;
    for(int i = 0; i<26;i++){
        if(a[i] > 0)
        {
           // printf("char %c",97+i);
            s[counter] = (char)(97+i);
            counter++;
        }
    }
    s[counter] = '\0';
    printf("%s",s);
    return 0;
}
