/*take 3 inputs one is sentence, 2nd is a character, 3rd is a substring with one word. you have to search the 
character in the string and set the position, is the char is not present set it to -1, do the same thing for 
substring also. display the sum of both the position.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define m 50                    // this is me
                                //me

int main()
{
    char s[m], c, st[m], str[2];
    printf("enter sentence: ");
    gets(s);
    printf("enter character: ");
    scanf("%c",&c);
    getchar();
    printf("enter word: ");
    gets(st);
    str[0] = c;
    int sum = strcspn(s,str);
    printf("\nsum: %d", sum);
    int index = 0, space = 0;
    char *token = strtok(s, " ");
    while(token != NULL)
    {
        if(strcmp(token, st) != 0)
        {
            index += (strlen(token));
            printf("\nlength %d", strlen(token));
            space++;
        }
        else
        {
            break;   
        }
        token = strtok(NULL, " ");
    }
    index = index + space;
    printf("result: %d", sum+index);

    return EXIT_SUCCESS;
}
