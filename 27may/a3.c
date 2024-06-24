#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool findAnagram(char* s, char* st){
    int a[26] = {};
    
    for(int i = 0; s[i] != '\0'; i++){
        a[s[i]-97]++;
    }
    
    for(int i = 0; st[i] != '\0'; i++){
        a[st[i]-97]--;
    }
    
    for(int i = 0; i<26; i++){
        if(a[i] != 0)
            return false;
    }
    return true;
}

int main() {
    char s[] = "area";
    char st[] = "reaa";

    bool r = findAnagram(s, st);
    
    if(r)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
