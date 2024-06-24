/*4. Write a C program to determine whether a given positive integer is an Armstrong number. An Armstrong number 
(also known as a narcissistic number or pluperfect number) is a number that is equal to the sum of its own digits 
each raised to the power of the number of digits. Your program should:
 
i. Prompt the user to enter a positive integer.
ii. Determine the number of digits in the number.
iii. Calculate the sum of each digit raised to the power of the total number of digits.
iv Compare the calculated sum to the original number to determine if it is an Armstrong number.
v. Print "Armstrong number" if the number is an Armstrong number, otherwise print "Not an Armstrong number".*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
    return EXIT_SUCCESS;
}
