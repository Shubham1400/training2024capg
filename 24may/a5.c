#include <stdio.h>
#include <math.h>

void sort(int* a){
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
    return 0;
}
