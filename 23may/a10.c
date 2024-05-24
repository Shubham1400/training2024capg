#include <stdio.h>
int main()
{
 /* char c;
    printf("enter operator\n");
    scanf("%c", &c);
    float a,b;
    printf("enter numbers\n");
    scanf("%f%f",&a,&b);
    float result;
*/
// above code works successfully too.
    char c;
    float a,b;
    printf("enter numbers\n");
    scanf("%f%f",&a,&b);
    while(getchar()!='\n');// used to clear the buffer
    printf("enter operator\n");
    scanf("%c", &c);
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
