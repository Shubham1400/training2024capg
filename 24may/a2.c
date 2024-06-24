/*2. Write a program that prompts the user for a positive integer and then reports the closest integer having a whole
number square root. For example, if the user enters 8, then the program reports 9. If the user enters 18, then the 
program reports 16.The program should work  for any number having one to seven digits.*/
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
