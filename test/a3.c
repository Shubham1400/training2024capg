#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char s[5][10], int count)
{
    char t[10];// = (char*)malloc(50*sizeof(char))
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(strcmp(s[i],s[j]) <= 0)
            {
                strcpy(t, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], t);
            }
        }
    }
    
//    for(int i = 0; i < 5; i++){
//        printf("\n--%s ", s[i]);
//    }
}

int main()
{
    char sentence[100], word[5][10];// 5 is no of words 10 is length of each word
    int count = 0;
    
    gets(sentence);
    
    char *token = strtok(sentence,"|");
    while(token != NULL){
        strcpy(word[count++], token);
        token = strtok(NULL, "|");
    }
    
    for(int i = 0; i < 5; i++){
        printf("\n%s ", word[i]);
    }
    sort(word, count);
    
   for(int i = 0; i < 5; i++){
        printf("\n--%s ", word[i]);
    }

    return EXIT_SUCCESS;
}
