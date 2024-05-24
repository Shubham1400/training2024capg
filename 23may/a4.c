#include <stdio.h>
#include <math.h>
int main()
{
    int binary;
    scanf("%d", &binary);
    int decimal = 0;
    int p = 0; // p is used as 2^p
    while(binary != 0){
        int a = binary % 10;
        decimal = decimal + (a*(int)pow(2,p));
        p++;
        binary /= 10;
    }
    
    printf("decimal = %d\n",decimal);

    return 0;
}
