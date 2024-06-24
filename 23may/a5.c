//5. program to find given number is Odd or Even
#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    
    if(num % 2 == 0)
        printf("%d is even",num);
    else
        printf("%d is odd",num);
    
    if((num & 1) == 0)
        printf("%d is even",num);
    else
        printf("%d is odd",num);

    return 0;
}
