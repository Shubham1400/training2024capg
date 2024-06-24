// 9. Write a program to sort an array of strings in lexicographic (dictionary) order.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char word[10][10], int count)
{
    char t[10];
    for(int i = 0; i < count - 1; i++)
    {
        for(int j = i + 1; j < count; j++)
        {
            if(strcmp(word[i], word[j]) > 0)
            {
                strcpy(t, word[i]);
                strcpy(word[i], word[j]);
                strcpy(word[j], t);
            }
        }
    }
    printf("sorted words - ");
    for(int i = 0; i < count; i++){
        printf(" %s ", word[i]);
    }
}

int main()
{
    char sentence[100], word[10][10]; // 5 is no of words, 10 is the length of each word
    int count = 0;
    
    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; // Remove the newline character at the end of the input
    
    char *token = strtok(sentence, " ");
    while(token != NULL){
        strcpy(word[count++], token);
        token = strtok(NULL, " ");
    }
    
   // for(int i = 0; i < count; i++){
     //   printf("\n%s ", word[i]);
    //}
    printf("\n");

    sort(word, count);

    return EXIT_SUCCESS;
}
