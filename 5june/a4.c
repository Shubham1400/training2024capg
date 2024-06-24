/*find no of ways in which a string can be partition into two no empty substring such that no of consonants
in the first part is greater than no of consonants in the second part. assume lowercase.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define m 50

int main()
{
    char s[m];
    int sum = 0, brk = 1, count = 0;
    printf("enter: ");
    gets(s);           // hopper
    
    for(int i=0; i<strlen(s); i++)
    {
        if(!(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'))
        {
            sum++;
        }
    }
    
    for(int i=0; i<strlen(s); i++)
    {
        int c = 0;
        for(int j=0; j<brk-1; j++)
        {
            if(!(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'))
            {
                //printf(" .%c. ",s[i]);
                c++;
            }
        }
        if(c > (sum - c)){ //printf("(%d)%c,%d | ", brk,s[brk],(sum - c));
            count++;
        }
        
        brk++;
    }
    printf
    ("\n ans- %d", count);
    return EXIT_SUCCESS;
}
