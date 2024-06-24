/*4. Find the Missing Number in an Array:
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, write a program to find the missing number.*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define M 50

int main() {
    int a[M], b[M], len, sum_a = 0, sum = 0;
    
    printf("Enter length: ");
    scanf("%d", &len);
    
    for(int i=0; i<len; i++)
    	scanf("%d", &a[i]);
    
    for(int i=0; i<=len; i++)// sum of all the elements that must be present
    	sum += i;

    for(int i=0; i<len; i++)// sum of elements in array
    	sum_a += a[i];

    printf("Element that is not present: %d", sum-sum_a);

    return EXIT_SUCCESS;
}
