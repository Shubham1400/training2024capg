/*3. C program to check if a number is an automorphic number (a number whose square ends in the same digits as the 
number itself).
Example:
Consider the number 76.
1. Calculate the square of the number:
      76*76=5776
2. Determine the number of digits in the original number:
	Number of digits in 76 is 2.
3. Therefore extract the last 2 digits from the square: (mod of 10 to the power 2)
       5776 mod 100 = 76
4. Compare the extracted digits with the original number:
	Extracted digits: 76
	Original number: 76
Since the extracted digits (76) match the original number (76), 76 is an automorphic number.*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
    
    return EXIT_SUCCESS;
}
