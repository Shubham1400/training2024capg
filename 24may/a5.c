/*5. Remove the duplicate elements in the given array of intergers
 
i/p
1 2 3 4 2 5 1
 
o/p
 
1 2 3 4 5*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void sort(int* a){    //BUBBLE SORT
    for(int i = 0;i<5;i++){
        for(int j=i+1; j<5;j++){
            if(a[i]>a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main()
{
    
    int a[5] = {2,6,4,9,2};         //2 2 4 6 9
    sort(a);
    for(int i= 0;i<5;i++)
        printf("%d",a[i]);
    int size = 5, s=5;
    int i = 0, j = 1;
    while(i!=s){
        if(a[i] != a[j]){
            a[++i] = a[j];
            printf(" got %d,%d ",a[i],a[j]);
        }
        else{
            size--;
        }
        j++;
    }
    printf("---%d---",size);
    for(int i = 0; i<size; i++){
        printf("%d",a[i]);
    }
    return EXIT_SUCCESS;
}
