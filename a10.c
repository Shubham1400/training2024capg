#include <stdio.h>
int main()
{
    char c;
    printf("enter operator\n");
    scanf("%c", &c);
    float a,b;
    printf("enter numbers\n");
    scanf("%f%f",&a,&b);
    float result;
    
    switch(c){
        case '+': result = a+b; break;
        
        case '-': result = a-b; break;
        
        case '*': result = a*b; break;
        
        case '/': result = a/b; break;
        
        default: printf("invalid"); return 0;
    }
    
    printf("result = %f", result);
    return 0;
}
