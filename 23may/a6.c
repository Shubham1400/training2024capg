//6. program to find largest of three numbers
#include <stdio.h>
int main()
{
    int num,num2,num3;
    scanf("%d", &num);
    scanf("%d", &num2);
    scanf("%d", &num3);
    int largest;
    
    if (num>num2 && num>num3)
        largest = num;
    else if (num2>num && num2>num3)
        largest = num2;
    else
        largest = num3;
    
    printf("%d is largest",largest);

    return 0;
}
