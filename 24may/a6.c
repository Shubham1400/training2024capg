#include <stdio.h>
//#include <math.h>

void sort(int* a){
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
    int a[5] = {2,6,4,9,2};
    sort(a);
    
    return 0;
}
