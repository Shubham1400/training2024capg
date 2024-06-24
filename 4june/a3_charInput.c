#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m = 50

int main()
{
    char s[50], st[2], str[2], c, ch;
    printf("enter String: ");
    gets(s);
    printf("enter character to replace: ");
    scanf("%c", &c); getchar();//gets(st);
    printf("enter character to replace with: ");
    scanf("%c", &ch);//gets(str);
    //scanf("%c", &c);
    st[0] = c; str[0] = ch;
    int index = strcspn(s, st);
    s[index] = str[0];      //str[0] is must instead os only str as str also contains null at the end.
    
    
    printf("%s", s);

    return 0;
}
