/*6. Given an array of positive integers. Your task is to find the leaders in the array. An element is leader if it 
is greater than all the elements to its right side. And the rightmost element is always a leader.
 
TESTCASE 1:
Input:
6
6 7 4 3 5 2
Output:
2 5 7
 
TESTCASE 2:
Input:
5
2 6 3 8 4
Output:
4 8*/

#include <stdio.h>
#include <stdlib.h>
#define M 10

void leader(int* a){
    int counter = 1;
    for(int i = 0;i<5;i++){
        for(int j=i+1; j<5;j++){
            if(a[i]>a[j])
                counter = 1;
            else{
                counter = 0;
                break;
            }
        }
        if(counter == 1)
            printf("%d ", a[i]);
    }
}

int main()
{
    int a[M];
    for(int i = 0; i<M; i++)
        scanf("%d", &a[i]);
    
    leader(a);
    
    return EXIT_SUCCESS;
}
