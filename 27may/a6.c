int main() {
    
    char s[] = "aabbdbbaa";
    int j = strlen(s) - 1, i = 0;
    for(; i<strlen(s)/2; i++)
    {
        //printf("palindrome");
        if(s[i] !=s[j--])
        break;    
    }
    if(i>=j)
        printf("palindrome");
    else
        printf("not palindrome");
    return 0;
}
