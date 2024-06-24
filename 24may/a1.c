/*1. Write a program that prompts the user for a positive integer and then computes the sum of all the digits of the 
number. For example, if the user enters 2784, then the program reports 21. If the user enters 59, then the program 
reports 14. The program should work for any number having one to ten digits.*/
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
