#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d", &n);
    int sq_root = (int)sqrt(n);
    int lower_sq = sq_root*sq_root;
    int upper_sq = (sq_root+1)*(sq_root+1);
    
    int nearest = (abs(n-lower_sq) > abs(n-upper_sq)) ? upper_sq : lower_sq;
    
    printf("%d ",nearest);
    
    return 0;
}
