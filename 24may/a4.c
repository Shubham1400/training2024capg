#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d", &n);
    int no_of_digit = 0, n_copy = n, n_copy2 = n, arm = 0;
    
    while(n!=0){
        int a = n%10;
        no_of_digit++;
        n /= 10;
    }
    while(n_copy!=0){
        int a = n_copy%10;
        arm+=((int)pow(a,no_of_digit));
        n_copy/=10;
    }
    
    if(n_copy2 == arm)
        printf("%d is armstrong",n_copy2);
    else 
        printf("%d is not armstrong",n_copy2);
    return 0;
}
