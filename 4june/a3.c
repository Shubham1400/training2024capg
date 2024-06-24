/*Write a C program to replace first occurrence of a character with another character in a string.
Example
 
Input
 
Input string: I love programming.
Input character to replace: .
Input character to replace with: !
 
Output
 
String after replacing '.' with '!': I love programming!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m = 50

int main()
{
    char s[50], st[2], str[2];
    printf("enter String: ");
    gets(s);
    printf("enter character to replace: ");
    gets(st);
    printf("enter character to replace with: ");
    gets(str);
    //scanf("%c", &c);
    
    int index = strcspn(s, st);
    s[index] = str[0];      //str[0] is must instead os only str as str also contains null at the end.
    
    
    printf("%s", s);

    return EXIT_SUCCESS;
}
