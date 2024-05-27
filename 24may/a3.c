#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d", &n);
    int no_of_digit = 0, n_copy = n;
    
    while(n!=0){
        int a = n%10;
        no_of_digit++;
        n /= 10;
    }
    int square = n_copy*n_copy;
    int digit_remainder_no = (int)pow(10,no_of_digit);
    if(n_copy==(square%digit_remainder_no))
        printf("%d is automorphic",n_copy);
    else 
        printf("%d is not automorphic",n_copy);
    return 0;
}
