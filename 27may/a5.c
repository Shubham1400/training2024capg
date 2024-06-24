// 5. Write a program to reverse the order of words in a given string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char word[10][10], int count)
{
    printf("Reversed order - ");
    for(int i = count - 1; i > -1; i--){
        printf(" %s ", word[i]);
    }
    
}

int main()
{
    char sentence[100], word[10][10]; // 10 is no of words, 10 is the length of each word
    int count = 0;
    
    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    
    char *token = strtok(sentence, " ");
    while(token != NULL){
        strcpy(word[count++], token);
        token = strtok(NULL, " ");
    }

    reverse(word, count);

    return EXIT_SUCCESS;
}
