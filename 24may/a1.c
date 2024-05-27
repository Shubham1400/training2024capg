#include <stdio.h>

int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d", &n);
    
    int sum = 0;
    
    while(n!=0){
        int a = n%10;
        sum += a;
        n =n/10;
    }

    printf("sum of digits = %d",sum);

    return 0;
}
